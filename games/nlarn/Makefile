# Created by: Martin Tournoij <martin@arp242.net>
# $FreeBSD$

PORTNAME=	nlarn
DISTVERSIONPREFIX=	NLarn-
DISTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Roguelike game and as such a remake of the classic game Larn

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake gnome lua:53 ncurses pkgconfig
USE_GITHUB=	yes
USE_GNOME=	glib20 introspection:build

post-configure:
	${REINPLACE_CMD} 's|/usr/share/nlarn|${DATADIR}|' \
		${WRKSRC}/src/game.c

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/nlarn ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/nlarn.ini-sample ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
