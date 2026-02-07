PORTNAME=	sokoban
DISTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/strategy:src \
		http://www.cs.cornell.edu/andru/release/:x
DISTFILES=	${PORTNAME}-src.tar.gz:src xsokoban-3.3c.tar.gz:x

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Logical game: problems with packets in cave

USES=		ncurses
ALL_TARGET=
WRKSRC=		${WRKDIR}/sokoban

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sokoban ${STAGEDIR}${PREFIX}/bin/sokoban
	@${MKDIR} ${STAGEDIR}${DATADIR}/screens
	${INSTALL_DATA} ${WRKSRC}/screens/sokoban.help \
		${WRKDIR}/xsokoban/screens/* ${STAGEDIR}${DATADIR}/screens
	@${MKDIR} ${STAGEDIR}/var/games/sokoban
	truncate -s 512 ${STAGEDIR}/var/games/sokoban/scores.sample

.include <bsd.port.mk>
