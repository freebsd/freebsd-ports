# New ports collection makefile for:   ecawave
# Date created:                24 aug 2001
# Whom:                        The Anarcat <anarcat@anarcat.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	ecawave
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://ecasound.seul.org/download/

MAINTAINER=	anarcat@anarcat.ath.cx
COMMENT=	Simple graphical audio file editor

BUILD_DEPENDS=	${LOCALBASE}/lib/libecasound.a:${PORTSDIR}/audio/ecasound

GNU_CONFIGURE=	yes
USE_QT_VER=	3
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
USE_REINPLACE=	yes

CFLAGS+=	${PTHREAD_CFLAGS:S/"//g}
LDFLAGS+=	${PTHREAD_LIBS:S/"//g}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${LDFLAGS}" \
		CFLAGS="-I${LOCALBASE}/include ${CFLAGS}" \
		CXXFLAGS="-I${LOCALBASE}/include ${CXXFLAGS}"

MAN1=		ecawave.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} >= 502102
BROKEN=		"Configure fails on alpha 5.x"
.endif

post-patch:
	${REINPLACE_CMD} -e "s,lqt,lqt-mt," ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/Documentation/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
