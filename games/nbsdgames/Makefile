PORTNAME=	nbsdgames
DISTVERSIONPREFIX=	v
DISTVERSION=	5
CATEGORIES=	games

MAINTAINER=	fuz@fuz.su
COMMENT=	17 text-based modern games

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	abakh

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
	reversi \
	snakeduel \
	sos \
	sudoku \
	tugow

post-install:
	${INSTALL_DATA} ${WRKSRC}/nbsdgames.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/
	${INSTALL_DATA} ${WRKSRC}/nbsdgames.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/
.for game in ${_GAMES}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${game}
.endfor

.include <bsd.port.mk>
