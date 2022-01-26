PORTNAME=	opencv
DISTVERSION=	4.5.5
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Open Source Computer Vision library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libharfbuzz.so:print/harfbuzz \
		libhdf5.so:science/hdf5

USES=		cmake compiler:c++14-lang cpe localbase:ldflags pkgconfig
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

CMAKE_ON=	OPENCV_GENERATE_PKGCONFIG
CMAKE_OFF=	OPENCV_GENERATE_SETUPVARS \
		BUILD_opencv_python2 \
		BUILD_TESTS \
		WITH_TESSERACT
CMAKE_ARGS=	-DOPENCV_EXTRA_MODULES_PATH="${WRKSRC}/contrib/modules"

DATADIR=	${PREFIX}/share/${PORTNAME}4

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

OPTIONS_DEFINE=		EIGEN GDAL GDCM HARDENING JAVA LTO OPENCL PATENTED PROTOBUF PYTHON TBB

OPTIONS_GROUP=		GUI IMAGE VIDEO
OPTIONS_GROUP_GUI=	GTK3 VTK
OPTIONS_GROUP_IMAGE=	GPHOTO2 JPEG OPENEXR PNG TIFF
OPTIONS_GROUP_VIDEO=	DC1394 FFMPEG GSTREAMER V4L VULKAN WEBP XINE

OPTIONS_SINGLE=		BLAS
OPTIONS_SINGLE_BLAS=	ATLAS OPENBLAS NOBLAS

OPTIONS_RADIO=		JPEG2K
OPTIONS_RADIO_JPEG2K=	JASPER OPENJPEG

OPTIONS_DEFAULT=	EIGEN GDAL GDCM OPENCL PROTOBUF PYTHON \
			DC1394 GSTREAMER V4L VULKAN WEBP \
			GPHOTO2 JPEG OPENEXR PNG TIFF \
			OPENBLAS \
			OPENJPEG
OPTIONS_SUB=		yes

# Normal options (EIGEN GDAL GDCM HARDENING JAVA LTO OPENCL PATENTED PROTOBUF PYTHON TBB)
EIGEN_DESC=		Add Eigen v3 Support, builds sfm modules
EIGEN_CMAKE_BOOL=	WITH_EIGEN
EIGEN_USES=		eigen:3

GDAL_DESC=		Add Geospatial Data Abstraction Library Support
GDAL_CMAKE_BOOL=	WITH_GDAL
GDAL_LIB_DEPENDS=	libgdal.so:graphics/gdal

GDCM_DESC=		Add Open source DICOM library Support
GDCM_CMAKE_BOOL=	WITH_GDCM
GDCM_LIB_DEPENDS=	libgdcmMSFF.so:devel/gdcm

HARDENING_DESC=		Enables Build Hardening
HARDENING_CMAKE_BOOL=	ENABLE_BUILD_HARDENING

JAVA_DESC=		Enable Java Support
JAVA_BUILD_DEPENDS=	ant:devel/apache-ant
JAVA_CMAKE_BOOL=	BUILD_opencv_java BUILD_opencv_java_bindings_generator BUILD_JAVA
JAVA_MAKE_ENV=		JAVACMD=${JAVA}
JAVA_USE=		JAVA=yes

LTO_DESC=		Enables Link Time Optimizations
LTO_CMAKE_BOOL=		ENABLE_THIN_LTO

OPENCL_DESC=		Add OpenCL Support
OPENCL_CMAKE_BOOL=	WITH_OPENCL
OPENCL_BUILD_DEPENDS=	opencl>=0:devel/opencl
OPENCL_RUN_DEPENDS=	opencl>=0:devel/opencl

PATENTED_DESC=		Enable patented 2d feature detection USE AT OWN RISK
PATENTED_CMAKE_BOOL=	OPENCV_ENABLE_NONFREE

PROTOBUF_DESC=		Enable protobuf support, builds dnn modules
PROTOBUF_CMAKE_BOOL=	WITH_PROTOBUF
PROTOBUF_LIB_DEPENDS=	libprotobuf.so:devel/protobuf

PYTHON_DESC=		Enable Python Support 3.6 or greater
PYTHON_BUILD_DEPENDS=	${PYNUMPY}
PYTHON_RUN_DEPENDS=	${PYNUMPY}
PYTHON_USES=		python:3.6+
PYTHON_CMAKE_BOOL=	BUILD_opencv_python3
PYTHON_CMAKE_ON=	-DOPENCV_PYTHON3_INSTALL_PATH=${PYTHON_SITELIBDIR}

TBB_DESC=		Add Intel Threading Building Blocks Support
TBB_CMAKE_BOOL=		WITH_TBB
TBB_LIB_DEPENDS=	libtbb.so:devel/tbb
###

# GUI group options (GTK3 VTK)
GTK3_USES=		gnome
GTK3_USE=		gnome=gtk30
GTK3_CMAKE_BOOL=	WITH_GTK

VTK_DESC=		Include VTK library support (build opencv_viz module)
VTK_CMAKE_BOOL=		WITH_VTK
VTK_LIB_DEPENDS=	libvtkCommonCore-9.1.so:math/vtk9
###

# IMAGE group options (GPHOTO2 JPEG OPENEXR PNG TIFF)
GPHOTO2_DESC=		Add Gphoto2 Support
GPHOTO2_CMAKE_BOOL=	WITH_GPHOTO2
GPHOTO2_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2

JPEG_DESC=		Add LibJpeg Support
JPEG_CMAKE_BOOL=	WITH_JPEG
JPEG_USES=		jpeg

OPENEXR_DESC=		Add OpenEXR Support
OPENEXR_CMAKE_BOOL=	WITH_OPENEXR
OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr

PNG_DESC=		Add LibPNG Support
PNG_CMAKE_BOOL=		WITH_PNG
PNG_LIB_DEPENDS=	libpng16.so:graphics/png

TIFF_DESC=		Add LibTIFF Support
TIFF_CMAKE_BOOL=	WITH_TIFF
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
###

# VIDEO group options (DC1394 FFMPEG GSTREAMER V4L VULKAN WEBP XINE)
DC1394_DESC=		IEEE 1394 camera support
DC1394_CMAKE_BOOL=	WITH_1394
DC1394_LIB_DEPENDS=	libdc1394.so:multimedia/libdc1394

FFMPEG_DESC=		Link with ffmpeg
FFMPEG_CMAKE_BOOL=	WITH_FFMPEG
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

GSTREAMER_DESC=		Add GSTREAMER Support
GSTREAMER_CMAKE_BOOL=	WITH_GSTREAMER
GSTREAMER_USE=		GSTREAMER1=yes

V4L_DESC=		Enable support for Video for Linux
V4L_CMAKE_BOOL=		WITH_V4L WITH_LIBV4L
V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l

VULKAN_DESC=		Add Vulkan Support
VULKAN_CMAKE_BOOL=	WITH_VULKAN
VULKAN_CMAKE_ON=	-DVULKAN_INCLUDE_DIRS=${LOCALBASE}/include
VULKAN_BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

WEBP_DESC=		Add Webp Support
WEBP_CMAKE_BOOL=	WITH_WEBP
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

XINE_DESC=		Add Xine Support
XINE_CMAKE_BOOL=	WITH_XINE
XINE_LIB_DEPENDS=	libxine.so:multimedia/libxine
###

# BLAS group options (ATLAS OPENBLAS NOBLAS)
ATLAS_DESC=		ATLAS blas implementation with lapacke
ATLAS_USES=		blaslapack:atlas
ATLAS_LIB_DEPENDS=	liblapacke.so:math/lapacke

OPENBLAS_DESC=		OpenBLAS blas implementation with lapacke
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_LIB_DEPENDS=	liblapacke.so:math/lapacke

NOBLAS_DESC=		Disable support for lapack/blas
NOBLAS_CMAKE_BOOL_OFF=	WITH_LAPACK
###

# JPEG2K group options (JASPER OPENJPEG)
JASPER_DESC=		Add Jasper Support for JPEG2000
JASPER_CMAKE_BOOL=	WITH_JASPER
JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper

OPENJPEG_DESC=		Add OpenJPEG Support for JPEG2000, OpenCV preferred
OPENJPEG_CMAKE_BOOL=	WITH_OPENJPEG
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
###

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
	${CP} ${WRKSRC_extra_mod_3rdparty_boost_descr}/* ${BUILD_WRKSRC}/downloads/xfeatures2d
	${CP} ${WRKSRC_extra_mod_3rdparty_vgg}/* ${BUILD_WRKSRC}/downloads/xfeatures2d
	# Handle prefetched wechat
	${MKDIR} ${BUILD_WRKSRC}/downloads/wechat_qrcode
	${CP} ${WRKSRC_wechat}/* ${BUILD_WRKSRC}/downloads/wechat_qrcode/
	# Handle Face
	${MKDIR} ${BUILD_WRKSRC}/share/opencv4/testdata/cv/face
	${CP} ${WRKSRC_face}/* ${BUILD_WRKSRC}/share/opencv4/testdata/cv/face
	# Handle ippicv
.if defined(_IPPICV_${ARCH})
	${MKDIR} ${BUILD_WRKSRC}/3rdparty/ippicv
	(cd ${BUILD_WRKSRC}/3rdparty/ippicv && ${EXTRACT_CMD} -xf ${WRKSRC_ippicv}/${_IPPICV_${ARCH}})
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/lib/atlas-base|${LOCALBASE}/lib|g' ${WRKSRC}/cmake/OpenCVFindAtlas.cmake
	${REINPLACE_CMD} -e 's|/usr/include/atlas|${LOCALBASE}/include|g' ${WRKSRC}/cmake/OpenCVFindAtlas.cmake

.include <bsd.port.mk>
