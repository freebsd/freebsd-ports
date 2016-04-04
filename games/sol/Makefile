# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	sol
PORTVERSION=	1.0.7
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://shh.thathost.com/pub-unix/files/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Solitaire card game for X Window System

LIB_DEPENDS=	libshhopt.so.1:devel/libshhopt \
		libshhmsg.so.1:devel/libshhmsg \
		libxalloc.so.1:devel/libxalloc \
		libshhcards.so.1:games/libshhcards

CONFLICTS=	gnome-games-*

USES=		gmake
USE_XORG=	xpm x11 xaw

OPTIONS_DEFINE=	DOCS

pre-build:
	(cd ${WRKSRC} && ${MAKE_CMD} readme.var)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sol ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sol.6 ${STAGEDIR}${PREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/sol
	${INSTALL_DATA} ${WRKSRC}/sol.score ${STAGEDIR}${PREFIX}/share/sol
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/sol
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${STAGEDIR}${PREFIX}/share/doc/sol
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/doc/sol

.include <bsd.port.mk>
