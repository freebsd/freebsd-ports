# New ports collection makefile for:   opencv
# Date created:                05 March 2005
# Whom:                        Marc Abramowitz (http://marc.abramowitz.info)
#
# $FreeBSD$
#

PORTNAME=	opencv
PORTVERSION=	2.0.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}library/${PORTNAME}-unix/2.0
DISTNAME=	OpenCV-${PORTVERSION}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Open Source Computer Vision library from Intel

USE_GNOME=	pkgconfig
WANT_GSTREAMER=	yes
MAKE_JOBS_SAFE=	yes
USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DWITH_1394:BOOL=Off -DWITH_UNICAP:BOOL=Off
CMAKE_SOURCE_PATH=	${WRKSRC}
USE_LDCONFIG=	yes

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	does not compile on sparc64

PORTDOCS=	CMakeLists.txt ChangeLog.htm haartraining.htm index.htm \
		latex_readme.txt license.txt opencv-logo.png \
		opencv-logo2.png opencv.jpg opencv.pdf packaging.txt \
		papers pattern.pdf python.txt vidsurv

PORTEXAMPLES=	c

OPTIONS=	FFMPEG	"Include FFmpeg support" off \
		GSTREAMER	"Include Gstreamer support" off \
		GTK	"Include GTK+ support" off \
		JASPER	"Include JPEG 2000 support" on \
		JPEG	"Include JPEG support" on \
		PNG	"Include PNG support" on \
		PYTHON	"Build with Python support" off \
		TIFF	"Include TIFF support" on \
		V4L	"Include Video4Linux support" on \
		XINE	"Include XINE support" off

# cannot be built with cmake yet
#OCTAVE	"Build with Octave support" off \

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
BROKEN=		does not build on 6.X
.endif

.ifndef(NOPORTEXAMPLES)
CMAKE_ARGS+=	-DBUILD_EXAMPLES:BOOL=On -DINSTALL_C_EXAMPLES:BOOL=On
.endif

.if defined(WITH_FFMPEG)
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
CMAKE_ARGS+=	-DWITH_FFMPEG:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_FFMPEG:BOOL=Off
.endif

.if defined(WITH_GSTREAMER)
LIB_DEPENDS+=	gstreamer-${GST_VERSION}.0:${PORTSDIR}/multimedia/gstreamer
CMAKE_ARGS+=	-DWITH_GSTREAMER:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_GSTREAMER:BOOL=Off
.endif

.if defined(WITH_GTK)
USE_GNOME=	gtk20
CMAKE_ARGS+=	-DWITH_GTK:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_GTK:BOOL=Off
.endif

.if !defined(WITHOUT_JASPER)
LIB_DEPENDS+=	jasper.4:${PORTSDIR}/graphics/jasper
CMAKE_ARGS+=	-DWITH_JASPER:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_JASPER:BOOL=Off
.endif

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
CMAKE_ARGS+=	-DWITH_JPEG:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_JPEG:BOOL=Off
.endif

#.if defined(WITH_OCTAVE)
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

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
CMAKE_ARGS+=	-DWITH_PNG:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_PNG:BOOL=Off
.endif

.if defined(WITH_PYTHON)
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_PYTHON=	yes
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

.if !defined(WITHOUT_TIFF)
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
CMAKE_ARGS+=	-DWITH_TIFF:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_TIFF:BOOL=Off
.endif

.if !defined(WITHOUT_V4L)
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
CMAKE_ARGS+=	-DWITH_V4L:BOOL=On \
		-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"
.else
CMAKE_ARGS+=	-DWITH_V4L:BOOL=Off
.endif

.if defined(WITH_XINE)
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
CMAKE_ARGS+=	-DWITH_XINE:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_XINE:BOOL=Off
.endif

CONFIGURE_WRKSRC=${WRKSRC}/build
BUILD_WRKSRC=${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=${BUILD_WRKSRC}

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
