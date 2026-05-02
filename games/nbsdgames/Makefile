PORTNAME=	nbsdgames
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.1
CATEGORIES=	games

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	21 text-based modern games
WWW=		https://github.com/abakh/nbsdgames

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	abakh

INSTALL_TARGET=	install scorefiles manpages
MAKE_ARGS+=	GAMES_DIR=${PREFIX}/bin \
		MAN_DIR=${PREFIX}/share/man/man6 \
		SCORES_DIR=/var/games/nbsdgames
CFLAGS+=	--std=c99 -I${NCURSESINC} -I${NCURSESBASE}/include

_GAMES=	battleship \
	checkers \
	darrt \
	fifteen \
	fisher \
	jewels \
	memoblocks \
	miketron \
	mines \
	muncher \
	nbsdgames \
	pipes \
	rabbithole \
	redsquare \
	revenge \
	reversi \
	scissor \
	sjump \
	snakeduel \
	sos \
	sudoku \
	trsr \
	tugow

post-install:
	${INSTALL_DATA} ${WRKSRC}/nbsdgames.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/
	${INSTALL_DATA} ${WRKSRC}/nbsdgames.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/
.for game in ${_GAMES}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${game}
.endfor

.include <bsd.port.mk>
