# Created by: Marc Abramowitz (http://marc.abramowitz.info)
# $FreeBSD$

PORTNAME?=	opencv
PORTVERSION=	2.4.9
PORTREVISION?=	8
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}library/${PORTNAME}-unix/${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Open Source Computer Vision library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake pkgconfig zip
USE_LDCONFIG=	yes
WANT_GSTREAMER=	yes

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	does not compile on sparc64

DATADIR=	${PREFIX}/share/OpenCV
PLIST_SUB+=	VERSION=${DISTVERSION}

CMAKE_ARGS+=	-DWITH_CUDA:BOOL=Off \
		-DWITH_PVAPI:BOOL=Off \
		-DWITH_UNICAP:BOOL=Off \
		-DBUILD_TESTS:BOOL=Off \
		-DBUILD_DOCS:BOOL=Off \
		-DPYTHON_EXECUTABLE:FILEPATH=${PYTHON_CMD}

SUB_FILES=	FindOpenCVCore.cmake
SUB_LIST=	OCV_VERSION=${PORTVERSION}

OCV_CORE_MODS=		core imgproc
OCV_MODS=		calib3d contrib features2d flann gpu \
			highgui legacy ml ocl objdetect photo \
			stitching superres ts video videostab
OCV_NONFREE_MODS=	nonfree
OCV_JAVA_MODS=		java
OCV_PYTHON_MODS=	python

OPTIONS_DEFINE=		DC1394 EXAMPLES NONFREE OPENGL SIMD
OPTIONS_GROUP=		IMAGE PERFORMANCE VIDEO
OPTIONS_GROUP_IMAGE=	JASPER JPEG OPENEXR PNG TIFF
OPTIONS_GROUP_PERFORMANCE=	EIGEN3 TBB
OPTIONS_GROUP_VIDEO=	FFMPEG GSTREAMER V4L XINE
OPTIONS_RADIO=		GUI
OPTIONS_RADIO_GUI=	GTK2 QT4
OPTIONS_DEFAULT=	EIGEN3 JASPER JPEG PNG SIMD TIFF V4L
OPTIONS_SUB=		yes
.if defined(OCV_CORE)
OPTIONS_EXCLUDE=	DC1394 EXAMPLES GTK2 QT4 JASPER JPEG NONFREE OPENEXR \
			OPENGL PNG TIFF FFMPEG GSTREAMER V4L XINE
.endif

DC1394_DESC=		IEEE 1394 camera support
EIGEN3_DESC=		Eigen 3 support
IMAGE_DESC=		Image format support
NONFREE_DESC=		Build functionality that has possible limitations of use
PERFORMANCE_DESC=	Performance enhancing libraries
TBB_DESC=		TBB support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDC1394}
LIB_DEPENDS+=	libdc1394.so:multimedia/libdc1394
CMAKE_ARGS+=	-DWITH_1394:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_1394:BOOL=Off
.endif

.if ${PORT_OPTIONS:MEIGEN3}
BUILD_DEPENDS+=	${LOCALBASE}/include/eigen3/Eigen/Eigen:math/eigen3
CMAKE_ARGS+=	-DWITH_EIGEN:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_EIGEN:BOOL=Off
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
. if !defined(OCV_SLAVE)
CMAKE_ARGS+=	-DBUILD_EXAMPLES:BOOL=On \
		-DINSTALL_C_EXAMPLES:BOOL=On
. endif
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	libavcodec.so:multimedia/ffmpeg
CMAKE_ARGS+=	-DWITH_FFMPEG:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_FFMPEG:BOOL=Off
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER=	yes
CMAKE_ARGS+=	-DWITH_GSTREAMER:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_GSTREAMER:BOOL=Off
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
CMAKE_ARGS+=	-DWITH_GTK:BOOL=On
. if ${PORT_OPTIONS:MOPENGL}
LIB_DEPENDS+=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext
. endif
.else
CMAKE_ARGS+=	-DWITH_GTK:BOOL=Off
.endif

.if ${PORT_OPTIONS:MJASPER}
LIB_DEPENDS+=	libjasper.so:graphics/jasper
CMAKE_ARGS+=	-DWITH_JASPER:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_JASPER:BOOL=Off
.endif

.if ${PORT_OPTIONS:MJPEG}
USES+=		jpeg
CMAKE_ARGS+=	-DWITH_JPEG:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_JPEG:BOOL=Off
.endif

.if ${PORT_OPTIONS:MNONFREE}
CMAKE_ARGS+=	-DBUILD_opencv_nonfree:BOOL=On
.else
CMAKE_ARGS+=	-DBUILD_opencv_nonfree:BOOL=Off
.endif

.if ${PORT_OPTIONS:MOPENEXR}
LIB_DEPENDS+=	libIlmImf.so:graphics/OpenEXR
CMAKE_ARGS+=	-DWITH_OPENEXR:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_OPENEXR:BOOL=Off
.endif

.if ${PORT_OPTIONS:MOPENGL}
CMAKE_ARGS+=	-DWITH_OPENGL:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_OPENGL:BOOL=Off
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng.so:graphics/png
CMAKE_ARGS+=	-DWITH_PNG:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_PNG:BOOL=Off
.endif

.if ${PORT_OPTIONS:MQT4}
USE_QT4+=	gui moc_build qmake_build rcc_build uic_build qtestlib
CMAKE_ARGS+=	-DWITH_QT:STRING="4"
. if ${PORT_OPTIONS:MOPENGL}
USE_QT4+=	opengl
. endif
.else
CMAKE_ARGS+=	-DWITH_QT:BOOL=Off
.endif

.if ${PORT_OPTIONS:MSIMD}
. if ${MACHINE_CPU:Msse}
CMAKE_ARGS+=	-DENABLE_SSE:BOOL=On
. else
CMAKE_ARGS+=	-DENABLE_SSE:BOOL=Off
. endif
. if ${MACHINE_CPU:Msse2}
CMAKE_ARGS+=	-DENABLE_SSE2:BOOL=On
. else
CMAKE_ARGS+=	-DENABLE_SSE2:BOOL=Off
. endif
. if ${MACHINE_CPU:Msse3}
CMAKE_ARGS+=	-DENABLE_SSE3:BOOL=On
. else
CMAKE_ARGS+=	-DENABLE_SSE3:BOOL=Off
. endif
# TODO: Add support for instructions above SSE3 (upstream has them off by default)
CMAKE_ARGS+=	-DENABLE_SSSE3:BOOL=Off \
		-DENABLE_SSE41:BOOL=Off \
		-DENABLE_SSE42:BOOL=Off
.else
CMAKE_ARGS+=	-DENABLE_SSE:BOOL=Off \
		-DENABLE_SSE2:BOOL=Off \
		-DENABLE_SSE3:BOOL=Off \
		-DENABLE_SSSE3:BOOL=Off \
		-DENABLE_SSE41:BOOL=Off \
		-DENABLE_SSE42:BOOL=Off
.endif

.if ${PORT_OPTIONS:MTBB}
LIB_DEPENDS+=	libtbb.so:devel/tbb
CMAKE_ARGS+=	-DWITH_TBB:BOOL=On \
		-DTBB_INCLUDE_DIR:STRING="${LOCALBASE}/include"
.else
CMAKE_ARGS+=	-DWITH_TBB:BOOL=Off
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	libtiff.so:graphics/tiff
CMAKE_ARGS+=	-DWITH_TIFF:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_TIFF:BOOL=Off
.endif

.if ${PORT_OPTIONS:MV4L}
LIB_DEPENDS+=	libv4l2.so:multimedia/libv4l
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
CMAKE_ARGS+=	-DWITH_V4L:BOOL=On \
		-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"
.else
CMAKE_ARGS+=	-DWITH_V4L:BOOL=Off
.endif

.if ${PORT_OPTIONS:MXINE}
LIB_DEPENDS+=	libxine.so:multimedia/libxine
CMAKE_ARGS+=	-DWITH_XINE:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_XINE:BOOL=Off
.endif

.if defined(OCV_CORE)
. for module in ${OCV_MODS} ${OCV_JAVA_MODS} ${OCV_PYTHON_MODS}
CMAKE_ARGS+=	-DBUILD_opencv_${module}:BOOL=Off
. endfor
.elif defined(OCV_PYTHON)
LIB_DEPENDS+=	libopencv_legacy.so:graphics/opencv
BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY}
USES+=		python
CMAKE_ARGS+=	-DBUILD_opencv_python:BOOL=On
. for module in apps java stitching superres videostab
CMAKE_ARGS+=	-DBUILD_opencv_${module}:BOOL=Off
. endfor
INSTALL_WRKSRC=	${WRKSRC}/modules/python
.elif defined(OCV_JAVA)
BUILD_DEPENDS+=	ant:devel/apache-ant
LIB_DEPENDS+=	libopencv_legacy.so:graphics/opencv
USES+=		python:build
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
.   if defined(PYTHON_REL) && ${PYTHON_REL} >= 3000
	cd ${WRKSRC}/samples/python && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/python
.   else
	cd ${WRKSRC}/samples/python2 && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/python2
.   endif
.endif
.if defined(OCV_JAVA)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples/java && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/java
.endif

.include <bsd.port.mk>
