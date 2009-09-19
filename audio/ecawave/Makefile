# New ports collection makefile for:   ecawave
# Date created:                24 aug 2001
# Whom:                        The Anarcat <anarcat@anarcat.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	ecawave
PORTVERSION=	0.6.1
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://ecasound.seul.org/download/

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Simple graphical audio file editor

BUILD_DEPENDS=	${LOCALBASE}/lib/libecasound.a:${PORTSDIR}/audio/ecasound

USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CFLAGS+=	${PTHREAD_CFLAGS:S/"//g}
LDFLAGS+=	${PTHREAD_LIBS:S/"//g}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${LDFLAGS}" \

MAN1=		ecawave.1
PLIST_FILES=	bin/ecawave
PORTDOCS=	*.html

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Configure fails on alpha 5.x
.endif

post-patch:
	${REINPLACE_CMD} -e "s,lqt,lqt-mt," ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/Documentation/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
