# New ports collection makefile for:   ecawave
# Date created:                24 aug 2001
# Whom:                        The Anarcat <anarcat@anarcat.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	ecawave
PORTVERSION=	0.4.1
CATEGORIES=	audio
MASTER_SITES=	http://ecasound.seul.org/download/

MAINTAINER=	anarcat@anarcat.dyndns.org

LIB_DEPENDS=	ecasound.7:${PORTSDIR}/audio/ecasound

GNU_CONFIGURE=	yes
USE_QT_VER=	2
USE_X_PREFIX=	yes

CFLAGS+=	${PTHREAD_CFLAGS:S/"//g}
LDFLAGS+=	${PTHREAD_LIBS:S/"//g}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lqt2 ${LDFLAGS}" \
		CFLAGS="-I${LOCALBASE}/include ${CFLAGS}" \
		CXXFLAGS="-I${LOCALBASE}/include ${CXXFLAGS}"

MAN1=		ecawave.1

post-patch:
	@${PERL} -pi -e 's,-lqt,-lqt2,g' ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/Documentation/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
