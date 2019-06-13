# $FreeBSD$

PORTNAME=	chessx
PORTVERSION=	1.4.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt 5 chess database application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang desktop-file-utils qmake:outsource qt:5 \
		shared-mime-info tar:tgz
USE_QT=		buildtools_build concurrent core gui linguisttools_build multimedia \
		network opengl printsupport svg widgets xml

PLIST_FILES=	bin/chessx \
		share/applications/chessx.desktop \
		share/pixmaps/chessx.png

OPTIONS_DEFINE=	STOCKFISH CRAFTY

CRAFTY_DESC=	Install Crafty Chess Application
CRAFTY_RUN_DEPENDS=	crafty:games/crafty

STOCKFISH_DESC=	Install Stockfish Chess Engine
STOCKFISH_RUN_DEPENDS=	stockfish:games/stockfish

.include <bsd.port.mk>
