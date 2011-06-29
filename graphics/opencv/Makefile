# New ports collection makefile for:   opencv
# Date created:                05 March 2005
# Whom:                        Marc Abramowitz (http://marc.abramowitz.info)
#
# $FreeBSD$
#

PORTNAME?=	opencv
DISTVERSION=	2.3.0rc
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}library/${PORTNAME}-unix/${DISTVERSION:R}
DISTNAME=	OpenCV-${DISTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Open Source Computer Vision library from Intel

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/doc/license.txt

USE_GNOME=	pkgconfig
WANT_GSTREAMER=	yes
MAKE_JOBS_SAFE=	yes
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/OpenCV-${DISTVERSION:S/rc//}

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	does not compile on sparc64

.if !defined(BUILDING_OPENCV_CORE)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-opencv
LIB_DEPENDS+=	opencv_core.2:${PORTSDIR}/graphics/opencv-core
CMAKE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

PORTDOCS=	*

OPTIONS=	EIGEN2	"Include Eigen 2 support" on \
		FFMPEG	"Include FFmpeg support" off \
		GSTREAMER	"Include Gstreamer support" off \
		GTK	"Include GTK+ support" off \
		JASPER	"Include JPEG 2000 support" on \
		JPEG	"Include JPEG support" on \
		OPENEXR	"Include OpenEXR support" off \
		PNG	"Include PNG support" on \
		PYTHON	"Build with Python support" off \
		QT4	"Build with Qt backend support" off \
		TBB	"Include TBB support" off \
		TIFF	"Include TIFF support" on \
		V4L	"Include Video4Linux support" on \
		XINE	"Include XINE support" off

.include <bsd.port.options.mk>

.ifndef(NOPORTEXAMPLES)
CMAKE_ARGS+=	-DBUILD_EXAMPLES:lBOOL=On -DINSTALL_C_EXAMPLES:BOOL=On
PORTEXAMPLES+=	c
.endif

.ifndef(WITHOUT_EIGEN2)
BUILD_DEPENDS+=	${LOCALBASE}/include/eigen2/Eigen/Eigen:${PORTSDIR}/math/eigen2
CMAKE_ARGS+=	-DWITH_EIGEN2:BOOL=On
.else
CMAKE_ARGS+=	-DDWITH_EIGEN2:BOOL=Off
.endif

.ifdef(WITH_FFMPEG)
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
CMAKE_ARGS+=	-DWITH_FFMPEG:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_FFMPEG:BOOL=Off
.endif

.ifdef(WITH_GSTREAMER)
USE_GSTREAMER=	yes
CMAKE_ARGS+=	-DWITH_GSTREAMER:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_GSTREAMER:BOOL=Off
.endif

.ifdef(WITH_GTK)
USE_GNOME=	gtk20
CMAKE_ARGS+=	-DWITH_GTK:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_GTK:BOOL=Off
.endif

.ifndef(WITHOUT_JASPER)
LIB_DEPENDS+=	jasper.4:${PORTSDIR}/graphics/jasper
CMAKE_ARGS+=	-DWITH_JASPER:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_JASPER:BOOL=Off
.endif

.ifndef(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
CMAKE_ARGS+=	-DWITH_JPEG:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_JPEG:BOOL=Off
.endif

.ifdef(WITH_OPENEXR)
LIB_DEPENDS+=	IlmImf:${PORTSDIR}/graphics/OpenEXR
CMAKE_ARGS+=	-DWITH_OPENEXR:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_OPENEXR:BOOL=Off
.endif

.ifndef(WITHOUT_PNG)
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
CMAKE_ARGS+=	-DWITH_PNG:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_PNG:BOOL=Off
.endif

.ifdef(WITH_PYTHON)
USE_PYTHON=	yes
BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY}
CMAKE_ARGS+=	-DBUILD_NEW_PYTHON_SUPPORT:BOOL=On
.ifndef(NOPORTEXAMPLES)
CMAKE_ARGS+=	-DINSTALL_PYTHON_EXAMPLES:BOOL=On
PORTEXAMPLES+=	python
.endif
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS+=	-DBUILD_NEW_PYTHON_SUPPORT:BOOL=Off
PLIST_SUB+=	PYTHON="@comment "
.endif

.ifdef(WITH_QT4)
USE_QT_VER= 	4
QT_COMPONENTS+=	opengl moc_build qmake_build rcc_build uic_build
CMAKE_ARGS+=	-DWITH_QT:BOOL=On -DWITH_QT_OPENGL:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_QT:BOOL=Off
.endif

.ifdef(WITH_TBB)
LIB_DEPENDS+=	tbb.3:${PORTSDIR}/devel/tbb
CMAKE_ARGS+=	-DWITH_TBB:BOOL=On \
		-DTBBLIB_FOUND:BOOL=1 -DTBB_FOUND:BOOL=On \
		-DTBB_INCLUDE_DIRS:STRING="${LOCALBASE}/include" \
		-DTBB_LIBRARY_DIRS:STRING="${LOCALBASE}/lib" \
		-DTBB_LIBRARIES:STRING="tbb"
.else
CMAKE_ARGS+=	-DWITH_TBB:BOOL=Off
.endif

.ifndef(WITHOUT_TIFF)
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
CMAKE_ARGS+=	-DWITH_TIFF:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_TIFF:BOOL=Off
.endif

.ifndef(WITHOUT_V4L)
LIB_DEPENDS+=	v4l2.0:${PORTSDIR}/multimedia/libv4l
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
CMAKE_ARGS+=	-DWITH_V4L:BOOL=On \
		-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"
.else
CMAKE_ARGS+=	-DWITH_V4L:BOOL=Off
.endif

.ifdef(WITH_XINE)
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
CMAKE_ARGS+=	-DWITH_XINE:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_XINE:BOOL=Off
.endif

.else # !defined(BUILDING_OPENCV_CORE)
COMMENT=	OpenCV core libraries
PLIST=		${PKGDIR}/pkg-plist.core
PKGNAMESUFFIX=	-core
LATEST_LINK=	${PORTNAME}-core
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-opencv-core
CMAKE_ARGS+=	-DBUILD_TESTS:BOOL=Off \
		-DBUILD_EXAMPLES:lBOOL=Off \
		-DBUILD_EXAMPLES:lBOOL=Off \
		-DDWITH_EIGEN2:BOOL=Off \
		-DWITH_FFMPEG:BOOL=Off \
		-DWITH_GSTREAMER:BOOL=Off \
		-DWITH_GTK:BOOL=Off \
		-DWITH_JASPER:BOOL=Off \
		-DWITH_JPEG:BOOL=Off \
		-DWITH_OPENEXR:BOOL=Off \
		-DWITH_PNG:BOOL=Off \
		-DBUILD_NEW_PYTHON_SUPPORT:BOOL=Off \
		-DINSTALL_PYTHON_EXAMPLES:BOOL=Off \
		-DWITH_QT:BOOL=Off \
		-DWITH_TBB:BOOL=Off \
		-DWITH_V4L:BOOL=Off \
		-DWITH_TIFF:BOOL=Off \
		-DWITH_XINE:BOOL=Off \
		-DWITH_PVAPI:BOOL=Off \
		-DWITH_1394:BOOL=Off \
		-DWITH_CUDA:BOOL=Off
.endif # !defined(BUILDING_OPENCV_CORE)

.include <bsd.port.pre.mk>

post-patch:
	@${MKDIR} ${CONFIGURE_WRKSRC}
	@${REINPLACE_CMD} -e 's:set(OPENCV_SOVERSION.*:set(OPENCV_SOVERSION "$${OPENCV_VERSION_MAJOR}"):' \
		-e 's:-pthread:${PTHREAD_LIBS}:g' \
		-e 's:lib/pkgconfig:libdata/pkgconfig:g' \
		-e 's:${PORTNAME}/doc:doc/${PORTNAME}:g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|${PORTNAME}/samples|examples/${PORTNAME}|g' \
		${WRKSRC}/samples/*/CMakeLists.txt
.if defined(BUILDING_OPENCV_CORE)
	@${REINPLACE_CMD} -e '/add_subdirectory(data)/ d' \
		-e '/add_subdirectory(include)/ d' \
		-e 's|opencv.pc|opencv-core.pc|g' \
		-e 's|OpenCVConfig.cmake|OpenCVConfig-core.cmake|g' \
		${WRKSRC}/CMakeLists.txt
	@${SED} -E -e \
		's|Name:.*|Name: OpenCV-core|' -e \
		's|Libs:.*|Libs: -L$${libdir} -lopencv_core@OPENCV_DLLVERSION@ -lopencv_imgproc@OPENCV_DLLVERSION@ -lopencv_video@OPENCV_DLLVERSION@ -lopencv_flann@OPENCV_DLLVERSION@|' \
		${WRKSRC}/opencv.pc.cmake.in > ${WRKSRC}/opencv-core.pc.cmake.in
	@${SED} -E -e \
		's|    set\(OPENCV_LIB_COMPONENTS .*|    set\(OPENCV_LIB_COMPONENTS opencv_core opencv_imgproc opencv_video opencv_ml opencv_flann\)|g' \
		${WRKSRC}/OpenCVConfig.cmake.in > ${WRKSRC}/OpenCVConfig-core.cmake.in
.endif
.if defined(NOPORTDOCS) || defined(BUILDING_OPENCV_CORE)
	@${REINPLACE_CMD} -e '/add_subdirectory(doc)/ d' \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
