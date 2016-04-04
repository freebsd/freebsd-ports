# $FreeBSD$

PORTNAME=	chessx
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Qt 4 chess database application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		desktop-file-utils qmake shared-mime-info tar:tgz
USE_QT4=	corelib gui svg network linguisttools_build \
		moc_build qmake_build rcc_build uic_build
QMAKE_ARGS+=	QMAKE_LRELEASE=${LRELEASE}

PLIST_FILES=	bin/chessx \
		share/applications/chessx.desktop \
		share/pixmaps/chessx.png

OPTIONS_DEFINE=	STOCKFISH CRAFTY

STOCKFISH_DESC=	Install Stockfish Chess Engine
STOCKFISH_RUN_DEPENDS=	stockfish:games/stockfish

CRAFTY_DESC=	Install Crafty Chess Application
CRAFTY_RUN_DEPENDS=	crafty:games/crafty

.include <bsd.port.mk>
