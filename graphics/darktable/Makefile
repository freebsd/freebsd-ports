# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	darktable
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Virtual lighttable and darkroom for photographers

LICENSE=	GPLv3

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	exiv2:${PORTSDIR}/graphics/exiv2 \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		lensfun:${PORTSDIR}/graphics/lensfun \
		lcms2:${PORTSDIR}/graphics/lcms2 \
		curl:${PORTSDIR}/ftp/curl

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	uses SSE extensions

MAKE_JOBS_SAFE=	yes

USES=		cmake:outsource
USE_XZ=		yes
USE_GNOME=	librsvg2
USE_SQLITE=	yes
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
INSTALLS_ICONS=	yes
MAN1=		${PORTNAME}.1
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	GPHOTO GEO FLICKR FACEBOOK KWALLET GNOMEKEYRING RAWSPEED \
		OPENJPEG SLIDESHOW NLS GCC46

GEO_DESC=	Geotagging support
FACEBOOK_DESC=	Support images export to Facebook
RAWSPEED_DESC=	Compile with rawspeed backend
SLIDESHOW_DESC=	Build OpenGL/SDL slideshow viewer
GCC46_DESC=	Build with GCC 4.6+ (better OpenMP support)

OPTIONS_DEFAULT=	GPHOTO RAWSPEED GCC46

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGPHOTO}
LIB_DEPENDS+=	gphoto2:${PORTSDIR}/graphics/libgphoto2
PLIST_FILES+=	lib/darktable/plugins/lighttable/libcamera.so \
		lib/darktable/plugins/lighttable/libcapture.so \
		lib/darktable/plugins/lighttable/liblive_view.so \
		lib/darktable/views/libcapture.so
.else
CMAKE_ARGS+=	-DUSE_CAMERA_SUPPORT:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MGEO}
LIB_DEPENDS+=	soup-2.4:${PORTSDIR}/devel/libsoup
PLIST_FILES+=	lib/darktable/plugins/lighttable/liblocation.so \
		lib/darktable/plugins/lighttable/libmap_settings.so \
		lib/darktable/views/libmap.so
.else
CMAKE_ARGS+=	-DUSE_GEO:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MFLICKR}
LIB_DEPENDS+=	flickcurl:${PORTSDIR}/www/flickcurl
PLIST_FILES+=	lib/darktable/plugins/imageio/storage/libflickr.so
.else
CMAKE_ARGS+=	-DUSE_FLICKR:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MFACEBOOK}
LIB_DEPENDS+=	json-glib-1.0:${PORTSDIR}/devel/json-glib
PLIST_FILES+=	lib/darktable/plugins/imageio/storage/libfacebook.so
.else
CMAKE_ARGS+=	-DUSE_GLIBJSON:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MKWALLET}
LIB_DEPENDS+=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
.else
CMAKE_ARGS+=	-DUSE_KWALLET:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MGNOMEKEYRING}
LIB_DEPENDS+=	gnome-keyring:${PORTSDIR}/security/libgnome-keyring
.else
CMAKE_ARGS+=	-DUSE_GNOME_KEYRING:BOOL=OFF
.endif

.if ! ${PORT_OPTIONS:MRAWSPEED}
CMAKE_ARGS+=	-DDONT_USE_RAWSPEED:BOOL=ON
.endif

.if ${PORT_OPTIONS:MOPENJPEG}
LIB_DEPENDS+=	openjpeg:${PORTSDIR}/graphics/openjpeg
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

.if ${PORT_OPTIONS:MGCC46}
USE_GCC=	4.6+
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
	@${REINPLACE_CMD} -e '/stats_/s,uint64_t,unsigned long,' \
		${WRKSRC}/src/common/mipmap_cache.h
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
