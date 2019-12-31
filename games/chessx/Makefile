# $FreeBSD$

PORTNAME=	chessx
PORTVERSION=	1.5.0
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	Qt 5 chess database application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang desktop-file-utils qmake qt:5 tar:tgz gl
USE_GL=	gl
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

post-configure:
	( cd ${BUILD_WRKSRC} && ${LRELEASE} ${WRKSRC}/${PORTNAME}.pro )

.include <bsd.port.mk>
