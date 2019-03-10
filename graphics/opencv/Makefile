# Created by: Marc Abramowitz (http://marc.abramowitz.info)
# $FreeBSD$

PORTNAME=	opencv
PORTVERSION=	3.4.1
PORTREVISION=	14
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source Computer Vision library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	does not compile on sparc64

.if defined(OCV_CORE)
BUILD_DEPENDS=	protoc:devel/protobuf
.else
LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		libtesseract.so:graphics/tesseract
.endif

USES=		cmake compiler:c++14-lang localbase:ldflags pkgconfig

USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_CXXSTD=	c++11

DATADIR=	${PREFIX}/share/OpenCV
PLIST_SUB+=	SOVERSION=${DISTVERSION:R} VERSION=${DISTVERSION}

# 3rd party libs
CMAKE_ON=	ENABLE_CXX11
CMAKE_OFF=	BUILD_ZLIB BUILD_TIFF BUILD_JASPER BUILD_JPEG BUILD_PNG BUILD_OPENEXR BUILD_TBB BUILD_IPP_IW BUILD_ITT BUILD_PROTOBUF
# Optional 3rd party components
CMAKE_ARGS+=	-DWITH_1394:BOOL=OFF \
		-DWITH_CAROTENE:BOOL=OFF \
		-DWITH_CPUFEATURES:BOOL=OFF \
		-DWITH_VTK:BOOL=OFF \
		-DWITH_CUDA:BOOL=OFF \
		-DWITH_CUFFT:BOOL=OFF \
		-DWITH_CUBLAS:BOOL=OFF \
		-DWITH_NVCUVID:BOOL=OFF \
		-DWITH_EIGEN:BOOL=OFF \
		-DWITH_VFW:BOOL=OFF \
		-DWITH_FFMPEG:BOOL=OFF \
		-DWITH_GSTREAMER:BOOL=OFF \
		-DWITH_GSTREAMER_0_10:BOOL=OFF \
		-DWITH_GTK:BOOL=OFF \
		-DWITH_GTK_2_X:BOOL=ON \
		-DWITH_IPP:BOOL=OFF \
		-DWITH_IPP_A:BOOL=OFF \
		-DWITH_HALIDE:BOOL=OFF \
		-DWITH_JASPER:BOOL=OFF \
		-DWITH_JPEG:BOOL=OFF \
		-DWITH_WEBP:BOOL=OFF \
		-DWITH_OPENEXR:BOOL=OFF \
		-DWITH_OPENGL:BOOL=OFF \
		-DWITH_OPENVX:BOOL=OFF \
		-DWITH_OPENNI:BOOL=OFF \
		-DWITH_OPENNI2:BOOL=OFF \
		-DWITH_PNG:BOOL=OFF \
		-DWITH_GDCM:BOOL=OFF \
		-DWITH_PVAPI:BOOL=OFF \
		-DWITH_GIGEAPI:BOOL=OFF \
		-DWITH_ARAVIS:BOOL=OFF \
		-DWITH_QT:BOOL=OFF \
		-DWITH_WIN32UI:BOOL=OFF \
		-DWITH_TBB:BOOL=OFF \
		-DWITH_OPENMP:BOOL=OFF \
		-DWITH_CSTRIPES:BOOL=ON \
		-DWITH_PTHREADS_PF:BOOL=OFF \
		-DWITH_TIFF:BOOL=OFF \
		-DWITH_UNICAP:BOOL=OFF \
		-DWITH_V4L:BOOL=OFF \
		-DWITH_LIBV4L:BOOL=OFF \
		-DWITH_DSHOW:BOOL=OFF \
		-DWITH_MSMF:BOOL=OFF \
		-DWITH_XIMEA:BOOL=OFF \
		-DWITH_XINE:BOOL=OFF \
		-DWITH_CLP:BOOL=OFF \
		-DWITH_OPENCL:BOOL=OFF \
		-DWITH_OPENCL_SVM:BOOL=OFF \
		-DWITH_OPENCLAMDFFT:BOOL=OFF \
		-DWITH_OPENCLAMDBLAS:BOOL=OFF \
		-DWITH_DIRECTX:BOOL=OFF \
		-DWITH_INTELPERC:BOOL=OFF \
		-DWITH_MATLAB:BOOL=OFF \
		-DWITH_VA:BOOL=OFF \
		-DWITH_VA_INTEL:BOOL=OFF \
		-DWITH_MFX:BOOL=OFF \
		-DWITH_GDAL:BOOL=OFF \
		-DWITH_GPHOTO2:BOOL=OFF \
		-DWITH_LAPACK:BOOL=OFF \
		-DWITH_ITT:BOOL=OFF
# OpenCV build components
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON \
		-DBUILD_opencv_apps:BOOL=ON \
		-DBUILD_opencv_js:BOOL=OFF \
		-DBUILD_ANDROID_EXAMPLES:BOOL=OFF \
		-DBUILD_DOCS:BOOL=OFF \
		-DBUILD_EXAMPLES:BOOL=OFF \
		-DBUILD_PACKAGE:BOOL=OFF \
		-DBUILD_PERF_TESTS:BOOL=OFF \
		-DBUILD_TESTS:BOOL=OFF \
		-DBUILD_WITH_DEBUG_INFO:BOOL=OFF \
		-DBUILD_WITH_DYNAMIC_IPP:BOOL=OFF \
		-DBUILD_FAT_JAVA_LIB:BOOL=OFF \
		-DBUILD_CUDA_STUBS:BOOL=OFF \
		-DBUILD_ANDROID_SERVICE:BOOL=OFF \
		-DBUILD_opencv_ts:BOOL=OFF \
		-DBUILD_opencv_cnn_3dobj_INIT:BOOL=OFF \
		-DBUILD_opencv_world:BOOL=OFF
# OpenCV installation options
CMAKE_ARGS+=	-DINSTALL_CREATE_DISTRIB:BOOL=OFF \
		-DINSTALL_C_EXAMPLES:BOOL=OFF \
		-DINSTALL_PYTHON_EXAMPLES:BOOL=OFF \
		-DINSTALL_TO_MANGLED_PATHS:BOOL=OFF \
		-DINSTALL_TESTS:BOOL=OFF
# OpenCV build options
CMAKE_ARGS+=	-DENABLE_CCACHE:BOOL=OFF \
		-DENABLE_PRECOMPILED_HEADERS:BOOL=OFF \
		-DENABLE_SOLUTION_FOLDERS:BOOL=OFF \
		-DENABLE_PROFILING:BOOL=OFF \
		-DENABLE_COVERAGE:BOOL=OFF \
		-DENABLE_OMIT_FRAME_POINTER:BOOL=ON \
		-DENABLE_POWERPC:BOOL=OFF \
		-DENABLE_VSX:BOOL=OFF \
		-DENABLE_FAST_MATH:BOOL=OFF \
		-DENABLE_NEON:BOOL=OFF \
		-DENABLE_VFPV3:BOOL=OFF \
		-DENABLE_NOISY_WARNINGS:BOOL=OFF \
		-DOPENCV_WARNINGS_ARE_ERRORS:BOOL=OFF \
		-DENABLE_IMPL_COLLECTION:BOOL=OFF \
		-DENABLE_INSTRUMENTATION:BOOL=OFF \
		-DENABLE_GNU_STL_DEBUG:BOOL=OFF \
		-DENABLE_BUILD_HARDENING:BOOL=OFF \
		-DENABLE_LTO:BOOL=OFF \
		-DGENERATE_ABI_DESCRIPTOR:BOOL=OFF \
		-DCV_ENABLE_INTRINSICS:BOOL=ON \
		-DCV_DISABLE_OPTIMIZATION:BOOL=OFF \
		-DCV_TRACE:BOOL=OFF \
		-DENABLE_PYLINT:BOOL=OFF

SUB_FILES=	FindOpenCVCore.cmake
SUB_LIST=	OCV_VERSION=${DISTVERSION}

OCV_CORE_MODS=		core imgproc
OCV_MODS=		apps calib3d contrib dnn features2d flann highgui \
			imgcodecs ml objdetect photo shape stitching \
			superres ts video videoio videostab
OCV_JAVA_MODS=		java
OCV_PYTHON_MODS=	python${PYTHON_MAJOR_VER}

OPTIONS_DEFINE=		EXAMPLES EXTRA_MODULES OPENGL
OPTIONS_GROUP=		PERFORMANCE IMAGE VIDEO
OPTIONS_GROUP_PERFORMANCE=	EIGEN3 OPENCL TBB
OPTIONS_GROUP_IMAGE=	GDAL GDCM JASPER JPEG OPENEXR PNG TIFF WEBP
OPTIONS_GROUP_VIDEO=	ARAVIS DC1394 FFMPEG GPHOTO2 GSTREAMER V4L XINE
OPTIONS_RADIO=		GUI
OPTIONS_RADIO_GUI=	GTK2 QT4
# EXTRA_MODULES required for libopencv_dnn which is required by py-opencv
OPTIONS_DEFAULT=	EIGEN3 EXTRA_MODULES FFMPEG JASPER JPEG PNG TIFF WEBP V4L \
			${MACHINE_CPU:tu}
OPTIONS_SUB=		yes
.if defined(OCV_CORE)
OPTIONS_EXCLUDE=	ARAVIS DC1394 EXAMPLES EXTRA_MODULES FFMPEG \
			GDAL GDCM GPHOTO2 GSTREAMER GTK2 JASPER JPEG \
			OPENEXR OPENGL PNG QT4 TIFF WEBP V4L XINE
.elif defined(OCV_SLAVE)
OPTIONS_EXCLUDE=	EXAMPLES
.endif

DC1394_DESC=		IEEE 1394 camera support
DC1394_LIB_DEPENDS=	libdc1394.so:multimedia/libdc1394
DC1394_CMAKE_BOOL=	WITH_1394

EXAMPLES_CMAKE_BOOL=	INSTALL_C_EXAMPLES

PERFORMANCE_DESC=	Performance enhancing libraries

EIGEN3_DESC=		Eigen 3 support
EIGEN3_BUILD_DEPENDS=	${LOCALBASE}/include/eigen3/Eigen/Eigen:math/eigen3
EIGEN3_CMAKE_BOOL=	WITH_EIGEN

OPENCL_DESC=		OpenCL support
OPENCL_BUILD_DEPENDS=	opencl>=0:devel/opencl
OPENCL_RUN_DEPENDS=	opencl>=0:devel/opencl
OPENCL_CMAKE_BOOL=	WITH_OPENCL

TBB_DESC=		TBB support
TBB_LIB_DEPENDS=	libtbb.so:devel/tbb
TBB_CMAKE_BOOL=		WITH_TBB

IMAGE_DESC=		Image format support

JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
JASPER_CMAKE_BOOL=	WITH_JASPER

JPEG_USES=		jpeg
JPEG_CMAKE_BOOL=	WITH_JPEG

GDAL_DESC=		Geospatial Data Abstraction Library
GDAL_LIB_DEPENDS=	libgdal.so:graphics/gdal
GDAL_CMAKE_BOOL=	WITH_GDAL

GDCM_DESC=		Open source DICOM library
GDCM_LIB_DEPENDS=	libgdcmMSFF.so:devel/gdcm
GDCM_CMAKE_BOOL=	WITH_GDCM

OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/openexr
OPENEXR_CMAKE_BOOL=	WITH_OPENEXR

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_BOOL=		WITH_PNG

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CMAKE_BOOL=	WITH_TIFF

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CMAKE_BOOL=	WITH_WEBP

VIDEO_DESC=		Video support

ARAVIS_DESC=		Aravis SDK
ARAVIS_LIB_DEPENDS=	libaravis-0.6.so:devel/libaravis
ARAVIS_CMAKE_BOOL=	WITH_ARAVIS

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	WITH_FFMPEG

GPHOTO2_DESC=		Gphoto2 camera support
GPHOTO2_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO2_CMAKE_BOOL=	WITH_GPHOTO2

GSTREAMER_USE=		GSTREAMER1=yes
GSTREAMER_CMAKE_BOOL=	WITH_GSTREAMER

V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_CMAKE_BOOL=		WITH_V4L WITH_LIBV4L
V4L_CMAKE_ON=		CMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"

XINE_LIB_DEPENDS=	libxine.so:multimedia/libxine
XINE_CMAKE_BOOL=	WITH_XINE

EXTRA_MODULES_DESC=		Extra modules
EXTRA_MODULES_GH_ACCOUNT=	opencv:DEFAULT \
				tiny-dnn:extra_mod_3rdparty_tiny_dnn
EXTRA_MODULES_GH_PROJECT=	opencv_contrib:extra_mod \
				tiny-dnn:extra_mod_3rdparty_tiny_dnn \
				opencv_3rdparty:extra_mod_3rdparty_face_landmark_model \
				opencv_3rdparty:extra_mod_3rdparty_boost_descr \
				opencv_3rdparty:extra_mod_3rdparty_vgg_descr
EXTRA_MODULES_GH_TAGNAME=	${PORTVERSION}:extra_mod \
				2a2b50caa437a5964a61e45ffc83e70558e2bc68:extra_mod_3rdparty_tiny_dnn \
				8afa57abc8229d611c4937165d20e2a2d9fc5a12:extra_mod_3rdparty_face_landmark_model \
				34e4206aef44d50e6bbcd0ab06354b52e7466d26:extra_mod_3rdparty_boost_descr \
				fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d:extra_mod_3rdparty_vgg_descr
EXTRA_MODULES_LIB_DEPENDS=	libgflags.so:devel/gflags \
				libglog.so:devel/glog \
				libhdf5.so:science/hdf5
EXTRA_MODULES_EXTRA_PATCHES+=	${FILESDIR}/extra-patch-modules_dnn__modern_CMakeLists.txt \
				${FILESDIR}/extra-patch-modules_sfm_src__libmv__light_libmv_numeric_numeric.h \
				${FILESDIR}/extra-patch-modules_stereo_src_descriptor.cpp

OPENGL_DESC=		OpenGL (require QT or GTK2)
OPENGL_CMAKE_BOOL=	WITH_OPENGL
OPENGL_LIB_DEPENDS=	${PORT_OPTIONS:MGTK2:C,.+,libgtkglext-x11-1.0.so:x11-toolkits/gtkglext,}
OPENGL_USE=		${PORT_OPTIONS:MQT4:S,$,=opengl,}

# GUI

GTK2_USE=		GNOME=cairo,gdkpixbuf2,gtk20
GTK2_CMAKE_BOOL=	WITH_GTK
GTK2_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz \
			libsz.so:science/szip \
			libfontconfig.so:x11-fonts/fontconfig \
			liblept.so:graphics/leptonica

QT4_USES=		qt:4
QT4_USE=		QT=corelib,gui,moc_build,qmake_build,rcc_build,uic_build,qtestlib
QT4_CMAKE_ON=		-DWITH_QT:STRING="4"
QT4_CMAKE_OFF=		-DWITH_QT:BOOL=OFF
QT4_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz \
			libsz.so:science/szip \
			liblept.so:graphics/leptonica

.if defined(OCV_CORE)
. for module in ${OCV_MODS} ${OCV_JAVA_MODS} ${OCV_PYTHON_MODS}
CMAKE_ARGS+=	-DBUILD_opencv_${module}:BOOL=OFF
. endfor
.elif defined(OCV_PYTHON)
LIB_DEPENDS+=	libopencv_core.so:graphics/opencv-core \
		libopencv_imgproc.so:graphics/opencv-core \
		libopencv_ml.so:graphics/opencv
BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY}
USES+=		python:2.7
USE_PYTHON=	flavors
CMAKE_ARGS+=	-DBUILD_opencv_python${PYTHON_MAJOR_VER}:BOOL=ON
. for module in apps java stitching superres videostab
CMAKE_ARGS+=	-DBUILD_opencv_${module}:BOOL=OFF
. endfor
INSTALL_WRKSRC=	${WRKDIR}/.build/modules/python${PYTHON_MAJOR_VER}
.elif defined(OCV_JAVA)
BUILD_DEPENDS+=	ant:devel/apache-ant
LIB_DEPENDS+=	libopencv_ml.so:graphics/opencv
USES+=		python:build
USE_JAVA=	yes
CMAKE_ARGS+=	-DBUILD_opencv_java:BOOL=ON
. for module in apps python stitching superres videostab
CMAKE_ARGS+=	-DBUILD_opencv_${module}:BOOL=OFF
. endfor
CONFIGURE_ENV+=	JAVA_HOME="${JAVA_HOME}"
INSTALL_WRKSRC=	${WRKDIR}/.build/modules/java
.else
LIB_DEPENDS+=	libopencv_core.so:graphics/opencv-core
. for module in ${OCV_JAVA_MODS} ${OCV_PYTHON_MODS}
CMAKE_ARGS+=	-DBUILD_opencv_${module}:BOOL=OFF
. endfor
.endif

.if !defined(OCV_JAVA)
CMAKE_ARGS+=	-DBUILD_JAVA:BOOL=OFF
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

post-extract-EXTRA_MODULES-on:
	@${MV} ${WRKSRC_extra_mod}/doc/tutorials/* ${WRKSRC}/doc/tutorials/
	@${MV} ${WRKSRC_extra_mod}/modules/* ${WRKSRC}/modules/
	@${CP} -RpP ${WRKSRC_extra_mod}/samples/* ${WRKSRC}/samples/
	@${MKDIR} ${CONFIGURE_WRKSRC}/3rdparty/tinydnn/tiny-dnn-1.0.0a3/
	@${MV} ${WRKSRC_extra_mod_3rdparty_tiny_dnn}/* ${CONFIGURE_WRKSRC}/3rdparty/tinydnn/tiny-dnn-1.0.0a3/
	@${MKDIR} ${CONFIGURE_WRKSRC}/share/OpenCV/testdata/cv/face/
	@${MV} ${WRKSRC_extra_mod_3rdparty_face_landmark_model}/* ${CONFIGURE_WRKSRC}/share/OpenCV/testdata/cv/face/
	@${MKDIR} ${CONFIGURE_WRKSRC}/downloads/xfeatures2d/
	@${MV} ${WRKSRC_extra_mod_3rdparty_boost_descr}/* ${CONFIGURE_WRKSRC}/downloads/xfeatures2d/
	@${MV} ${WRKSRC_extra_mod_3rdparty_vgg_descr}/* ${CONFIGURE_WRKSRC}/downloads/xfeatures2d/

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/s|$${OPENCV_LIB_INSTALL_PATH}|libdata|' \
		 ${WRKSRC}/cmake/OpenCVGenPkgconfig.cmake
	@${REINPLACE_CMD} -e 's|$${OpenCV_SOURCE_DIR}/3rdparty/include/opencl/1.2|${LOCALBASE}/include/CL|g' \
		 ${WRKSRC}/cmake/OpenCVDetectOpenCL.cmake
	@${REINPLACE_CMD} -e 's|share/OpenCV/doc|${DOCSDIR_REL}|g' \
		-e 's|share/OpenCV/samples|${EXAMPLESDIR_REL}|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' \
		${WRKSRC}/modules/dnn/src/torch/THGeneral.cpp
.if defined(OCV_CORE)
	@${REINPLACE_CMD} -e 's|opencv.pc|opencv-core.pc|g' \
		${WRKSRC}/cmake/OpenCVGenPkgconfig.cmake
	@${REINPLACE_CMD} -e 's|Name:.*|Name: OpenCV-core|' \
		${WRKSRC}/cmake/templates/opencv-XXX.pc.in
.endif
.if defined(OCV_SLAVE)
	@${REINPLACE_CMD} -e 's|add_subdirectory(data)||g' \
		${WRKSRC}/CMakeLists.txt
.endif
	@${FIND} ${WRKSRC} -name '*.bak' -exec ${RM} {} \;

pre-build:
	protoc --proto_path=${WRKSRC}/modules/dnn/src/caffe/ --cpp_out=${WRKSRC}/modules/dnn/misc/caffe/ ${WRKSRC}/modules/dnn/src/caffe/*.proto
	protoc --proto_path=${WRKSRC}/modules/dnn/src/tensorflow/ --cpp_out=${WRKSRC}/modules/dnn/misc/tensorflow/ ${WRKSRC}/modules/dnn/src/tensorflow/*.proto

post-install:
.if !defined(OCV_SLAVE)
	(cd ${STAGEDIR}${PREFIX} && \
		${RM} -r include/opencv2/core include/opencv2/core.hpp include/opencv2/imgproc \
			include/opencv2/imgproc.hpp \
			include/opencv2/cvconfig.h lib/libopencv_core* lib/libopencv_imgproc*)
.endif
.if defined(OCV_CORE)
	${RM} -r ${STAGEDIR}${PREFIX}/include/opencv
	${RM} -r ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cmake/Modules
	${INSTALL_DATA} ${WRKDIR}/FindOpenCVCore.cmake ${STAGEDIR}${PREFIX}/share/cmake/Modules
.endif
.if defined(OCV_PYTHON)
	(cd ${STAGEDIR}${PREFIX} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S|${PREFIX}/||} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S|${PREFIX}/||})
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples/python && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/python
.endif
.if defined(OCV_JAVA)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples/java && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/java
.endif

.include <bsd.port.pre.mk>

.if !defined(OCV_CORE)
.if (${OPSYS} == FreeBSD && ${OSVERSION} < 1200000)
EXTRA_PATCHES+=			${FILESDIR}/extra-patch-modules_sfm_src_libmv__light_libmv_numeric_numeric.cc
.endif
.endif

.include <bsd.port.post.mk>
