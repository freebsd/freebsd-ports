# Created by: Randall Hopper <aa8vb@nc.rr.com>
# $FreeBSD$

PORTNAME=	osg
PORTVERSION=	3.6.4
DISTVERSIONPREFIX=	OpenSceneGraph-
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ OpenGL scene graph library for real-time rendering

LICENSE=	OSGPL
LICENSE_NAME=	OpenSceneGraph Public License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USE_GITHUB=	yes
GH_ACCOUNT=	openscenegraph
GH_PROJECT=	OpenSceneGraph

CONFLICTS_INSTALL=osg34-[0-9]*

USES=		alias cmake compiler:c11 jpeg gl pkgconfig xorg
USE_GL=		gl
USE_XORG=	x11
USE_LDCONFIG=	yes

PLIST_SUB=	OSG_VERSION=${PORTVERSION} \
		OSG_SHLIBVER=160 \
		OPENTHREADS_VERSION=3.3.1 \
		OPENTHREADS_SHLIBVER=21

OPTIONS_DEFINE=	CURL FFMPEG FREETYPE GDAL GIF GSTREAMER GTA \
		JASPER LIBLAS LUA NVTT OPENEXR PDF SDL ASIO \
		SVG VNC XRANDR XINERAMA FONTCONFIG DCMTK COLLADA
OPTIONS_DEFAULT=FFMPEG FREETYPE GIF XRANDR XINERAMA FONTCONFIG
OPTIONS_SUB=		yes

ASIO_DESC=		ASIO support (resthttp plugin)
GDAL_DESC=		GDAL support
GTA_DESC=		GTA file format support
LIBLAS_DESC=		liblas support
NVTT_DESC=		Use NVidia texture tools
SDL_DESC=		Use SDL (joystick support in present3d)
VNC_DESC=		LibVNCServer support
OPENCASCADE_DESC=	OpenCASCADE format support
DCMTK_DESC=		DICOM format support
COLLADA_DESC=		COLLADA (dae) format support

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_VARS=		FORCE_REQUIRE+=CURL
CURL_VARS_OFF=		FORCE_IGNORE+=CURL
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_VARS=		FORCE_REQUIRE+=FFmpeg
FFMPEG_VARS_OFF=	FORCE_IGNORE+=FFmpeg
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_VARS=		FORCE_REQUIRE+=Freetype
FREETYPE_VARS_OFF=	FORCE_IGNORE+=Freetype
FONTCONFIG_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
FONTCONFIG_CMAKE_BOOL=	OSG_TEXT_USE_FONTCONFIG
GDAL_LIB_DEPENDS=	libgdal.so:graphics/gdal
GDAL_VARS=		FORCE_REQUIRE+=GDAL
GDAL_VARS_OFF=		FORCE_IGNORE+=GDAL
GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_VARS=		FORCE_REQUIRE+=GIFLIB
GIF_VARS_OFF=		FORCE_IGNORE+=GIFLIB
GSTREAMER_USE=		GNOME=glib20 GSTREAMER1=yes
GSTREAMER_VARS=		FORCE_REQUIRE+="GStreamer GLIB"
GSTREAMER_VARS_OFF=	FORCE_IGNORE+="GStreamer GLIB"
GSTREAMER_BROKEN=	fails when linking gstreamer plugin, with error cannot find -lgstreamer-1.0
GTA_LIB_DEPENDS=	libgta.so:devel/libgta
GTA_VARS=		FORCE_REQUIRE+=GTA
GTA_VARS_OFF=		FORCE_IGNORE+=GTA
JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
JASPER_VARS=		FORCE_REQUIRE+=Jasper
JASPER_VARS_OFF=	FORCE_IGNORE+=Jasper
LIBLAS_LIB_DEPENDS=	liblas.so:devel/liblas
LIBLAS_VARS=		FORCE_REQUIRE+=LIBLAS
LIBLAS_VARS_OFF=	FORCE_IGNORE+=LIBLAS
LUA_USES=		lua:52
LUA_CMAKE_ON=		-DOSG_USE_LOCAL_LUA_SOURCE:BOOL=OFF
LUA_VARS=		FORCE_IGNORE+=Lua51 FORCE_REQUIRE+=Lua52
LUA_VARS_OFF=		FORCE_IGNORE+="Lua51 Lua52"
NVTT_LIB_DEPENDS=	libnvtt.so:graphics/nvidia-texture-tools
NVTT_VARS=		FORCE_REQUIRE+=NVTT
NVTT_VARS_OFF=		FORCE_IGNORE+=NVTT
OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/openexr
OPENEXR_VARS=		FORCE_REQUIRE+=OpenEXR
OPENEXR_VARS_OFF=	FORCE_IGNORE+=OpenEXR
PDF_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
PDF_USE=		GNOME=cairo
PDF_VARS=		FORCE_REQUIRE+=Poppler-glib
PDF_VARS_OFF=		FORCE_IGNORE+=Poppler-glib
SDL_USE=		SDL=sdl
SDL_VARS=		FORCE_REQUIRE+=SDL
SDL_VARS_OFF=		FORCE_IGNORE+=SDL
SVG_LIB_DEPENDS=	librsvg-2.so:graphics/librsvg2
SVG_USE=		GNOME=cairo
SVG_VARS=		FORCE_REQUIRE+=RSVG
SVG_VARS_OFF=		FORCE_IGNORE+=RSVG
VNC_LIB_DEPENDS=	libvncserver.so:net/libvncserver
VNC_VARS=		FORCE_REQUIRE+=LibVNCServer
VNC_VARS_OFF=		FORCE_IGNORE+=LibVNCServer
XRANDR_CMAKE_BOOL=	OSGVIEWER_USE_XRANDR
XRANDR_USE=		XORG=xrandr
XINERAMA_CMAKE_BOOL=	OSGVIEWER_USE_XINERAMA
XINERAMA_USE=		XORG=xinerama
#OPENCASCADE_LIB_DEPENDS=libTKBRep.so:cad/opencascade
#OPENCASCADE_VARS=	FORCE_REQUIRE+=OpenCascade
#OPENCASCADE_VARS_OFF=	FORCE_IGNORE+=OpenCascade
#OPENCASCADE_CMAKE_ARGS=	-DOPENCASCADE_LIBRARY_TYPE="Shared"
DCMTK_LIB_DEPENDS=	libdcmrt.so:graphics/dcmtk \
			libxml2.so:textproc/libxml2 \
			libicuuc.so:devel/icu
DCMTK_USES=		ssl
DCMTK_VARS=		FORCE_REQUIRE+=DCMTK
DCMTK_VARS_OFF=		FORCE_IGNORE+=DCMTK
#ILMBASE_LIB_DEPENDS=	${LOCALBASE}/lib/libImath.so:graphics/ilmbase
#ILMBASE_VARS=		FORCE_REQUIRE+=ilmbase
#ILMBASE_VARS_OFF=	FORCE_IGNORE+=ilmbase
COLLADA_LIB_DEPENDS=	libcollada-dom2.5-dp.so:devel/collada-dom \
			libboost_filesystem.so:devel/boost-libs
COLLADA_VARS=		FORCE_REQUIRE+=COLLADA
COLLADA_VARS_OFF=	FORCE_IGNORE+=COLLADA
ASIO_BUILD_DEPENDS=	${LOCALBASE}/include/asio.hpp:net/asio
ASIO_VARS=		FORCE_REQUIRE+=Asio
ASIO_VARS_OFF=		FORCE_IGNORE+=Asio

# GUI toolkits are only needed for building examples, which are not even installed
FORCE_IGNORE=	FLTK FOX wxWidgets GtkGl SDL2		# only for examples
FORCE_IGNORE+=	FBX Inventor				# not in ports
FORCE_IGNORE+=	ilmbase					# not used
FORCE_IGNORE+=	OpenCascade				# detection broken
FORCE_IGNORE+=	ZeroConf				# no avahi support yet
FORCE_REQUIRE=	Threads OpenGL X11 JPEG PNG TIFF ZLIB	# common & lightweight

.include <bsd.port.options.mk>

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
