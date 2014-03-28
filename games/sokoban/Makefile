# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=		sokoban
PORTVERSION=		1.0
PORTREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
DISTNAME=		${PORTNAME}-src

MAINTAINER=		lifanov@mail.lifanov.com
COMMENT=		Logical game: problems with packets in cave

WRKSRC=			${WRKDIR}/sokoban
ALL_TARGET=

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sokoban ${STAGEDIR}${PREFIX}/bin/sokoban
	@${MKDIR} ${STAGEDIR}${DATADIR}/screens
	@${INSTALL_DATA} ${WRKSRC}/screens/* ${STAGEDIR}${DATADIR}/screens

.include <bsd.port.mk>
