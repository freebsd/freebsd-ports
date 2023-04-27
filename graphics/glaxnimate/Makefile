PORTNAME=	glaxnimate
DISTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple vector animation program
WWW=		https://glaxnimate.mattbas.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	pip:devel/py-pip@${PY_FLAVOR}
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libpotrace.so:graphics/libpotrace

USES=		cmake compiler:c++17-lang desktop-file-utils gl libarchive python qt:5
USE_QT=		concurrent core gui network svg xml widgets buildtools:build linguisttools:build qmake:build uitools:build
USE_GL=		gl

USE_GITLAB=	yes
GL_ACCOUNT=	mattbas
GL_COMMIT=	91219dc52ca909118e4a756629ea779dde5577c3

GL_TUPLE=	mattbas:CMake-Lib:8af80b5668dbc6a0210e09a969a1b43fc99f39ba:mattbas_CMake_Lib/cmake \
		mattbas:Qt-Color-Widgets:091c29463bbeec1a672598af4597055ba24842cd:mattbas_Qt_Color_Widgets/external/Qt-Color-Widgets \
		mattbas:Qt-History-LineEdit:5b761f436e8b31491e06b26460d28a2eaef0babc:mattbas_Qt_History_LineEdit/external/Qt-History-LineEdit \
		mattbas:python-lottie:9e742aadb5ca7d0e8c9b01b2553c0a81de238ae4:mattbas_python_lottie/data/lib/python-lottie

USE_GITHUB=	nodefault
GH_TUPLE=	KDE:breeze-icons:1a13b09adc7ebe0c4b5be6cc1add3869f3de8a1a:KDE_breeze_icons/data/icons/breeze-icons \
		mbasaglia:pybind11:7b30131fcbbbc227d2afcc969a8aab8c8b792b66:mbasaglia_pybind11/external/QtAppSetup/external/pybind11 \
		rpavlik/cmake-modules:c97690cc0024a1842cd8de71334a2ee9c5f7e729:rpavlik_cmake_modules/external/cmake-modules

CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}

ALL_TARGET=	all translations

.include <bsd.port.mk>
