# Created by: Randall Hopper <aa8vb@nc.rr.com>
# $FreeBSD$

PORTNAME=	osg
PORTVERSION=	3.3.9
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://trac.openscenegraph.org/downloads/developer_releases/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMESUFFIX=	-devel
DISTNAME=	OpenSceneGraph-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ OpenGL scene graph library for real-time rendering

LICENSE=	OSGPL
LICENSE_NAME=	OpenSceneGraph Public License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

CONFLICTS=	osg-[0-9]*

USES=		alias cmake:outsource jpeg pkgconfig zip
USE_GL=		gl glu
USE_XORG=	x11
USE_LDCONFIG=	yes

PLIST_SUB=	OSG_VERSION=${PORTVERSION} \
		OSG_SHLIBVER=123 \
		OPENTHREADS_VERSION=3.3.0 \
		OPENTHREADS_SHLIBVER=20

PORTSCOUT=	limitw:1,odd

OPTIONS_DEFINE=	CURL FFMPEG FREETYPE GDAL GIF GSTREAMER GTA INVENTOR \
		JASPER LIBLAS LUA NVTT OPENEXR PDF QT4 SDL \
		SVG VNC XINE XRANDR
OPTIONS_DEFAULT=FREETYPE GIF FFMPEG XRANDR

LIBLAS_DESC=	liblas support
GDAL_DESC=	GDAL support
INVENTOR_DESC=	SGI OpenInventor support
GTA_DESC=	GTA file format support
VNC_DESC=	LibVNCServer support
SDL_DESC=	Use SDL (joystick support in present3d)
NVTT_DESC=	Use NVidia texture tools
LUA_DESC=	Lua script engine support

OPTIONS_SUB=	yes

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
LIBLAS_LIB_DEPENDS=	liblas.so:devel/liblas
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
GDAL_LIB_DEPENDS=	libgdal.so:graphics/gdal
GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GSTREAMER_USE=		GNOME=glib20 GSTREAMER1=yes
INVENTOR_LIB_DEPENDS=	libInventor.so:graphics/inventor
JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
XINE_LIB_DEPENDS=	libxine.so:multimedia/libxine
GTA_LIB_DEPENDS=	libgta.so:devel/libgta
VNC_LIB_DEPENDS=	libvncserver.so:net/libvncserver
OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/OpenEXR
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
SVG_LIB_DEPENDS=	librsvg-2.so:graphics/librsvg2
PDF_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
SDL_USE=		SDL=sdl
NVTT_LIB_DEPENDS=	libnvtt.so:graphics/nvidia-texture-tools
XRANDR_CMAKE_ON=	-DOSGVIEWER_USE_XRANDR:BOOL=ON
XRANDR_CMAKE_OFF=	-DOSGVIEWER_USE_XRANDR:BOOL=OFF
QT4_USE=		QT4=corelib,gui,opengl,qmake_build,moc_build,uic_build,rcc_build
QT4_CMAKE_ON=		-DOSG_USE_QT=ON
QT4_CMAKE_OFF=		-DOSG_USE_QT=OFF
LUA_USES=		lua:52

.include <bsd.port.options.mk>

# GUI toolkits are only needed for building examples, which are not even installed
FORCE_IGNORE=	FLTK GLUT FOX Qt3 Qt5Widgets wxWidgets OpenAL GtkGl SDL2 # only for examples
FORCE_IGNORE+=	COLLADA Performer OurDCMTK XUL FBX           # not in ports
FORCE_IGNORE+=	OpenVRML                                     # ports version too old
FORCE_IGNORE+=	ITK                                          # ports version doesn't build on 10.x
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

.if ${PORT_OPTIONS:MXINE}
FORCE_REQUIRE+=	Xine
.else
FORCE_IGNORE+=	Xine
.endif

.if ${PORT_OPTIONS:MGTA}
FORCE_REQUIRE+=	GTA
.else
FORCE_IGNORE+=	GTA
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
.else
FORCE_IGNORE+=	SDL
.endif

.if ${PORT_OPTIONS:MNVTT}
FORCE_REQUIRE+=	NVTT
.else
FORCE_IGNORE+=	NVTT
.endif

.if ${PORT_OPTIONS:MLUA}
FORCE_REQUIRE+=	Lua51
.else
FORCE_IGNORE+=	Lua51
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
	@${REINPLACE_CMD} -e '/FIND_LIBRARY.*DL_LIBRARY/ d; \
		s|-pedantic||' ${WRKSRC}/CMakeLists.txt
.for p in ${FORCE_REQUIRE}
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*${p}/ s|)$$| REQUIRED&|' \
		${WRKSRC}/CMakeLists.txt
.endfor
.for p in ${FORCE_IGNORE}
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*${p}/ s|^|#|' \
		${WRKSRC}/CMakeLists.txt
.endfor

.include <bsd.port.mk>
