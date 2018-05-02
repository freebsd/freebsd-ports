# Created by: Marc Abramowitz (http://marc.abramowitz.info)
# $FreeBSD$

PORTNAME?=	opencv
PORTVERSION=	2.4.13.1
PORTREVISION?=	10
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source Computer Vision library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

USES=		cmake pkgconfig
USE_LDCONFIG=	yes

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	does not compile on sparc64

DATADIR=	${PREFIX}/share/OpenCV
PLIST_SUB+=	VERSION=${DISTVERSION:R}

CMAKE_ARGS+=	-DWITH_CUDA:BOOL=Off \
		-DWITH_PVAPI:BOOL=Off \
		-DWITH_UNICAP:BOOL=Off \
		-DBUILD_TESTS:BOOL=Off \
		-DBUILD_DOCS:BOOL=Off \
		-DPYTHON_EXECUTABLE:FILEPATH=${PYTHON_CMD}

SUB_FILES=	FindOpenCVCore.cmake
SUB_LIST=	OCV_VERSION=${DISTVERSION:R}

OCV_CORE_MODS=		core imgproc
OCV_MODS=		calib3d contrib features2d flann gpu \
			highgui legacy ml ocl objdetect photo \
			stitching superres ts video videostab
OCV_NONFREE_MODS=	nonfree
OCV_JAVA_MODS=		java
OCV_PYTHON_MODS=	python

OPTIONS_DEFINE=		DC1394 EXAMPLES NONFREE OPENGL
OPTIONS_GROUP=		IMAGE PERFORMANCE SIMD VIDEO
OPTIONS_GROUP_IMAGE=	JASPER JPEG OPENEXR PNG TIFF
OPTIONS_GROUP_PERFORMANCE=	EIGEN3 TBB
OPTIONS_GROUP_SIMD=	${OPTIONS_GROUP_SIMD_${MACHINE_ARCH}}
OPTIONS_GROUP_SIMD_amd64=	${OPTIONS_GROUP_SIMD_i386}
OPTIONS_GROUP_SIMD_armv6=	NEON VFPV3
#OPTIONS_GROUP_SIMD_armv7=	NEON VFPV3
OPTIONS_GROUP_SIMD_i386=	SSE SSE2 SSE3 SSSE3 SSE41 SSE42 AVX AVX2
OPTIONS_GROUP_VIDEO=	FFMPEG GSTREAMER GSTREAMER0 V4L XINE
OPTIONS_RADIO=		GUI
OPTIONS_RADIO_GUI=	GTK2 QT4
OPTIONS_DEFAULT=	EIGEN3 JASPER JPEG PNG TIFF V4L ${MACHINE_CPU:tu}
OPTIONS_SUB=		yes
.if defined(OCV_CORE)
OPTIONS_EXCLUDE=	DC1394 EXAMPLES GTK2 QT4 JASPER JPEG NONFREE OPENEXR \
			OPENGL PNG TIFF FFMPEG GSTREAMER GSTREAMER0 V4L XINE
.endif

DC1394_DESC=		IEEE 1394 camera support
DC1394_LIB_DEPENDS=	libdc1394.so:multimedia/libdc1394
DC1394_CMAKE_BOOL=	WITH_1394

EIGEN3_DESC=		Eigen 3 support
EIGEN3_USES=		eigen:3
EIGEN3_CMAKE_BOOL=	WITH_EIGEN

. if !defined(OCV_SLAVE)
EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES INSTALL_C_EXAMPLES
. endif
EXAMPLES_PORTEXAMPLES=	*

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	WITH_FFMPEG

GSTREAMER0_DESC=	${GSTREAMER_DESC} 0.10
GSTREAMER0_USE=		GSTREAMER=yes
GSTREAMER0_CMAKE_BOOL=	WITH_GSTREAMER_0_10

GSTREAMER_USE=		GSTREAMER1=yes
GSTREAMER_CMAKE_BOOL=	WITH_GSTREAMER

GTK2_USE=		GNOME=gtk20
GTK2_CMAKE_BOOL=	WITH_GTK

JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
JASPER_CMAKE_BOOL=	WITH_JASPER

JPEG_USES=		jpeg
JPEG_CMAKE_BOOL=	WITH_JPEG

NONFREE_CMAKE_BOOL=	BUILD_opencv_nonfree

OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/OpenEXR
OPENEXR_CMAKE_BOOL=	WITH_OPENEXR

OPENGL_LIB_DEPENDS=	${PORT_OPTIONS:MGTK2:C,.+,libgtkglext-x11-1.0.so:x11-toolkits/gtkglext,}
OPENGL_USE=		${PORT_OPTIONS:MQT4:S,$,=opengl,}
OPENGL_CMAKE_BOOL=	WITH_OPENGL

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_BOOL=		WITH_PNG

QT4_USE=		QT4=gui,moc_build,qmake_build,rcc_build,uic_build,qtestlib
QT4_CMAKE_ON=		-DWITH_QT:STRING="4"
QT4_CMAKE_OFF=		-DWITH_QT:BOOL=false

.for _simd in ${OPTIONS_GROUP_SIMD}
${_simd}_DESC=		${MMX_DESC:S/MMX/${_simd}/}
${_simd}_CMAKE_BOOL=	ENABLE_${_simd}
.endfor

TBB_LIB_DEPENDS=	libtbb.so:devel/tbb
TBB_CMAKE_BOOL=		WITH_TBB
TBB_CMAKE_ON=		-DTBB_INCLUDE_DIR:STRING="${LOCALBASE}/include"

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CMAKE_BOOL=	WITH_TIFF

V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_CMAKE_BOOL=		WITH_V4L
V4L_CMAKE_ON=		-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"

XINE_LIB_DEPENDS=	libxine.so:multimedia/libxine
XINE_CMAKE_BOOL=	WITH_XINE

IMAGE_DESC=		Image format support
NONFREE_DESC=		Build functionality that has possible limitations of use
PERFORMANCE_DESC=	Performance enhancing libraries
TBB_DESC=		TBB support

.if defined(OCV_CORE)
. for module in ${OCV_MODS} ${OCV_JAVA_MODS} ${OCV_PYTHON_MODS}
CMAKE_ARGS+=	-DBUILD_opencv_${module}:BOOL=Off
. endfor
.elif defined(OCV_PYTHON)
LIB_DEPENDS+=	libopencv_legacy.so:graphics/opencv
BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY}
USES+=		fortran python:2.7
USE_PYTHON=	flavors
CMAKE_ARGS+=	-DBUILD_opencv_python:BOOL=On
. for module in apps java stitching superres videostab
CMAKE_ARGS+=	-DBUILD_opencv_${module}:BOOL=Off
. endfor
INSTALL_WRKSRC=	${WRKSRC}/modules/python
.elif defined(OCV_JAVA)
BUILD_DEPENDS+=	ant:devel/apache-ant
LIB_DEPENDS+=	libopencv_legacy.so:graphics/opencv
USES+=		python:2.7,build
USE_JAVA=	yes
CMAKE_ARGS+=	-DBUILD_opencv_java:BOOL=On
. for module in apps python stitching superres videostab
CMAKE_ARGS+=	-DBUILD_opencv_${module}:BOOL=Off
. endfor
CONFIGURE_ENV+=	JAVA_HOME="${JAVA_HOME}"
INSTALL_WRKSRC=	${WRKSRC}/modules/java
.else
LIB_DEPENDS+=	libopencv_core.so:graphics/opencv-core
. for module in ${OCV_JAVA_MODS} ${OCV_PYTHON_MODS}
CMAKE_ARGS+=	-DBUILD_opencv_${module}:BOOL=Off
. endfor
.endif

post-patch:
	@${MKDIR} ${CONFIGURE_WRKSRC}
	@${REINPLACE_CMD} -e '/pkgconfig/s|$${OPENCV_LIB_INSTALL_PATH}|libdata|' \
		 ${WRKSRC}/cmake/OpenCVGenPkgconfig.cmake
	@${REINPLACE_CMD} -e 's|share/OpenCV/doc|${DOCSDIR_REL}|g' \
		-e 's|share/OpenCV/samples|${EXAMPLESDIR_REL}|g' \
		${WRKSRC}/CMakeLists.txt
	@${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} {} \;
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

post-install:
.if !defined(OCV_SLAVE)
	(cd ${STAGEDIR}${PREFIX} && \
		${RM} -r include/opencv2/core include/opencv2/imgproc \
			lib/libopencv_core* lib/libopencv_imgproc*)
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
	cd ${WRKSRC}/samples/python2 && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/python2
.endif
.if defined(OCV_JAVA)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples/java && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/java
.endif

.include <bsd.port.mk>
