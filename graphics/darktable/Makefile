# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	darktable
PORTVERSION=	1.4.2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	Virtual lighttable and darkroom for photographers

LICENSE=	GPLv3

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libexiv2.so:${PORTSDIR}/graphics/exiv2 \
		liblensfun.so:${PORTSDIR}/graphics/lensfun \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libcurl.so:${PORTSDIR}/ftp/curl

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	uses SSE extensions

USES=		cmake:outsource pkgconfig tar:xz ninja desktop-file-utils
USE_GNOME=	librsvg2
USE_SQLITE=	yes
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	COLORD DOCS FB_PICASA FLICKR GEO GNOMEKEYRING GPHOTO	\
		GRAPHMAGICK LUA NLS OPENEXR OPENJPEG RAWSPEED SLIDESHOW	\
		SQUISH WEBP

GEO_DESC=	Support geotagging
FB_PICASA_DESC=	Support export to Facebook and Picasa
SQUISH_DESC=	Compress thumbnail via libsquish
RAWSPEED_DESC=	Compile with rawspeed backend
SLIDESHOW_DESC=	Build OpenGL/SDL slideshow viewer

OPTIONS_DEFAULT=COLORD FB_PICASA FLICKR GEO GPHOTO LUA NLS OPENEXR	\
		OPENJPEG RAWSPEED WEBP

CMAKE_ARGS+=	-DBINARY_PACKAGE_BUILD=1

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGPHOTO}
LIB_DEPENDS+=	libgphoto2.so:${PORTSDIR}/graphics/libgphoto2
PLIST_FILES+=	lib/darktable/plugins/lighttable/libcamera.so \
		lib/darktable/plugins/lighttable/libcapture.so \
		lib/darktable/plugins/lighttable/liblive_view.so \
		lib/darktable/views/libcapture.so
.else
CMAKE_ARGS+=	-DUSE_CAMERA_SUPPORT:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MGEO}
LIB_DEPENDS+=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup
PLIST_FILES+=	lib/darktable/plugins/lighttable/libgeotagging.so \
		lib/darktable/plugins/lighttable/liblocation.so \
		lib/darktable/plugins/lighttable/libmap_settings.so \
		lib/darktable/views/libmap.so
.else
CMAKE_ARGS+=	-DUSE_GEO:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MFLICKR}
LIB_DEPENDS+=	libflickcurl.so:${PORTSDIR}/www/flickcurl
PLIST_FILES+=	lib/darktable/plugins/imageio/storage/libflickr.so
.else
CMAKE_ARGS+=	-DUSE_FLICKR:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MFB_PICASA}
LIB_DEPENDS+=	libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib
PLIST_FILES+=	lib/darktable/plugins/imageio/storage/libfacebook.so \
		lib/darktable/plugins/imageio/storage/libpicasa.so
.else
CMAKE_ARGS+=	-DUSE_GLIBJSON:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MGNOMEKEYRING}
LIB_DEPENDS+=	libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring
.else
CMAKE_ARGS+=	-DUSE_GNOME_KEYRING:BOOL=OFF
.endif

.if ! ${PORT_OPTIONS:MRAWSPEED}
CMAKE_ARGS+=	-DDONT_USE_RAWSPEED:BOOL=ON
.endif

.if ${PORT_OPTIONS:MOPENEXR}
LIB_DEPENDS+=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR
PLIST_FILES+=	lib/darktable/plugins/imageio/format/libexr.so
.else
CMAKE_ARGS+=	-DUSE_OPENEXR:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MOPENJPEG}
LIB_DEPENDS+=	libopenjpeg.so:${PORTSDIR}/graphics/openjpeg15
PLIST_FILES+=	lib/darktable/plugins/imageio/format/libj2k.so
.else
CMAKE_ARGS+=	-DUSE_OPENJPEG:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MCOLORD}
# darktable 1.4 can use colord but provides its own libcolord,
# statically linked to libdarktable.so.
LIB_DEPENDS+=	libcolord.so:${PORTSDIR}/graphics/colord
.else
CMAKE_ARGS+=	-DUSE_COLORD:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MGRAPHMAGICK}
LIB_DEPENDS+=	libGraphicsMagick.so:${PORTSDIR}/graphics/GraphicsMagick13
.else
CMAKE_ARGS+=	-DUSE_GRAPHICSMAGICK:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MLUA}
USES+=		lua
PLIST_FILES+=	%%DATADIR%%/lua/darktable/debug.lua \
		%%DATADIR%%/luarc
.else
CMAKE_ARGS+=	-DUSE_LUA:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MSQUISH}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsquish.a:${PORTSDIR}/graphics/squish
.else
CMAKE_ARGS+=	-DUSE_SQUISH:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MSLIDESHOW}
USE_GL=		gl
USE_SDL=	sdl
PLIST_FILES+=	bin/darktable-viewer
.else
CMAKE_ARGS+=	-DBUILD_SLIDESHOW:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MWEBP}
LIB_DEPENDS+=	libwebp.so:${PORTSDIR}/graphics/webp
PLIST_FILES+=	lib/darktable/plugins/imageio/format/libwebp.so
.else
CMAKE_ARGS+=	-DUSE_WEBP:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
.else
CMAKE_ARGS+=	-DUSE_NLS:BOOL=OFF
.endif

.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,__APPLE__,__${OPSYS}__,' \
		${WRKSRC}/src/common/utility.c
# Do not install useless (to end-user) documentation; adjust manpages path
	@${REINPLACE_CMD} -e '/DOC_FILES/d ; s,share/man/man1,man/man1,' \
		${WRKSRC}/doc/CMakeLists.txt

post-install:
.if ! ${PORT_OPTIONS:MDOCS}
	@${RM} ${STAGEDIR}${DOCSDIR}/darktablerc.html
	@${RMDIR} ${STAGEDIR}${DOCSDIR}
.endif
.if ! ${PORT_OPTIONS:MRAWSPEED}
	@${REINPLACE_CMD} -e '/rawspeed/d' ${TMPPLIST}
.endif
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/LC_MESSAGES/d' ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
