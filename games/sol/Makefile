# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	sol
PORTVERSION=	1.0.8
CATEGORIES=	games
MASTER_SITES=	http://shh.thathost.com/pub-unix/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Solitaire card game for X Window System

LICENSE=	ART10

LIB_DEPENDS=	libXaw.so:x11-toolkits/libXaw \
		libshhcards.so:games/libshhcards \
		libshhmsg.so:devel/libshhmsg \
		libshhopt.so:devel/libshhopt \
		libxalloc.so:devel/libxalloc

CONFLICTS=	gnome-games-*

USES=		gmake
USE_XORG=	ice sm x11 xext xmu xpm xt

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
