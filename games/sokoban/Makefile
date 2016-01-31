# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=		sokoban
PORTVERSION=		1.0
PORTREVISION=		2
CATEGORIES=		games
MASTER_SITES=		SUNSITE/games/strategy
DISTNAME=		${PORTNAME}-src

MAINTAINER=		lifanov@mail.lifanov.com
COMMENT=		Logical game: problems with packets in cave

USES=			ncurses
WRKSRC=			${WRKDIR}/sokoban
ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sokoban ${STAGEDIR}${PREFIX}/bin/sokoban
	@${MKDIR} ${STAGEDIR}${DATADIR}/screens
	${INSTALL_DATA} ${WRKSRC}/screens/* ${STAGEDIR}${DATADIR}/screens

post-install:
	@${MKDIR} ${STAGEDIR}/var/games/sokoban
	truncate -s 512 ${STAGEDIR}/var/games/sokoban/scores.sample

.include <bsd.port.mk>
