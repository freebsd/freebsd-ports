PORTNAME=	colorcode
DISTVERSION=	0.8.7
CATEGORIES=	games
MASTER_SITES=	http://colorcode.laebisch.com/download/
DISTNAME=	ColorCode-${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Advanced MasterMind game and solver
WWW=		http://colorcode.laebisch.com/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl qmake qt:5
USE_GL=		gl
USE_QT=		core gui widgets buildtools:build linguisttools:build

QMAKE_SOURCE_PATH=	${WRKSRC}/src

DESKTOP_ENTRIES=	ColorCode \
			"" \
			colorcode \
			colorcode \
			"LogicGame;Game;Qt;" \
			true

PLIST_FILES=	bin/colorcode \
		share/pixmaps/colorcode.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/colorcode ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA}	${WRKSRC}/src/img/cc64.png	${STAGEDIR}${PREFIX}/share/pixmaps/colorcode.png

.include <bsd.port.mk>
