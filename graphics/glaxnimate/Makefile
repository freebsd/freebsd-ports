PORTNAME=	glaxnimate
DISTVERSION=	0.5.4
CATEGORIES=	graphics

PATCH_SITES=	https://gitlab.com/${GL_ACCOUNT}/${PORTNAME}/-/commit/
PATCHFILES+=	6f312a0b93208255b2903f6d3105cc36cfc6b6c7.patch:-p1 # Fix build with Qt 6.5.x

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple vector animation program
WWW=		https://glaxnimate.mattbas.org/

BROKEN=		Does not build with ffmpeg > 6

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BROKEN_armv7=	lrelease coredumps, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=276285

BUILD_DEPENDS=	pip:devel/py-pip@${PY_FLAVOR}
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libpotrace.so:graphics/libpotrace

USES=		cmake compiler:c++17-lang desktop-file-utils gl libarchive \
		python qt:6
USE_GL=		gl
USE_QT=		base svg tools

CMAKE_ON=	WITH_QT6
CMAKE_OFF=	WITH_QT5

USE_GITLAB=	yes
GL_ACCOUNT=	mattbas
GL_TAGNAME=	3090870e9172dfd587e89753c2d4d19e9c083f70

GL_TUPLE=	mattbas:CMake-Lib:3b445d91fd4620542162f35ccc6bf14533a76321:mattbas_CMake_Lib/cmake \
		mattbas:Qt-Color-Widgets:621a1a3c336aedc451c1597e66449e239d0aed5e:mattbas_Qt_Color_Widgets/external/Qt-Color-Widgets \
		mattbas:Qt-History-LineEdit:5b761f436e8b31491e06b26460d28a2eaef0babc:mattbas_Qt_History_LineEdit/external/Qt-History-LineEdit \
		mattbas:python-lottie:9e742aadb5ca7d0e8c9b01b2553c0a81de238ae4:mattbas_python_lottie/data/lib/python-lottie

USE_GITHUB=	nodefault
GH_TUPLE=	KDE:breeze-icons:1a13b09adc7ebe0c4b5be6cc1add3869f3de8a1a:KDE_breeze_icons/data/icons/breeze-icons \
		pybind:pybind11:80dc998efced8ceb2be59756668a7e90e8bef917:pybind_pybind11/external/QtAppSetup/external/pybind11 \
		rpavlik/cmake-modules:c97690cc0024a1842cd8de71334a2ee9c5f7e729:rpavlik_cmake_modules/external/cmake-modules

CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}

ALL_TARGET=	all translations

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MDEBUG}
CXXFLAGS:=	${CXXFLAGS:C/-O([2-9]|[sz]|fast)/-O1/} -fstack-protector-strong -fno-strict-aliasing
.endif

.include <bsd.port.mk>
