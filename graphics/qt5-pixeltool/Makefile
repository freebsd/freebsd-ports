PORTNAME=	pixeltool
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 screen magnifier

USES=		compiler:c++11-lang qmake qt-dist:5,tools
USE_QT=		core gui widgets buildtools_build

# qt5logo.png is installed by qt5-widgets.
DESKTOP_ENTRIES="Qt 5 PixelTool" "" \
		"${PREFIX}/share/pixmaps/qt5logo.png" \
		"${PREFIX}/${QT_BINDIR_REL}/pixeltool" \
		"Graphics;Qt;" true

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

QT_BINARIES=	yes

.include <bsd.port.mk>
