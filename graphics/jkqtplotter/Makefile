PORTNAME=	jkqtplotter
DISTVERSION=	5.0.0 # not tagged yet, see https://github.com/jkriege2/JKQtPlotter/issues/155
CATEGORIES=	graphics
PKGNAMESUFFIX?=	-${FLAVOR}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt plotter framework
WWW=		https://github.com/jkriege2/JKQtPlotter \
		https://jkriege2.github.io/JKQtPlotter/index.html

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	qt6 qt5
FLAVOR?=	qt6

USES=		cmake gl qt:${FLAVOR:S/qt//}
_USE_QT_qt5=	core gui opengl printsupport svg xml widgets qmake:build buildtools:build
_USE_QT_qt6=	base svg tools:build
USE_QT=		${_USE_QT_${FLAVOR}}
USE_GL=		gl opengl

USE_GITHUB=	yes
GH_ACCOUNT=	jkriege2
GH_TAGNAME=	d243218

WRKSRC=		${WRKDIR}/JKQtPlotter-${GH_TAGNAME}

CMAKE_ARGS=	-DQT_VERSION=${FLAVOR:S/qt//}
CMAKE_OFF=	JKQtPlotter_BUILD_TESTS \
		JKQtPlotter_BUILD_EXAMPLES

DOCSDIR=	${PREFIX}/share/doc/JKQTPlotter

PLIST=		${.CURDIR}/pkg-plist.${FLAVOR}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)|find_package(QT NAMES Qt${FLAVOR:S/qt//} COMPONENTS Core REQUIRED)|g' \
		${WRKSRC}/cmake/jkqtplotter_common_qtsettings.cmake

.include <bsd.port.mk>
