# $FreeBSD$

PORTNAME=	opencv
DISTVERSION=	4.5.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Open Source Computer Vision library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers \
		opencl>=0:devel/opencl
RUN_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	\
		libIlmImf.so:graphics/openexr \
		libavcodec.so:multimedia/ffmpeg \
		libfreetype.so:print/freetype2 \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libgphoto2.so:graphics/libgphoto2 \
		libharfbuzz.so:print/harfbuzz \
		libhdf5.so:science/hdf5 \
		libopenblas.so:math/openblas \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp
#		libtbb.so:devel/tbb

USES=		cmake compiler:c++14-lang eigen:3 jpeg localbase:ldflags pkgconfig python:3.6+,build
USE_GITHUB=	yes
GH_PROJECT=	opencv_contrib:contrib \
		ade:ade \
		opencv_3rdparty:extra_mod_3rdparty_boost_descr \
		opencv_3rdparty:extra_mod_3rdparty_vgg_descr
GH_TAGNAME=	v0.1.1f:ade \
		34e4206aef44d50e6bbcd0ab06354b52e7466d26:extra_mod_3rdparty_boost_descr \
		fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d:extra_mod_3rdparty_vgg_descr

CMAKE_ON=	\
		WITH_EIGEN  \
		WITH_GDAL \
		WITH_GDCM \
		WITH_GPHOTO2 \
		WITH_JASPER \
		WITH_JPEG \
		WITH_OPENCL \
		WITH_OPENEXR \
		WITH_OPENGL \
		WITH_PNG \
		WITH_TIFF \
		WITH_VULKAN \
		WITH_WEBP \
		OPENCV_GENERATE_PKGCONFIG \
		OPENCV_ENABLE_NONFREE
# Disabled during tbb migration: not oneTBB-compatible
#		WITH_TBB
CMAKE_OFF=	OPENCV_GENERATE_SETUPVARS \
		BUILD_opencv_python2 \
		BUILD_TESTS
CMAKE_ARGS=	-DOPENCV_EXTRA_MODULES_PATH="${WRKSRC}/contrib/modules" \
		-DOPENCV_PYTHON3_INSTALL_PATH=${PYTHON_SITELIBDIR} \
		-DVULKAN_INCLUDE_DIRS=${LOCALBASE}/include

DATADIR=	${PREFIX}/share/${PORTNAME}4

OPTIONS_DEFINE=		HARDENING PYTHON JAVA LTO
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

HARDENING_CMAKE_BOOL=	ENABLE_BUILD_HARDENING
HARDENING_DESC=		Enable hardening of the resulting binaries

JAVA_CMAKE_BOOL=	BUILD_openv_java
JAVA_BUILD_DEPENDS=	ant:devel/apache-ant

PYTHON_BUILD_DEPENDS=	${PYNUMPY}
PYTHON_RUN_DEPENDS=	${PYNUMPY}
PYTHON_USES=		python:3.6+
PYTHON_CMAKE_BOOL=	BUILD_opencv_python3

LTO_CMAKE_BOOL=		ENABLE_THIN_LTO

post-extract:
	${MV} ${WRKSRC_contrib} ${WRKSRC}/contrib
	${MKDIR} ${BUILD_WRKSRC}/3rdparty/ade
	${MV} ${WRKSRC_ade} ${BUILD_WRKSRC}/3rdparty/ade
	${MKDIR} ${WRKSRC}/contrib/modules/xfeatures2d/src
	${MV} ${WRKSRC_extra_mod_3rdparty_boost_descr}/* ${WRKSRC}/contrib/modules/xfeatures2d/src
	${MV} ${WRKSRC_extra_mod_3rdparty_vgg_descr}/* ${WRKSRC}/contrib/modules/xfeatures2d/src

.include <bsd.port.mk>
