PORTNAME=	kImageAnnotator
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	graphics kde
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for image-annotation tools
WWW=		https://github.com/ksnip/kImageAnnotator

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=		qt5 qt6
FLAVOR?=		${FLAVORS:[1]}
qt5_LIB_DEPENDS=	libkColorPicker-Qt5.so:graphics/kcolorpicker@qt5
qt6_LIB_DEPENDS=	libkColorPicker-Qt6.so:graphics/kcolorpicker@qt6

USES=		cmake localbase compiler:c++17-lang gl qt:${FLAVOR:S/qt//} xorg
USE_GITHUB=	yes
GH_ACCOUNT=	ksnip
_USE_GL_qt5=	# empty
_USE_GL_qt6=	opengl
USE_GL=		${_USE_GL_${FLAVOR}}
_USE_QT_qt5=	core gui svg widgets \
		buildtools:build linguisttools:build qmake:build
_USE_QT_qt6=	base svg \
		tools:build
USE_QT=		${_USE_QT_${FLAVOR}}
USE_XORG=	x11

CMAKE_ON=	BUILD_SHARED_LIBS BUILD_WITH_${FLAVOR:tu}
CMAKE_OFF=	BUILD_EXAMPLE

_QT5_ONLY_qt5=	#
_QT5_ONLY_qt6=	"@comment "

PLIST_SUB=	QT5_ONLY=${_QT5_ONLY_${FLAVOR}} \
		QT_VER=${FLAVOR:S/qt//} \
		SHLIB_VER=${DISTVERSION} \
		SHLIB_VER_MAJ=${DISTVERSION:R:R}

.include <bsd.port.mk>
