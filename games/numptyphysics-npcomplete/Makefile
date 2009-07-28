# New ports collection makefile for:	numptyphysics-npcomplete
# Date created:		04 Jan 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	npcomplete
PORTVERSION=	0.0.r20090116
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	numptyphysics-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Level pack for Numpty Physics

RUN_DEPENDS=	numptyphysics:${PORTSDIR}/games/numptyphysics

USE_BZIP2=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/npcomplete
DATADIR=	${PREFIX}/share/numptyphysics

post-extract:
# this level will crash the game
	@${RM} -f "${WRKSRC}/L02_bridge Gaps tut.nph"

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.nph ${DATADIR}

.include <bsd.port.mk>
