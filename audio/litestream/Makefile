# ports collection makefile for:   litestream
# Date created:	       Sat Nov 4 2000
# Whom:		       aaron@mutex.org
#
# $FreeBSD$
#

PORTNAME=	litestream
PORTVERSION=	1.0.1r3
CATEGORIES=	audio
MASTER_SITES=	http://www.litestream.net/releases/
DISTNAME=	${PORTNAME}-1.0b1r3

MAINTAINER=	aaron@mutex.org

USE_GMAKE=	yes

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/litestream
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/litestream
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/litestream
	${INSTALL_DATA} ${WRKSRC}/ABOUT ${PREFIX}/share/doc/litestream
	${INSTALL_DATA} ${WRKSRC}/MAKEITGO ${PREFIX}/share/doc/litestream
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/litestream ${PREFIX}/bin/litestream
	${INSTALL_PROGRAM} ${WRKSRC}/literestream ${PREFIX}/bin/literestream
	${INSTALL_PROGRAM} ${WRKSRC}/source ${PREFIX}/bin/source

.include <bsd.port.mk>
