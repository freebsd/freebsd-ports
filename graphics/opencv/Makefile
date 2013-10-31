# Created by: Marc Abramowitz (http://marc.abramowitz.info)
# $FreeBSD$

PORTNAME?=	opencv
PORTVERSION=	2.3.1
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}library/${PORTNAME}-unix/${PORTVERSION}
DISTNAME=	OpenCV-${DISTVERSION}a

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Open Source Computer Vision library from Intel

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/doc/license.txt

WANT_GSTREAMER=	yes
MAKE_JOBS_UNSAFE=	yes
USE_BZIP2=	yes
USES=		compiler:features cmake pkgconfig
USE_DOS2UNIX=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/OpenCV-${DISTVERSION}

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	does not compile on sparc64

DATADIR=	${PREFIX}/share/OpenCV
PLIST_SUB+=	VERSION=${DISTVERSION}

.if !defined(_BUILDING_OPENCV_CORE) && !defined(_BUILDING_OPENCV_PYTHON)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-opencv
LIB_DEPENDS+=	libopencv_core.so.2:${PORTSDIR}/graphics/opencv-core
LDFLAGS+=	-L${LOCALBASE}/lib -lopencv_core

PORTDOCS=	*

OPTIONS_DEFINE=		EIGEN3 FFMPEG GSTREAMER GTK2 JASPER JPEG OPENEXR PNG \
			QT4 TBB TIFF V4L XINE EXAMPLES
OPTIONS_DEFAULT=	EIGEN3 JASPER JPEG PNG TIFF V4L

EIGEN3_DESC=		Eigen 3 support
EIGEN3_BUILD_DEPENDS=	${LOCALBASE}/include/eigen3/Eigen/Eigen:${PORTSDIR}/math/eigen3
EIGEN3_CMAKE_ON=	-DWITH_EIGEN:BOOL=On
EIGEN3_CMAKE_OFF=	-DWITH_EIGEN:BOOL=Off

FFMPEG_LIB_DEPENDS=	libavcodec0.so:${PORTSDIR}/multimedia/ffmpeg0
FFMPEG_CMAKE_ON=	-DWITH_FFMPEG:BOOL=On
FFMPEG_CMAKE_OFF=	-DWITH_FFMPEG:BOOL=Off
FFMPEG_CXXFLAGS=	-I${LOCALBASE}/include/ffmpeg0

GSTREAMER_USE=		GSTREAMER=yes
GSTREAMER_CMAKE_ON=	-DWITH_GSTREAMER:BOOL=On
GSTREAMER_CMAKE_OFF=	-DWITH_GSTREAMER:BOOL=Off

GTK2_USE=		GNOME=gtk20
GTK2_CMAKE_ON=		-DWITH_GTK:BOOL=On
GTK2_CMAKE_OFF=		-DWITH_GTK:BOOL=Off

JASPER_LIB_DEPENDS=	libjasper.so:${PORTSDIR}/graphics/jasper
JASPER_CMAKE_ON=	-DWITH_JASPER:BOOL=On
JASPER_CMAKE_OFF=	-DWITH_JASPER:BOOL=Off

JPEG_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
JPEG_CMAKE_ON=		-DWITH_JPEG:BOOL=On
JPEG_CMAKE_OFF=		-DWITH_JPEG:BOOL=Off

OPENEXR_DESC=		OpenEXR support
OPENEXR_LIB_DEPENDS=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR
OPENEXR_CMAKE_ON=	-DWITH_OPENEXR:BOOL=On
OPENEXR_CMAKE_OFF=	-DWITH_OPENEXR:BOOL=Off

PNG_LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png
PNG_CMAKE_ON=		-DWITH_PNG:BOOL=On
PNG_CMAKE_OFF=		-DWITH_PNG:BOOL=Off

QT4_USE=		QT4=opengl moc_build qmake_build rcc_build uic_build qtestlib
QT4_CMAKE_ON=		-DWITH_QT:BOOL=On -DWITH_QT_OPENGL:BOOL=On
QT4_CMAKE_OFF=		-DWITH_QT:BOOL=Off

TBB_DESC=		TBB support
TBB_LIB_DEPENDS=	libtbb.so:${PORTSDIR}/devel/tbb
TBB_CMAKE_ON=		-DWITH_TBB:BOOL=On \
			-DTBBLIB_FOUND:BOOL=1 -DTBB_FOUND:BOOL=On \
			-DTBB_INCLUDE_DIRS:STRING="${LOCALBASE}/include" \
			-DTBB_LIBRARY_DIRS:STRING="${LOCALBASE}/lib" \
			-DTBB_LIBRARIES:STRING="tbb"
TBB_CMAKE_OFF=		-DWITH_TBB:BOOL=Off

TIFF_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff
TIFF_CMAKE_ON=		-DWITH_TIFF:BOOL=On
TIFF_CMAKE_OFF=		-DWITH_TIFF:BOOL=Off

V4L_LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l
V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
V4L_CMAKE_ON=		-DWITH_V4L:BOOL=On \
			-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"
V4L_CMAKE_OFF=		-DWITH_V4L:BOOL=Off

XINE_LIB_DEPENDS=	libxine.so:${PORTSDIR}/multimedia/libxine
XINE_CMAKE_ON=		-DWITH_XINE:BOOL=On
XINE_CMAKE_OFF=		-DWITH_XINE:BOOL=Off

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
CMAKE_ARGS+=	-DBUILD_EXAMPLES:BOOL=On -DINSTALL_C_EXAMPLES:BOOL=On
PORTEXAMPLES+=	c cpp gpu
.endif

.else # defined(_BUILDING_OPENCV_CORE) || defined(_BUILDING_OPENCV_PYTHON)

. if defined(_BUILDING_OPENCV_CORE)
COMMENT=	OpenCV core libraries
PLIST=		${PKGDIR}/pkg-plist.oc
PKGNAMESUFFIX=	-core
LATEST_LINK=	${PORTNAME}-core
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-opencv-core

. elif defined(_BUILDING_OPENCV_PYTHON)
COMMENT=	OpenCV Python library
CATEGORIES=	graphics python
PLIST=		${PKGDIR}/pkg-plist.python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	# no suffix

LIB_DEPENDS+=	libopencv_legacy.so.2:${PORTSDIR}/graphics/opencv
CMAKE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
INSTALL_WRKSRC=	${WRKSRC}/modules/python
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-opencv-python

USE_PYTHON=	yes
BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY}
. endif	# defined(_BUILDING_OPENCV_PYTHON)
CMAKE_ARGS+=	-DBUILD_EXAMPLES:BOOL=Off \
		-DINSTALL_PYTHON_EXAMPLES:BOOL=Off \
		-DBUILD_TESTS:BOOL=Off \
		-DWITH_EIGEN:BOOL=Off \
		-DWITH_FFMPEG:BOOL=Off \
		-DWITH_GSTREAMER:BOOL=Off \
		-DWITH_GTK:BOOL=Off \
		-DWITH_JASPER:BOOL=Off \
		-DWITH_JPEG:BOOL=Off \
		-DWITH_OPENEXR:BOOL=Off \
		-DWITH_PNG:BOOL=Off \
		-DWITH_QT:BOOL=Off \
		-DWITH_TBB:BOOL=Off \
		-DWITH_V4L:BOOL=Off \
		-DWITH_TIFF:BOOL=Off \
		-DWITH_XINE:BOOL=Off \
		-DWITH_PVAPI:BOOL=Off \
		-DWITH_1394:BOOL=Off \
		-DWITH_CUDA:BOOL=Off
.endif # defined(_BUILDING_OPENCV_CORE) || defined(_BUILDING_OPENCV_PYTHON)

.if defined(_BUILDING_OPENCV_PYTHON)
CMAKE_ARGS+=	-DBUILD_NEW_PYTHON_SUPPORT:BOOL=On
.else
CMAKE_ARGS+=	-DBUILD_NEW_PYTHON_SUPPORT:BOOL=Off
.endif

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE}=="clang"
USE_CXXSTD=	c++11
CXXFLAGS+=	-stdlib=libc++ -Wno-error -Wno-c++11-narrowing
.endif

post-patch:
	@${MKDIR} ${CONFIGURE_WRKSRC}
	@${REINPLACE_CMD} -e 's:set(OPENCV_SOVERSION.*:set(OPENCV_SOVERSION "$${OPENCV_VERSION_MAJOR}"):' \
		-e 's:-pthread:${PTHREAD_LIBS}:g' \
		-e 's:$${OPENCV_LIB_INSTALL_PATH}/pkgconfig:$${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig:g' \
		-e 's:share/OpenCV/doc:share/doc/opencv:g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|${PORTNAME}/samples|examples/${PORTNAME}|g' \
		${WRKSRC}/samples/*/CMakeLists.txt \
		${WRKSRC}/samples/*/*/CMakeLists.txt
	@${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} {} \;
	@${REINPLACE_CMD} \
		-e 's,libavcodec ,libavcodec0 ,g' \
		-e 's,libavformat ,libavformat0 ,g' \
		-e 's,libswscale ,libswscale0 ,g' \
		-e 's,libavutil ,libavutil0 ,g' \
		${WRKSRC}/CMakeLists.txt

.if defined(_BUILDING_OPENCV_CORE) && !defined(_BUILDING_OPENCV_PYTHON)
	@${REINPLACE_CMD} -e '/add_subdirectory(data)/ d' \
		-e '/add_subdirectory(include)/ d' \
		-e 's|opencv.pc|opencv-core.pc|g' \
		-e 's|OpenCVConfig.cmake|OpenCVConfig-core.cmake|g' \
		-e 's|OpenCVConfig-version.cmake|OpenCVConfig-core-version.cmake|g' \
		-e 's|    set(root_files README)||g' \
		-e 's|    install(CODE "exec_program.*||g' \
		${WRKSRC}/CMakeLists.txt
	@${SED} -E -e \
		's|Name:.*|Name: OpenCV-core|' -e \
		's|Libs:.*|Libs: -L$${libdir} -lopencv_core@OPENCV_DLLVERSION@ -lopencv_imgproc@OPENCV_DLLVERSION@ -lopencv_video@OPENCV_DLLVERSION@ -lopencv_flann@OPENCV_DLLVERSION@|' \
		${WRKSRC}/opencv.pc.cmake.in > ${WRKSRC}/opencv-core.pc.cmake.in
	@${SED} -E -e \
		's|    set\(OPENCV_LIB_COMPONENTS .*|    set\(OPENCV_LIB_COMPONENTS opencv_core opencv_imgproc opencv_video opencv_ml opencv_flann\)|g' \
		${WRKSRC}/OpenCVConfig.cmake.in > ${WRKSRC}/OpenCVConfig-core.cmake.in
	@${LN} -sf OpenCVConfig-version.cmake.in ${WRKSRC}/OpenCVConfig-core-version.cmake.in
.endif
.if ! ${PORT_OPTIONS:MDOCS} || defined(_BUILDING_OPENCV_CORE) || defined(_BUILDING_OPENCV_PYTHON)
	@${REINPLACE_CMD} -e '/add_subdirectory(doc)/ d' \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
