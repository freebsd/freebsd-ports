# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	efl
DISTVERSION=	1.20.7
PORTREVISION=	24
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/libs/${PORTNAME}/
DIST_SUBDIR=	enlightenment

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Enlightenment Foundation Libraries

LICENSE=	BSD2CLAUSE LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libdbus-1.so:devel/dbus \
		libsndfile.so:audio/libsndfile

# lib/libeio.so.1
CONFLICTS_INSTALL=	libeio

GNU_CONFIGURE=	yes
USES=		autoreconf compiler:c++14-lang gettext-tools gmake gnome iconv \
		jpeg libtool pathfix pkgconfig python:2.7,run shared-mime-info \
		shebangfix tar:xz xorg
SHEBANG_FILES=	src/scripts/eina/eina-bench-cmp
USE_XORG=	x11 xcb xcursor xcomposite xdamage xext xfixes xi xinerama \
		xrandr xrender xtst xscrnsaver
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-profile=release \
		--enable-multisense \
		--disable-systemd \
		--disable-elput \
		--disable-cserve \
		--enable-i-really-know-what-i-am-doing-and-that-this-will-probably-break-things-and-i-will-fix-them-myself-and-send-patches-abb
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes

PLIST_SUB=	BRANCHVERSION=${PORTVERSION:R} PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		AVAHI FRIBIDI HARFBUZZ NLS PHYSICS PULSEAUDIO SSL WAYLAND WAYLAND_EGL
OPTIONS_GROUP=		EMOTION INPUT LOADER
OPTIONS_GROUP_EMOTION=	GSTREAMER LIBXINE V4L VLC
OPTIONS_GROUP_INPUT=	IBUS SCIM
OPTIONS_GROUP_LOADER=	OPENJPEG PDF PS RAW SVG WEBP XCF
OPTIONS_RADIO=		ENGINE
OPTIONS_RADIO_ENGINE=	OPENGL OPENGLES SDL
OPTIONS_DEFAULT=	FRIBIDI HARFBUZZ PHYSICS PULSEAUDIO SSL GSTREAMER PDF SVG OPENGL
OPTIONS_SUB=		yes

HARFBUZZ_DESC=		OpenType text shaping engine
PHYSICS_DESC=		Physics effects
WAYLAND_DESC=		Wayland backend support
WAYLAND_EGL_DESC=	Wayland-EGL backend support
VLC_DESC=		Multimedia support by VLC
IBUS_DESC=		Intelligent Input Bus
SCIM_DESC=		Smart Common Input Method
XCF_DESC=		Gimp image format support
OPENGLES_DESC=		2D/3D rendering support via OpenGL ES

AVAHI_LIB_DEPENDS=		libavahi-client.so:net/avahi-app
AVAHI_CONFIGURE_ENABLE=		avahi

FRIBIDI_LIB_DEPENDS=		libfribidi.so:converters/fribidi
FRIBIDI_CONFIGURE_ENABLE=	fribidi

HARFBUZZ_LIB_DEPENDS=		libharfbuzz.so:print/harfbuzz
HARFBUZZ_CONFIGURE_ENABLE=	harfbuzz

NLS_USES=			gettext-runtime
NLS_CONFIGURE_ENABLE=		nls

PHYSICS_LIB_DEPENDS=		libBulletDynamics.so:devel/bullet
PHYSICS_CONFIGURE_ENABLE=	physics

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulseaudio

WAYLAND_BROKEN=			ERROR: epoll_create() is deprecated, use epoll_create1(EPOLL_CLOEXEC).
WAYLAND_BUILD_DEPENDS=		wayland-protocols>=1.7:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=		libepoll-shim.so:devel/libepoll-shim \
				libxkbcommon.so:x11/libxkbcommon \
				libwayland-client.so:graphics/wayland \
				libwayland-cursor.so:graphics/wayland
WAYLAND_CFLAGS=			-I${LOCALBASE}/include/libepoll-shim
WAYLAND_LDFLAGS=		-lepoll-shim
WAYLAND_CONFIGURE_ENABLE=	wayland

WAYLAND_EGL_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland
WAYLAND_EGL_CONFIGURE_ENABLE=	egl
WAYLAND_EGL_USE=		GL=egl
WAYLAND_EGL_IMPLIES=		WAYLAND OPENGLES

GSTREAMER_USE=			GSTREAMER1=core
GSTREAMER_CONFIGURE_ENABLE=	gstreamer1

LIBXINE_LIB_DEPENDS=		libxine.so:multimedia/libxine
LIBXINE_CONFIGURE_ENABLE=	xine

V4L_BUILD_DEPENDS=		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_CONFIGURE_ENABLE=		v4l2

VLC_LIB_DEPENDS=		libvlc.so:multimedia/vlc
VLC_CONFIGURE_WITH=		generic_vlc

IBUS_LIB_DEPENDS=		libibus-1.0.so:textproc/ibus

SCIM_LIB_DEPENDS=		libscim-1.0.so:textproc/scim
SCIM_CONFIGURE_ENABLE=		scim

OPENJPEG_LIB_DEPENDS=		libopenjpeg.so:graphics/openjpeg15
OPENJPEG_CONFIGURE_ENABLE=	image-loader-jp2k

PDF_LIB_DEPENDS=		libpoppler.so:graphics/poppler
PDF_CONFIGURE_ENABLE=		poppler

PS_LIB_DEPENDS=			libspectre.so:print/libspectre
PS_CONFIGURE_ENABLE=		spectre

RAW_LIB_DEPENDS=		libraw.so:graphics/libraw
RAW_CONFIGURE_ENABLE=		libraw

SVG_USE=			GNOME=cairo GNOME=librsvg2
SVG_CONFIGURE_ENABLE=		librsvg

WEBP_LIB_DEPENDS=		libwebp.so:graphics/webp
WEBP_CONFIGURE_ENABLE=		image-loader-webp

XCF_CONFIGURE_ENABLE=		xcf

OPENGL_USES=			gl
OPENGL_USE=			GL=gl

OPENGLES_USES=			gl
OPENGLES_USE=			GL=glesv2
OPENGLES_CONFIGURE_ON=		--with-opengl=es --enable-egl

SDL_USES=			sdl
SDL_USE=			SDL=sdl2
SDL_CONFIGURE_ENABLE=		sdl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
PLIST_SUB+=			AUDIO=""
.else
CONFIGURE_ARGS+=		--disable-pulseaudio
PLIST_SUB+=			AUDIO="@comment "
.endif

.if ${PORT_OPTIONS:MSSL}
USES+=				ssl
.else
CONFIGURE_ARGS+=		--with-crypto=none
.endif

.if ${PORT_OPTIONS:MIBUS}
CONFIGURE_ARGS+=		--with-glib=yes
.else
CONFIGURE_ARGS+=		--disable-ibus --with-glib=no
.endif

.if empty(PORT_OPTIONS:MOPENGL) && empty(PORT_OPTIONS:MOPENGLES)
CONFIGURE_ARGS+=		--with-opengl=none
.endif

# keep in sync with all platforms where libunwind is available
.if (${ARCH} == amd64 || ${ARCH} == i386)
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif

.if ${ARCH:Mpowerpc*} || ${ARCH} == "sparc64"
USES+=				lua
CONFIGURE_ARGS+=		--enable-lua-old
PLIST_SUB+=			ELUA="@comment "
.else
LIB_DEPENDS+=			libluajit-5.1.so:lang/luajit
PLIST_SUB+=			ELUA=""
.endif

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/gdb
	@for i in `${FIND} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/lib -type f`; do \
	    if ${FILE} $$i | ${GREP} -q "not stripped"; then ${STRIP_CMD} $$i; fi; \
	done
	# workaround for https://phab.enlightenment.org/T6783 : it leaves an empty directory
	@if [ -d ${STAGEDIR}${PREFIX}/lib/evas/utils -a -z "$$(ls -A ${STAGEDIR}${PREFIX}/lib/evas/utils)" ]; then \
	    ${RMDIR} ${STAGEDIR}${PREFIX}/lib/evas/utils; \
	fi

.include <bsd.port.mk>
