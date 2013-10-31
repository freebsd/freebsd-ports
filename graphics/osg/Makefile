# Created by: Randall Hopper <aa8vb@nc.rr.com>
# $FreeBSD$

PORTNAME=	osg
PORTVERSION=	3.0.1
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://www.openscenegraph.org/downloads/stable_releases/OpenSceneGraph-${PORTVERSION}/source/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	OpenSceneGraph-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ OpenGL scene graph library for real-time rendering

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

CONFLICTS=	osg-devel-[0-9]*

USE_ZIP=	yes
USES=		cmake pkgconfig
USE_GL=		gl glu
USE_XORG=	x11
USE_LDCONFIG=	yes

PLIST_SUB=	OSG_VERSION=${PORTVERSION} \
		OSG_SHLIBVER=80 \
		OPENTHREADS_VERSION=2.6.0 \
		OPENTHREADS_SHLIBVER=12

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	CURL FREETYPE GDAL GIF INVENTOR JASPER XINE ITK \
		VNC OPENEXR FFMPEG SVG PDF XRANDR SDL
OPTIONS_DEFAULT=FREETYPE GIF FFMPEG XRANDR

GDAL_DESC=	GDAL support
INVENTOR_DESC=	SGI OpenInventor support
ITK_DESC=	InsightToolkit support
VNC_DESC=	LibVNCServer support
SDL_DESC=	Use SDL (joystick support in present3d)

OPTIONS_SUB=	yes

CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
FREETYPE_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
GDAL_LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal
GIF_LIB_DEPENDS=	libgif.so:${PORTSDIR}/graphics/giflib
INVENTOR_LIB_DEPENDS=	libInventor.so:${PORTSDIR}/graphics/inventor
JASPER_LIB_DEPENDS=	libjasper.so:${PORTSDIR}/graphics/jasper
XINE_LIB_DEPENDS=	libxine.so:${PORTSDIR}/multimedia/libxine
ITK_BUILD_DEPENDS=	${LOCALBASE}/lib/InsightToolkit/UseITK.cmake:${PORTSDIR}/science/InsightToolkit
ITK_RUN_DEPENDS=	${LOCALBASE}/lib/InsightToolkit/UseITK.cmake:${PORTSDIR}/science/InsightToolkit
VNC_LIB_DEPENDS=	libvncserver.so:${PORTSDIR}/net/libvncserver
OPENEXR_LIB_DEPENDS=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR
FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
SVG_LIB_DEPENDS=	librsvg-2.so:${PORTSDIR}/graphics/librsvg2
PDF_LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib
XRANDR_CMAKE_ON=	-DOSGVIEWER_USE_XRANDR:BOOL=ON
XRANDR_CMAKE_OFF=	-DOSGVIEWER_USE_XRANDR:BOOL=OFF

.include <bsd.port.options.mk>

# GUI toolkits are only needed for building examples, which are not even installed
FORCE_IGNORE=	FLTK GLUT FOX Qt3 Qt4 wxWidgets OpenAL GtkGl # only for examples
FORCE_IGNORE+=	COLLADA Performer OurDCMTK XUL FBX           # not in ports
FORCE_REQUIRE=	Threads OpenGL X11 JPEG PNG TIFF ZLIB        # common & lightweight

# options that affect FIND_PACKAGE
.if ${PORT_OPTIONS:MCURL}
FORCE_REQUIRE+=	CURL
.else
FORCE_IGNORE+=	CURL
.endif

.if ${PORT_OPTIONS:MFREETYPE}
FORCE_REQUIRE+=	FreeType
.else
FORCE_IGNORE+=	FreeType
.endif

.if ${PORT_OPTIONS:MGDAL}
FORCE_REQUIRE+=	GDAL
.else
FORCE_IGNORE+=	GDAL
.endif

.if ${PORT_OPTIONS:MGIF}
FORCE_REQUIRE+=	GIFLIB
.else
FORCE_IGNORE+=	GIFLIB
.endif

.if ${PORT_OPTIONS:MINVENTOR}
FORCE_REQUIRE+=	Inventor
.else
FORCE_IGNORE+=	Inventor
.endif

.if ${PORT_OPTIONS:MJASPER}
FORCE_REQUIRE+=	Jasper
.else
FORCE_IGNORE+=	Jasper
.endif

# broken (openvrml from ports is too old)
FORCE_IGNORE+=	OpenVRML

.if ${PORT_OPTIONS:MXINE}
FORCE_REQUIRE+=	Xine
.else
FORCE_IGNORE+=	Xine
.endif

.if ${PORT_OPTIONS:MITK}
FORCE_REQUIRE+=	ITK
CXXFLAGS+=	-DVCL_CAN_STATIC_CONST_INIT_FLOAT=0
.else
FORCE_IGNORE+=	ITK
.endif

.if ${PORT_OPTIONS:MVNC}
FORCE_REQUIRE+=	LibVNCServer
.else
FORCE_IGNORE+=	LibVNCServer
.endif

.if ${PORT_OPTIONS:MOPENEXR}
FORCE_REQUIRE+=	OpenEXR
.else
FORCE_IGNORE+=	OpenEXR
.endif

.if ${PORT_OPTIONS:MFFMPEG}
FORCE_REQUIRE+=	FFmpeg
.else
FORCE_IGNORE+=	FFmpeg
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
.else
FORCE_IGNORE+=	RSVG
.endif

.if ${PORT_OPTIONS:MPDF}
FORCE_REQUIRE+=	Poppler-glib
.else
FORCE_IGNORE+=	Poppler-glib
.endif

.if ${PORT_OPTIONS:MSVG} || ${PORT_OPTIONS:MPDF}
USE_GNOME=	cairo
.endif

# other options
.if ${PORT_OPTIONS:MXRANDR}
USE_XORG+=	xrandr
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
