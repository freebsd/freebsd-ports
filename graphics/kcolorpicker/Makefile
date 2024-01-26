PORTNAME=	kColorPicker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	graphics kde
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt-based color picker library with popup menu
WWW=		https://github.com/ksnip/kColorPicker

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	qt5 qt6
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake compiler:c++17-lang gl qt:${FLAVOR:S/qt//}
USE_GITHUB=	yes
GH_ACCOUNT=	ksnip
_USE_GL_qt5=	# empty
_USE_GL_qt6=	opengl
USE_GL=		${_USE_GL_${FLAVOR}}
_USE_QT_qt5=	core gui widgets \
		buildtools:build qmake:build testlib:build
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}

CMAKE_ON=	BUILD_SHARED_LIBS BUILD_WITH_QT${FLAVOR:S/qt//}

PLIST_SUB=	QT_VER=${FLAVOR:S/qt//} \
		SHLIB_VER=${DISTVERSION} \
		SHLIB_VER_MAJ=${DISTVERSION:R:R}

.include <bsd.port.mk>
