# New ports collection makefile for:   opencv
# Date created:                05 March 2005
# Whom:                        Marc Abramowitz (http://marc.abramowitz.info)
#
# $FreeBSD$
#

PORTNAME=	opencv
PORTVERSION=	2.1.0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}library/${PORTNAME}-unix/${PORTVERSION:R}
DISTNAME=	OpenCV-${PORTVERSION}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Open Source Computer Vision library from Intel

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/doc/license.txt

USE_GNOME=	pkgconfig
WANT_GSTREAMER=	yes
MAKE_JOBS_SAFE=	yes
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	does not compile on sparc64

PORTDOCS=	CMakeLists.txt ChangeLog.htm README.txt \
		haartraining.htm index.htm license.txt \
		opencv-logo.png opencv-logo2.png opencv.jpg \
		opencv.pdf packaging.txt papers pattern.pdf vidsurv

PORTEXAMPLES=	c

OPTIONS=	FFMPEG	"Include FFmpeg support" off \
		GSTREAMER	"Include Gstreamer support" off \
		GTK	"Include GTK+ support" off \
		JASPER	"Include JPEG 2000 support" on \
		JPEG	"Include JPEG support" on \
		PNG	"Include PNG support" on \
		PYTHON	"Build with Python support" off \
		TBB	"Include TBB support" off \
		TIFF	"Include TIFF support" on \
		V4L	"Include Video4Linux support" on \
		XINE	"Include XINE support" off

# Cannot be built with CMake yet.
#OCTAVE	"Build with Octave support" off \

.include <bsd.port.options.mk>

.ifndef(NOPORTEXAMPLES)
CMAKE_ARGS+=	-DBUILD_EXAMPLES:BOOL=On -DINSTALL_C_EXAMPLES:BOOL=On
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

#.ifdef(WITH_OCTAVE)
#.include "${PORTSDIR}/Mk/bsd.octave.mk"
#CMAKE_ARGS+=	-DBUILD_OCTAVE_SUPPORT:BOOL=On
#.ifndef(NOPORTEXAMPLES)
#CMAKE_ARGS+=	-DINSTALL_OCTAVE_EXAMPLES:BOOL=On
#PORTEXAMPLES+=	octave
#.endif
#PLIST_SUB+=	OCTAVE=""
#.else
#CMAKE_ARGS+=	-DBUILD_OCTAVE_SUPPORT:BOOL=Off
#PLIST_SUB+=	OCTAVE="@comment "
#.endif

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

.include <bsd.port.pre.mk>

# This whole block looks a bit hackish, but it works...
.if ${ARCH} == "amd64" && ${OSVERSION} < 700042
USE_GCC=	4.2+
.else
CMAKE_OUTSOURCE=	yes
.if ${ARCH} == "i386" && ${OSVERSION} >= 700042 && ${OSVERSION} < 800107
USE_GCC=	4.4+
.endif
.endif

# Any other way to override CFLAGS and CXXFLAGS?
.ifdef(USE_GCC)
CMAKE_SOURCE_PATH=	-DCMAKE_C_FLAGS:STRING="${CFLAGS:C/-Wl[^ ]*//g}" \
			-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS:C/-Wl[^ ]*//g}" \
			${WRKSRC}
.endif

pre-configure:
	@${MKDIR} ${CONFIGURE_WRKSRC}
	@${REINPLACE_CMD} -e 's:set(OPENCV_SOVERSION.*:set(OPENCV_SOVERSION "$${OPENCV_VERSION_MAJOR}"):' \
		-e 's:-pthread:${PTHREAD_LIBS}:g' \
		-e 's:lib/pkgconfig:libdata/pkgconfig:g' \
		-e 's:${PORTNAME}/doc:doc/${PORTNAME}:g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's:${PORTNAME}/samples:examples/${PORTNAME}:g' \
		${WRKSRC}/samples/*/CMakeLists.txt
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/add_subdirectory(doc)/ d' \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
