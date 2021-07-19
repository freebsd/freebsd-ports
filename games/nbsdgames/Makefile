PORTNAME=	nbsdgames
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.2
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
	pipes \
	rabbithole \
	redsquare \
	reversi \
	snakeduel \
	sos \
	sudoku \

post-install:
.for game in ${_GAMES}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${game}
.endfor

.include <bsd.port.mk>
