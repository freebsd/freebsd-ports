# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	npcomplete
PORTVERSION=	0.0.r20090116
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	numptyphysics-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Level pack for Numpty Physics

RUN_DEPENDS=	numptyphysics:games/numptyphysics

USES=		tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/npcomplete
DATADIR=	${PREFIX}/share/numptyphysics

post-extract:
# this level will crash the game
	@${RM} "${WRKSRC}/L02_bridge Gaps tut.nph"

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.nph ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
