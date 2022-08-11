PORTNAME=	nlarn
DISTVERSIONPREFIX=	NLarn-
DISTVERSION=	0.7.6
CATEGORIES=	games

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Roguelike game and as such a remake of the classic game Larn

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake gnome localbase lua:53 ncurses:port pkgconfig
USE_GITHUB=	yes
USE_GNOME=	glib20 introspection:build

post-configure:
	${REINPLACE_CMD} 's|/usr/share/nlarn|${DATADIR}|' \
		${WRKSRC}/src/nlarn.c

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/nlarn ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
