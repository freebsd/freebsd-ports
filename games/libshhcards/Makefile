# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	libshhcards
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://shh.thathost.com/pub-unix/files/
DISTNAME=	shhcards-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for displaying game cards on X Window System

USE_XORG=	xpm
MAKEFILE=	${FILESDIR}/Makefile.lib
USE_LDCONFIG=	yes
MAKE_ENV=	WITHOUT_PROFILE=yes __MAKE_CONF=/dev/null SRCCONF=/dev/null

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_LIB} ${WRKSRC}/libshhcards.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libshhcards.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libshhcards.so.1 ${STAGEDIR}${PREFIX}/lib
	${INSTALL} ${WRKSRC}/shhcards.h ${STAGEDIR}${PREFIX}/include
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
