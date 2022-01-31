PORTNAME=	glaxnimate
DISTVERSION=	0.5.0
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple vector animation program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	pip:devel/py-pip@${PY_FLAVOR}
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libpotrace.so:graphics/libpotrace

USES=		cmake compiler:c++17-lang gl libarchive python qt:5
USE_QT=		concurrent core gui network svg xml widgets buildtools_build linguisttools_build qmake_build uitools_build
USE_GL=		gl

USE_GITLAB=	yes
GL_ACCOUNT=	mattbas
GL_COMMIT=	7aaa27b346888d9aeae12815c3aa3e720adf985f

GL_TUPLE=	mattbas:CMake-Lib:2738b6bbc3d386fa7cafb2267d5ad597a1f455a8:mattbas_CMake_Lib/cmake \
		mattbas:Qt-Color-Widgets:8d0f56c0b855ae766183ffec2cc3e973a5d4bf8f:mattbas_Qt_Color_Widgets/external/Qt-Color-Widgets \
		mattbas:Qt-History-LineEdit:e6c254f5a893963dfece477bc99405495e471483:mattbas_Qt_History_LineEdit/external/Qt-History-LineEdit \
		mattbas:python-lottie:9e742aadb5ca7d0e8c9b01b2553c0a81de238ae4:mattbas_python_lottie/data/lib/python-lottie

USE_GITHUB=	nodefault
GH_TUPLE=	KDE:breeze-icons:1a13b09adc7ebe0c4b5be6cc1add3869f3de8a1a:KDE_breeze_icons/data/icons/breeze-icons \
		rpavlik/cmake-modules:c97690cc0024a1842cd8de71334a2ee9c5f7e729:rpavlik_cmake_modules/external/cmake-modules \
		mbasaglia:pybind11:7b30131fcbbbc227d2afcc969a8aab8c8b792b66:mbasaglia_pybind11/external/QtAppSetup/external/pybind11

CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}

.include <bsd.port.mk>
