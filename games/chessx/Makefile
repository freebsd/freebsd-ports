# $FreeBSD$

PORTNAME=	chessx
DISTVERSION=	1-1-0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Qt 4 chess database application

LICENSE=	GPLv2 # (or later)

USES=		desktop-file-utils shared-mime-info qmake
USE_QT4=	corelib gui svg xml network linguist_build \
		moc_build qmake_build rcc_build uic_build
QMAKE_ARGS+=	QMAKE_LRELEASE=${LRELEASE}

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	STOCKFISH CRAFTY

STOCKFISH_DESC=	Install Stockfish Chess Engine
STOCKFISH_RUN_DEPENDS=	stockfish:${PORTSDIR}/games/stockfish

CRAFTY_DESC=	Install Crafty Chess Application
CRAFTY_RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty

.include <bsd.port.mk>
