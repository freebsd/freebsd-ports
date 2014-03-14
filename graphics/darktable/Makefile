# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	darktable
PORTVERSION=	1.2.3
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Virtual lighttable and darkroom for photographers

LICENSE=	GPLv3

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libexiv2.so:${PORTSDIR}/graphics/exiv2 \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		liblensfun.so:${PORTSDIR}/graphics/lensfun \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libcurl.so:${PORTSDIR}/ftp/curl

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	uses SSE extensions

USES=		cmake:outsource pkgconfig
USE_XZ=		yes
USE_GNOME=	librsvg2
USE_SQLITE=	yes
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
INSTALLS_ICONS=	yes
MAN1=		${PORTNAME}.1
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	GPHOTO GEO FLICKR FACEBOOK KWALLET GNOMEKEYRING RAWSPEED \
		OPENJPEG SLIDESHOW NLS GCC

GEO_DESC=	Geotagging support
FACEBOOK_DESC=	Support images export to Facebook
RAWSPEED_DESC=	Compile with rawspeed backend
SLIDESHOW_DESC=	Build OpenGL/SDL slideshow viewer
GCC_DESC=	Build with modern GCC (better OpenMP support)

OPTIONS_DEFAULT=	GPHOTO RAWSPEED GCC

NO_STAGE=	yes
.include <bsd.port.options.mk>

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

.if ${PORT_OPTIONS:MFACEBOOK}
LIB_DEPENDS+=	libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib
PLIST_FILES+=	lib/darktable/plugins/imageio/storage/libfacebook.so
.else
CMAKE_ARGS+=	-DUSE_GLIBJSON:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MKWALLET}
LIB_DEPENDS+=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
.else
CMAKE_ARGS+=	-DUSE_KWALLET:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MGNOMEKEYRING}
LIB_DEPENDS+=	libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring
.else
CMAKE_ARGS+=	-DUSE_GNOME_KEYRING:BOOL=OFF
.endif

.if ! ${PORT_OPTIONS:MRAWSPEED}
CMAKE_ARGS+=	-DDONT_USE_RAWSPEED:BOOL=ON
.endif

.if ${PORT_OPTIONS:MOPENJPEG}
LIB_DEPENDS+=	libopenjpeg.so:${PORTSDIR}/graphics/openjpeg
PLIST_FILES+=	lib/darktable/plugins/imageio/format/libj2k.so
.else
CMAKE_ARGS+=	-DUSE_OPENJPEG:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MSLIDESHOW}
USE_GL=		gl
USE_SDL=	sdl
PLIST_FILES+=	bin/darktable-viewer
.else
CMAKE_ARGS+=	-DBUILD_SLIDESHOW:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
.else
CMAKE_ARGS+=	-DUSE_NLS:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MGCC}
USE_GCC=	yes
# libdarktable.so has parts written in C++ (built-in rawspeed and libraw)
# and is linked to GCC 4.6's libstdc++.  However CMake removes RPATH from
# this library, and libstdc++ from base (GCC 4.2.1) is pulled at runtime,
# preventing darktable from starting.
#
# To workaround this, link darktable executable with libstdc++ explicitly;
# it still has the RPATH and the correct libstdc++ is pulled.
LDFLAGS+=	-lstdc++
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,__APPLE__,__${OPSYS}__,' \
		${WRKSRC}/src/common/utility.c
# Do not install useless (to end-user) documentation; adjust manpages path
	@${REINPLACE_CMD} -e '/DOC_FILES/d ; s,share/man/man1,man/man1,' \
		${WRKSRC}/doc/CMakeLists.txt
# Respect CFLAGS for release builds; remove `-g' from common CFLAGS which
# are used for release builds as well
	@${REINPLACE_CMD} -e '/-O3/s,^,#, ; /-msse2/s, -g,,' \
		${WRKSRC}/src/CMakeLists.txt

post-install:
.if ! ${PORT_OPTIONS:MRAWSPEED}
	@${REINPLACE_CMD} -e '/rawspeed/d' ${TMPPLIST}
.endif
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/LC_MESSAGES/d' ${TMPPLIST}
.endif

.include <bsd.port.mk>
