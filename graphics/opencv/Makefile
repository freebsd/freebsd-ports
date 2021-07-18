PORTNAME=	opencv
DISTVERSION=	4.5.3
CATEGORIES=	graphics

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Open Source Computer Vision library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers \
		opencl>=0:devel/opencl
RUN_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	\
		libOpenEXR.so:graphics/openexr \
		libavcodec.so:multimedia/ffmpeg \
		libfreetype.so:print/freetype2 \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libgphoto2.so:graphics/libgphoto2 \
		libharfbuzz.so:print/harfbuzz \
		libhdf5.so:science/hdf5 \
		libopenblas.so:math/openblas \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp

USES=		cmake compiler:c++14-lang eigen:3 jpeg localbase:ldflags pkgconfig python:3.6+,build
USE_GITHUB=	yes
GH_ACCOUNT=	WeChatCV:wechat
GH_PROJECT=	opencv_contrib:contrib \
		ade:ade \
		opencv_3rdparty:extra_mod_3rdparty_boost_descr \
		opencv_3rdparty:extra_mod_3rdparty_vgg \
		opencv_3rdparty:wechat \
		opencv_3rdparty:face \
		opencv_3rdparty:ippicv
GH_TAGNAME=	v0.1.1f:ade \
		34e4206aef44d50e6bbcd0ab06354b52e7466d26:extra_mod_3rdparty_boost_descr \
		fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d:extra_mod_3rdparty_vgg \
		a8b69ccc738421293254aec5ddb38bd523503252:wechat \
		8afa57abc8229d611c4937165d20e2a2d9fc5a12:face \
		a56b6ac6f030c312b2dce17430eef13aed9af274:ippicv

CMAKE_ON=	WITH_EIGEN  \
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
LDFLAGS+=	-lglog

DATADIR=	${PREFIX}/share/${PORTNAME}4

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

OPTIONS_DEFINE=		HARDENING PYTHON JAVA LTO
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

HARDENING_CMAKE_BOOL=	ENABLE_BUILD_HARDENING
HARDENING_DESC=		Enable hardening of the resulting binaries

JAVA_CMAKE_BOOL=	BUILD_JAVA
JAVA_BUILD_DEPENDS=	ant:devel/apache-ant
JAVA_MAKE_ENV=		JAVACMD=${JAVA}
JAVA_USE=		JAVA=yes
JAVA_VARS=		JAVA_BUILD=yes

PYTHON_BUILD_DEPENDS=	${PYNUMPY}
PYTHON_RUN_DEPENDS=	${PYNUMPY}
PYTHON_USES=		python:3.6+
PYTHON_CMAKE_BOOL=	BUILD_opencv_python3

LTO_CMAKE_BOOL=		ENABLE_THIN_LTO

_IPPICV_i386=		ippicv/ippicv_2020_lnx_ia32_20191018_general.tgz
_IPPICV_amd64=		ippicv/ippicv_2020_lnx_intel64_20191018_general.tgz

post-extract:
	# Handle contrib
	${MV} ${WRKSRC_contrib} ${WRKSRC}/contrib
	# Handle prefetched ade modul
	${MKDIR} ${BUILD_WRKSRC}/3rdparty/ade
	${MV} ${WRKSRC_ade} ${BUILD_WRKSRC}/3rdparty/ade
	# Handle prefetched xfeatures2d
	${MKDIR} ${BUILD_WRKSRC}/downloads/xfeatures2d
	cp ${WRKSRC_extra_mod_3rdparty_boost_descr}/* ${BUILD_WRKSRC}/downloads/xfeatures2d
	cp ${WRKSRC_extra_mod_3rdparty_vgg}/* ${BUILD_WRKSRC}/downloads/xfeatures2d
	# Handle prefetched wechat
	${MKDIR} ${BUILD_WRKSRC}/downloads/wechat_qrcode
	cp ${WRKSRC_wechat}/* ${BUILD_WRKSRC}/downloads/wechat_qrcode/
	# Handle Face
	${MKDIR} ${BUILD_WRKSRC}/share/opencv4/testdata/cv/face
	cp ${WRKSRC_face}/* ${BUILD_WRKSRC}/share/opencv4/testdata/cv/face
	# Handle ippicv
.if defined(_IPPICV_${ARCH})
	${MKDIR} ${BUILD_WRKSRC}/3rdparty/ippicv
	(cd ${BUILD_WRKSRC}/3rdparty/ippicv && ${EXTRACT_CMD} -xf ${WRKSRC_ippicv}/${_IPPICV_${ARCH}})
.endif

.include <bsd.port.mk>
