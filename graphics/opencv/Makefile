PORTNAME=	opencv
DISTVERSION=	4.11.0
PORTREVISION=	3
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/opencv/opencv/commit/
PATCHFILES=	97f3f390661f2fd1168336820b89eb4383ce8528.patch:-p1

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Open Source Computer Vision library
WWW=		https://www.opencv.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libhdf5.so:science/hdf5

USES=		cmake compiler:c++14-lang cpe gnome localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_PROJECT=	ade:ade opencv_3rdparty:ippicv opencv_contrib:contrib
GH_TAGNAME=	7f55c0c26be418d494615afca15218566775c725:ippicv v0.1.2e:ade
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DOPENCV_EXTRA_MODULES_PATH="${WRKSRC}/contrib/modules"
CMAKE_ON=	OPENCV_GENERATE_PKGCONFIG OPENCV_SKIP_CMAKE_CXX_STANDARD
CMAKE_OFF=	BUILD_opencv_python2 BUILD_TESTS OPENCV_GENERATE_SETUPVARS

DATADIR=	${PREFIX}/share/${PORTNAME}4

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

OPTIONS_DEFINE=		EIGEN GDAL GDCM HARDENING JAVA LTO OPENCL PATENTED \
			PROTOBUF PYTHON TBB TESSERACT
OPTIONS_DEFAULT=	DC1394 EIGEN GDAL GDCM GPHOTO2 GSTREAMER JPEG OPENBLAS \
			OPENCL OPENEXR OPENJPEG PNG PROTOBUF PYTHON TIFF V4L \
			VULKAN WEBP

OPTIONS_GROUP=		GUI IMAGE VIDEO
OPTIONS_GROUP_GUI=	GTK3 VTK
OPTIONS_GROUP_IMAGE=	AVIF GPHOTO2 JPEG OGRE3D OPENEXR PNG TIFF
OPTIONS_GROUP_VIDEO=	DC1394 FFMPEG GSTREAMER OBSENSOR V4L VULKAN WEBP XINE

OPTIONS_RADIO=		JPEG2K
OPTIONS_RADIO_JPEG2K=	JASPER OPENJPEG

OPTIONS_SINGLE=		BLAS
OPTIONS_SINGLE_BLAS=	ATLAS NOBLAS OPENBLAS

OPTIONS_SUB=	yes

# Normal options (EIGEN GDAL GDCM HARDENING JAVA LTO OPENCL PATENTED PROTOBUF PYTHON TBB)
EIGEN_DESC=		Add Eigen v3 Support, builds sfm modules
EIGEN_CMAKE_BOOL=	WITH_EIGEN
EIGEN_LIB_DEPENDS=	libceres.so:math/ceres-solver \
			libgflags.so:devel/gflags \
			libglog.so:devel/glog
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
JAVA_CMAKE_BOOL=	BUILD_JAVA BUILD_opencv_java \
			BUILD_opencv_java_bindings_generator
JAVA_MAKE_ENV=		JAVACMD=${JAVA}
JAVA_USES=		java

LTO_DESC=	Enables Link Time Optimizations
LTO_CMAKE_BOOL=	ENABLE_THIN_LTO

OPENCL_DESC=		Add OpenCL Support
OPENCL_CMAKE_BOOL=	WITH_OPENCL
OPENCL_BUILD_DEPENDS=	opencl>=0:devel/opencl
OPENCL_RUN_DEPENDS=	opencl>=0:devel/opencl

PATENTED_DESC=		Enable patented 2d feature detection USE AT OWN RISK
PATENTED_CMAKE_BOOL=	OPENCV_ENABLE_NONFREE

PROTOBUF_DESC=		Enable protobuf support, builds dnn modules
PROTOBUF_CMAKE_BOOL=	WITH_PROTOBUF # by default the bundled protobuf is built

PYTHON_DESC=		Enable Python Support 3.6 or greater
PYTHON_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}
PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	BUILD_opencv_python3
PYTHON_CMAKE_ON=	-DOPENCV_PYTHON3_INSTALL_PATH=${PYTHON_SITELIBDIR}

TBB_DESC=		Add Intel Threading Building Blocks Support
TBB_CMAKE_BOOL=		WITH_TBB
TBB_LIB_DEPENDS=	libtbb.so:devel/onetbb

TESSERACT_DESC=		Add Tesseract-based OCR
TESSERACT_LIB_DEPENDS=	libtesseract.so:graphics/tesseract
TESSERACT_CMAKE_BOOL=	WITH_TESSERACT
###

# GUI group options (GTK3 VTK)
GTK3_USE=		cairo,gdkpixbuf,gnome=gtk30
GTK3_CMAKE_BOOL=	WITH_GTK

VTK_DESC=		Include VTK library support (build opencv_viz module)
VTK_CMAKE_BOOL=		WITH_VTK
VTK_LIB_DEPENDS=	libvtkCommonCore-${VTK_VER}.so:math/vtk${VTK_VER:R}
VTK_USES=		qt:5
VTK_USE=		QT=buildtools:build,qmake:build
###

# IMAGE group options (AVIF GPHOTO2 JPEG OPENEXR PNG TIFF)
AVIF_LIB_DEPENDS=	libavif.so:graphics/libavif
AVIF_CMAKE_BOOL=	WITH_AVIF

GPHOTO2_DESC=		Add Gphoto2 Support
GPHOTO2_CMAKE_BOOL=	WITH_GPHOTO2
GPHOTO2_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2

JPEG_DESC=		Add LibJpeg Support
JPEG_CMAKE_BOOL=	WITH_JPEG
JPEG_USES=		jpeg

OGRE3D_DESC=		Add OGRE support
OGRE3D_LIB_DEPENDS=	libOgreMain.so:graphics/ogre3d
OGRE3D_CMAKE_BOOL=	BUILD_opencv_ovis

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
GSTREAMER_USES=		gstreamer
GSTREAMER_USE=		GNOME=glib20

OBSENSOR_DESC=		Orbbec 3D camera support
OBSENSOR_CMAKE_BOOL=	WITH_OBSENSOR
OBSENSOR_IMPLIES=	V4L

V4L_DESC=		Enable support for Video for Linux
V4L_CMAKE_BOOL=		WITH_LIBV4L WITH_V4L
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
ATLAS_BUILD_DEPENDS=	cblas>0:math/cblas \
			lapacke>0:math/lapacke

OPENBLAS_DESC=		OpenBLAS blas implementation with lapacke
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_BUILD_DEPENDS=	cblas>0:math/cblas \
			lapacke>0:math/lapacke

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

_IPPICV_amd64=	ippicv/ippicv_2021.12.0_lnx_intel64_20240425_general.tgz
_IPPICV_i386=	ippicv/ippicv_2021.12.0_lnx_ia32_20240425_general.tgz

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64le && defined(MACHINE_CPU) && ${MACHINE_CPU:Mvsx3}
CMAKE_ARGS+=	-DCPU_BASELINE:STRING="VSX;VSX3;"
.endif

post-extract:
# Handle contrib
	${MV} ${WRKSRC_contrib} \
		${WRKSRC}/contrib
# Handle prefetched ade modul
	${MKDIR} ${BUILD_WRKSRC}/3rdparty/ade
	${MV} ${WRKSRC_ade} \
		${BUILD_WRKSRC}/3rdparty/ade
# Handle ippicv
.if defined(_IPPICV_${ARCH})
	${MKDIR} ${BUILD_WRKSRC}/3rdparty/ippicv
	(cd ${BUILD_WRKSRC}/3rdparty/ippicv && \
		${EXTRACT_CMD} -xf ${WRKSRC_ippicv}/${_IPPICV_${ARCH}})
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/lib/atlas-base|${LOCALBASE}/lib|g' \
		${WRKSRC}/cmake/OpenCVFindAtlas.cmake
	${REINPLACE_CMD} -e 's|/usr/include/atlas|${LOCALBASE}/include|g' \
		${WRKSRC}/cmake/OpenCVFindAtlas.cmake

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
