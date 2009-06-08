# New ports collection makefile for:	Open Scene Graph
# Date created:				26 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	osg
PORTVERSION=	2.9.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.openscenegraph.org/downloads/developer_releases/ \
		http://mirror.amdmi3.ru/
PKGNAMESUFFIX=	-devel
DISTNAME=	OpenSceneGraph-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ OpenGL scene graph library for real-time rendering

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

CONFLICTS=	osg-[0-9]*

USE_ZIP=	yes
USE_CMAKE=	yes
USE_GL=		gl glu
USE_GNOME=	pkgconfig
USE_XORG=	x11
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

PLIST_SUB=	OSG_VERSION=${PORTVERSION} \
		OSG_SHLIBVER=59 \
		OPENTHREADS_VERSION=2.4.0 \
		OPENTHREADS_SHLIBVER=11

PORTSCOUT=	limitw:1,odd

OPTIONS=	CURL     "Support for cURL"                 off \
		FREETYPE "Support for FreeType"             on \
		GDAL     "Support for GDAL"                 off \
		GIF      "Support for libungif"             on \
		INVENTOR "Support for SGI OpenInventor"     off \
		JASPER   "Support for JPEG2000"             off \
		XINE     "Support for Xine"                 off \
		ITK      "Support for InsightToolkit"       off \
		VNC      "Support for LibVNCServer"         off \
		OPENEXR  "Support for OpenEXR"              off \
		FFMPEG   "Support for FFmpeg"               off \
		SVG      "Support for SVG through librsvg2" off \
		PDF      "Support for PDF through poppler"  off \
		XRANDR   "Use Xrandr"                       on

# broken (openvrml from ports is too old)
#		OPENVRML "Support for OpenVRML"             off

.include <bsd.port.pre.mk>

# GUI toolkits are only needed for building examples, which are not even installed
FORCE_IGNORE=	FLTK GLUT SDL FOX Qt3 Qt4 wxWidgets OpenAL # only for examples
FORCE_IGNORE+=	COLLADA Performer OurDCMTK XUL        # not in ports
FORCE_REQUIRE=	Threads OpenGL X11 JPEG PNG TIFF ZLIB # common & lightweight
FORCE_PC_IGNORE=	GTK GTKGL                     # only for examples
FORCE_PC_REQUIRE=

# options that affect FIND_PACKAGE
.if defined(WITH_CURL)
FORCE_REQUIRE+=	CURL
LIB_DEPENDS+=	curl.5:${PORTSDIR}/ftp/curl
PLIST_SUB+=	CURL=""
.else
FORCE_IGNORE+=	CURL
PLIST_SUB+=	CURL="@comment "
.endif

.if !defined(WITHOUT_FREETYPE)
FORCE_REQUIRE+=	FreeType
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
PLIST_SUB+=	FREETYPE=""
.else
FORCE_IGNORE+=	FreeType
PLIST_SUB+=	FREETYPE="@comment "
.endif

.if defined(WITH_GDAL)
FORCE_REQUIRE+=	GDAL
LIB_DEPENDS+=	gdal.14:${PORTSDIR}/graphics/gdal
PLIST_SUB+=	GDAL=""
.else
FORCE_IGNORE+=	GDAL
PLIST_SUB+=	GDAL="@comment "
.endif

.if defined(WITH_GIF)
FORCE_REQUIRE+=	GIFLIB
LIB_DEPENDS+=	ungif.5:${PORTSDIR}/graphics/libungif
PLIST_SUB+=	GIF=""
.else
FORCE_IGNORE+=	GIFLIB
PLIST_SUB+=	GIF="@comment "
.endif

.if defined(WITH_INVENTOR)
FORCE_REQUIRE+=	Inventor
BUILD_DEPENDS+=	${LOCALBASE}/lib/libInventor.so:${PORTSDIR}/graphics/inventor
RUN_DEPENDS+=	${LOCALBASE}/lib/libInventor.so:${PORTSDIR}/graphics/inventor
PLIST_SUB+=	INVENTOR=""
.else
FORCE_IGNORE+=	Inventor
PLIST_SUB+=	INVENTOR="@comment "
.endif

.if defined(WITH_JASPER)
FORCE_REQUIRE+=	Jasper
LIB_DEPENDS+=	jasper.4:${PORTSDIR}/graphics/jasper
PLIST_SUB+=	JASPER=""
.else
FORCE_IGNORE+=	Jasper
PLIST_SUB+=	JASPER="@comment "
.endif

#.if defined(WITH_OPENVRML)
#FORCE_REQUIRE+=	OpenVRML
#LIB_DEPENDS+=	openvrml.8:${PORTSDIR}/www/openvrml
#PLIST_SUB+=	OPENVRML=""
#.else
FORCE_IGNORE+=	OpenVRML
PLIST_SUB+=	OPENVRML="@comment "
#.endif

.if defined(WITH_XINE)
FORCE_REQUIRE+=	Xine
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
PLIST_SUB+=	XINE=""
.else
FORCE_IGNORE+=	Xine
PLIST_SUB+=	XINE="@comment "
.endif

.if defined(WITH_ITK)
FORCE_REQUIRE+=	ITK
BUILD_DEPENDS+=	${LOCALBASE}/lib/InsightToolkit/UseITK.cmake:${PORTSDIR}/science/InsightToolkit
RUN_DEPENDS+=	${LOCALBASE}/lib/InsightToolkit/UseITK.cmake:${PORTSDIR}/science/InsightToolkit
PLIST_SUB+=	ITK=""
CXXFLAGS+=	-DVCL_CAN_STATIC_CONST_INIT_FLOAT=0
.else
FORCE_IGNORE+=	ITK
PLIST_SUB+=	ITK="@comment "
.endif

.if defined(WITH_VNC)
FORCE_REQUIRE+=	LibVNCServer
LIB_DEPENDS+=	vncserver.0:${PORTSDIR}/net/libvncserver
PLIST_SUB+=	VNC=""
.else
FORCE_IGNORE+=	LibVNCServer
PLIST_SUB+=	VNC="@comment "
.endif

.if defined(WITH_OPENEXR)
FORCE_REQUIRE+=	OpenEXR
LIB_DEPENDS+=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR
PLIST_SUB+=	OPENEXR=""
.else
FORCE_IGNORE+=	OpenEXR
PLIST_SUB+=	OPENEXR="@comment "
.endif

.if defined(WITH_FFMPEG)
FORCE_REQUIRE+=	FFmpeg
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	FFMPEG=""
.else
FORCE_IGNORE+=	FFmpeg
PLIST_SUB+=	FFMPEG="@comment "
.endif

# options that affect PKG_CHECK_MODULES
.if defined(WITH_SVG)
FORCE_PC_REQUIRE+=RSVG
LIB_DEPENDS+=	rsvg-2:${PORTSDIR}/graphics/librsvg2
PLIST_SUB+=	SVG=""
.else
FORCE_PC_IGNORE+=RSVG
PLIST_SUB+=	SVG="@comment "
.endif

.if defined(WITH_PDF)
FORCE_PC_REQUIRE+=POPPLER
LIB_DEPENDS+=	poppler-glib.4:${PORTSDIR}/graphics/poppler-gtk
PLIST_SUB+=	PDF=""
.else
FORCE_PC_IGNORE+=POPPLER
PLIST_SUB+=	PDF="@comment "
.endif

.if defined(WITH_SVG) || defined(WITH_PDF)
FORCE_PC_REQUIRE+=CAIRO
LIB_DEPENDS+=	cairo.2:${PORTSDIR}/graphics/cairo
.else
FORCE_PC_IGNORE+=CAIRO
.endif

# other options
.if defined(WITHOUT_XRANDR)
CMAKE_ARGS+=	-DOSGVIEWER_USE_XRANDR:BOOL=OFF
.else
CMAKE_ARGS+=	-DOSGVIEWER_USE_XRANDR:BOOL=ON
USE_XORG+=	xrandr
.endif

post-patch:
	@${FIND} ${WRKSRC}/CMakeModules -type f -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g'
.for p in ${FORCE_REQUIRE}
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*${p}/ s|)$$| REQUIRED&|' \
		${WRKSRC}/CMakeLists.txt
.endfor
.for p in ${FORCE_IGNORE}
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*${p}/ s|^|#|' \
		${WRKSRC}/CMakeLists.txt
.endfor
.for p in ${FORCE_PC_REQUIRE}
	@${REINPLACE_CMD} -e 's|PKG_CHECK_MODULES.*${p}|& REQUIRED| ' \
		${WRKSRC}/CMakeLists.txt
.endfor
.for p in ${FORCE_PC_IGNORE}
	@${REINPLACE_CMD} -e '/PKG_CHECK_MODULES.*${p}/ s|^|#|' \
		${WRKSRC}/CMakeLists.txt
.endfor

.include <bsd.port.post.mk>
