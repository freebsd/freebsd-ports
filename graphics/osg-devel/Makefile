# Created by: Randall Hopper <aa8vb@nc.rr.com>
# $FreeBSD$

PORTNAME=	osg
PORTVERSION=	3.1.3
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.openscenegraph.org/downloads/developer_releases/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMESUFFIX=	-devel
DISTNAME=	OpenSceneGraph-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ OpenGL scene graph library for real-time rendering

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff

CONFLICTS=	osg-[0-9]*

USE_ZIP=	yes
USES=		cmake pkgconfig
USE_GL=		gl glu
USE_XORG=	x11
USE_LDCONFIG=	yes

PLIST_SUB=	OSG_VERSION=${PORTVERSION} \
		OSG_SHLIBVER=93 \
		OPENTHREADS_VERSION=2.6.0 \
		OPENTHREADS_SHLIBVER=12

PORTSCOUT=	limitw:1,odd

OPTIONS_DEFINE=	CURL FREETYPE GDAL GIF INVENTOR JASPER XINE ITK \
		VNC OPENEXR FFMPEG SVG PDF XRANDR SDL
GDAL_DESC=	GDAL support
INVENTOR_DESC=	SGI OpenInventor support
ITK_DESC=	InsightToolkit support
VNC_DESC=	LibVNCServer support
SDL_DESC=	Use SDL (joystick support in present3d)

OPTIONS_DEFAULT=	FREETYPE GIF XRANDR

# broken (openvrml from ports is too old)
#		OPENVRML "Support for OpenVRML"             off

NO_STAGE=	yes
.include <bsd.port.options.mk>

# GUI toolkits are only needed for building examples, which are not even installed
FORCE_IGNORE=	FLTK GLUT FOX Qt3 Qt4 wxWidgets OpenAL GtkGl # only for examples
FORCE_IGNORE+=	COLLADA Performer OurDCMTK XUL FBX GTA       # not in ports
FORCE_REQUIRE=	Threads OpenGL X11 JPEG PNG TIFF ZLIB        # common & lightweight

# options that affect FIND_PACKAGE
.if ${PORT_OPTIONS:MCURL}
FORCE_REQUIRE+=	CURL
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
PLIST_SUB+=	CURL=""
.else
FORCE_IGNORE+=	CURL
PLIST_SUB+=	CURL="@comment "
.endif

.if ${PORT_OPTIONS:MFREETYPE}
FORCE_REQUIRE+=	FreeType
LIB_DEPENDS+=	freetype:${PORTSDIR}/print/freetype2
PLIST_SUB+=	FREETYPE=""
.else
FORCE_IGNORE+=	FreeType
PLIST_SUB+=	FREETYPE="@comment "
.endif

.if ${PORT_OPTIONS:MGDAL}
FORCE_REQUIRE+=	GDAL
LIB_DEPENDS+=	gdal:${PORTSDIR}/graphics/gdal
PLIST_SUB+=	GDAL=""
.else
FORCE_IGNORE+=	GDAL
PLIST_SUB+=	GDAL="@comment "
.endif

.if ${PORT_OPTIONS:MGIF}
FORCE_REQUIRE+=	GIFLIB
LIB_DEPENDS+=	gif:${PORTSDIR}/graphics/giflib
PLIST_SUB+=	GIF=""
.else
FORCE_IGNORE+=	GIFLIB
PLIST_SUB+=	GIF="@comment "
.endif

.if ${PORT_OPTIONS:MINVENTOR}
FORCE_REQUIRE+=	Inventor
BUILD_DEPENDS+=	${LOCALBASE}/lib/libInventor.so:${PORTSDIR}/graphics/inventor
RUN_DEPENDS+=	${LOCALBASE}/lib/libInventor.so:${PORTSDIR}/graphics/inventor
PLIST_SUB+=	INVENTOR=""
.else
FORCE_IGNORE+=	Inventor
PLIST_SUB+=	INVENTOR="@comment "
.endif

.if ${PORT_OPTIONS:MJASPER}
FORCE_REQUIRE+=	Jasper
LIB_DEPENDS+=	jasper:${PORTSDIR}/graphics/jasper
PLIST_SUB+=	JASPER=""
.else
FORCE_IGNORE+=	Jasper
PLIST_SUB+=	JASPER="@comment "
.endif

#.if ${PORT_OPTIONS:MOPENVRML}
#FORCE_REQUIRE+=	OpenVRML
#LIB_DEPENDS+=	openvrml:${PORTSDIR}/www/openvrml
#PLIST_SUB+=	OPENVRML=""
#.else
FORCE_IGNORE+=	OpenVRML
PLIST_SUB+=	OPENVRML="@comment "
#.endif

.if ${PORT_OPTIONS:MXINE}
FORCE_REQUIRE+=	Xine
LIB_DEPENDS+=	xine:${PORTSDIR}/multimedia/libxine
PLIST_SUB+=	XINE=""
.else
FORCE_IGNORE+=	Xine
PLIST_SUB+=	XINE="@comment "
.endif

.if ${PORT_OPTIONS:MITK}
FORCE_REQUIRE+=	ITK
BUILD_DEPENDS+=	${LOCALBASE}/lib/InsightToolkit/UseITK.cmake:${PORTSDIR}/science/InsightToolkit
RUN_DEPENDS+=	${LOCALBASE}/lib/InsightToolkit/UseITK.cmake:${PORTSDIR}/science/InsightToolkit
PLIST_SUB+=	ITK=""
CXXFLAGS+=	-DVCL_CAN_STATIC_CONST_INIT_FLOAT=0
.else
FORCE_IGNORE+=	ITK
PLIST_SUB+=	ITK="@comment "
.endif

.if ${PORT_OPTIONS:MVNC}
FORCE_REQUIRE+=	LibVNCServer
LIB_DEPENDS+=	vncserver:${PORTSDIR}/net/libvncserver
PLIST_SUB+=	VNC=""
.else
FORCE_IGNORE+=	LibVNCServer
PLIST_SUB+=	VNC="@comment "
.endif

.if ${PORT_OPTIONS:MOPENEXR}
FORCE_REQUIRE+=	OpenEXR
LIB_DEPENDS+=	IlmImf:${PORTSDIR}/graphics/OpenEXR
PLIST_SUB+=	OPENEXR=""
.else
FORCE_IGNORE+=	OpenEXR
PLIST_SUB+=	OPENEXR="@comment "
.endif

.if ${PORT_OPTIONS:MFFMPEG}
FORCE_REQUIRE+=	FFmpeg
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	FFMPEG=""
.else
FORCE_IGNORE+=	FFmpeg
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if ${PORT_OPTIONS:MSDL}
FORCE_REQUIRE+=	SDL
USE_SDL=	sdl
.else
FORCE_IGNORE+=	SDL
.endif

# options that affect PKG_CHECK_MODULES
.if ${PORT_OPTIONS:MSVG}
FORCE_REQUIRE+=	RSVG
LIB_DEPENDS+=	rsvg-2:${PORTSDIR}/graphics/librsvg2
PLIST_SUB+=	SVG=""
.else
FORCE_IGNORE+=	RSVG
PLIST_SUB+=	SVG="@comment "
.endif

.if ${PORT_OPTIONS:MPDF}
FORCE_REQUIRE+=	Poppler-glib
LIB_DEPENDS+=	poppler-glib:${PORTSDIR}/graphics/poppler-glib
PLIST_SUB+=	PDF=""
.else
FORCE_IGNORE+=	Poppler-glib
PLIST_SUB+=	PDF="@comment "
.endif

.if ${PORT_OPTIONS:MSVG} || ${PORT_OPTIONS:MPDF}
LIB_DEPENDS+=	cairo:${PORTSDIR}/graphics/cairo
.endif

# other options
.if ${PORT_OPTIONS:MXRANDR}
CMAKE_ARGS+=	-DOSGVIEWER_USE_XRANDR:BOOL=ON
USE_XORG+=	xrandr
.else
CMAKE_ARGS+=	-DOSGVIEWER_USE_XRANDR:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MXRANDR}
CMAKE_ARGS+=	-DOSGVIEWER_USE_XRANDR:BOOL=ON
USE_XORG+=	xrandr
.else
CMAKE_ARGS+=	-DOSGVIEWER_USE_XRANDR:BOOL=OFF
.endif

post-patch:
	@${FIND} ${WRKSRC}/CMakeModules -type f -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g'
	@${REINPLACE_CMD} -e '/FIND_LIBRARY.*DL_LIBRARY/ d' \
		${WRKSRC}/CMakeLists.txt
.for p in ${FORCE_REQUIRE}
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*${p}/ s|)$$| REQUIRED&|' \
		${WRKSRC}/CMakeLists.txt
.endfor
.for p in ${FORCE_IGNORE}
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*${p}/ s|^|#|' \
		${WRKSRC}/CMakeLists.txt
.endfor

.include <bsd.port.mk>
