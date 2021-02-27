# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	efl
DISTVERSION=	1.25.1
PORTREVISION=	5
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/libs/${PORTNAME}/
DIST_SUBDIR=	enlightenment

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Enlightenment Foundation Libraries

LICENSE=	BSD2CLAUSE LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	checkmk:devel/check
LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libdbus-1.so:devel/dbus \
		libcurl.so:ftp/curl \
		libsndfile.so:audio/libsndfile
RUN_DEPENDS=	update-mime-database:misc/shared-mime-info

# lib/libeio.so.1
CONFLICTS_INSTALL=	libeio

USES=		compiler:c++14-lang gettext-tools gnome iconv \
		jpeg libtool meson ninja ssl pathfix pkgconfig python:3.5+ shared-mime-info \
		shebangfix tar:xz xorg
SHEBANG_FILES=  src/tests/elementary/spec/generator.py \
		src/bin/exactness/exactness_play.in \
		src/bin/exactness/exactness_record.in
USE_XORG=	x11 xcb xcursor xcomposite xdamage xext xfixes xi xinerama \
		xrandr xrender xtst xscrnsaver
USE_LDCONFIG=	yes

MESON_ARGS=	-Dsystemd=false -Deeze=false

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes

PLIST_SUB=	BRANCHVERSION=${PORTVERSION:R} PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		AVAHI FRIBIDI HARFBUZZ NLS PHYSICS PULSEAUDIO SDL VNC EFLONE ELUA EXAMPLES DOXYGEN WAYLAND
OPTIONS_GROUP=		EMOTION INPUT LOADER BINDINGS
OPTIONS_GROUP_EMOTION=	GSTREAMER V4L
OPTIONS_GROUP_INPUT=	IBUS SCIM XIM
OPTIONS_GROUP_LOADER=	OPENJPEG PDF PS RAW SVG WEBP XCF AV1
OPTIONS_GROUP_BINDINGS=	LUA CXX
OPTIONS_GROUP_WAYLAND=	WAYLAND
OPTIONS_SINGLE=		CRYPTO ENGINE LUAL
OPTIONS_SINGLE_CRYPTO=	OPENSSL GNUTLS
OPTIONS_SINGLE_ENGINE=	OPENGL OPENGLES NONE
OPTIONS_SINGLE_LUAL=	LUAJIT LUALANG
OPTIONS_DEFAULT=	FRIBIDI HARFBUZZ PULSEAUDIO EXAMPLES GSTREAMER V4L SCIM XIM \
			OPENSSL OPENJPEG PDF PS RAW SVG WEBP XCF OPENGL LUAJIT CXX
OPTIONS_DEFAULT_aarch64=	LUALANG
OPTIONS_EXCLUDE_aarch64=	LUAJIT
OPTIONS_SUB=		yes

HARFBUZZ_DESC=		OpenType text shaping engine
PHYSICS_DESC=		Physics engine (bullet) - DEPRECATED UPSTREAM
EFLONE_DESC=		Create EFL-One library (single file library) - EXPERIMENTAL
ELUA_DESC=		Lua launcher binary support in efl
VNC_DESC=		VNC Server support
IBUS_DESC=		Intelligent Input Bus
SCIM_DESC=		Smart Common Input Method
XIM_DESC=		X Input Method
SVG_DESC=		Vector graphics support
XCF_DESC=		Gimp image format support
AV1_DESC=		AV1 image format support
LUAL_DESC=		LUA
LUALANG_DESC=		Use Lua
LUAJIT_DESC=		Use Luajit
OPENGLES_DESC=		2D/3D rendering support via OpenGL ES
NONE_DESC=		No acceleration, software only
LUA_DESC=		Lua Bindings
CXX_DESC=		C++ Bindings
EXAMPLES_DESC=		Build examples of using EFL

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_MESON_TRUE=	avahi

FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_MESON_TRUE=	fribidi

HARFBUZZ_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
HARFBUZZ_MESON_TRUE=	harfbuzz

NLS_USES=			gettext-runtime
NLS_MESON_TRUE=			nls

PHYSICS_LIB_DEPENDS=		libBulletDynamics.so:devel/bullet
PHYSICS_MESON_TRUE=		physics

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_MESON_TRUE=		pulseaudio

EFLONE_BROKEN_i386=		EFLONE option is broken on i386 by the upstream bug: https://phab.enlightenment.org/T8870
EFLONE_MESON_TRUE=		efl-one

ELUA_MESON_TRUE=		elua

EXAMPLES_MESON_TRUE=		build-examples

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
# PR 247427
DOXYGEN_PREVENTS=		OPENJPEG
DOXYGEN_PREVENTS_MSG=		devel/doxygen installs graphics/openjpeg15 which breaks build of all ports that depend on graphics/openjpeg

VNC_MESON_TRUE=			vnc-server
VNC_LIB_DEPENDS=		libvncserver.so:net/libvncserver

LUA_IMPLIES=			ELUA

WAYLAND_BUILD_DEPENDS=		wayland-protocols>=1.7:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=		libepoll-shim.so:devel/libepoll-shim \
		libxkbcommon.so:x11/libxkbcommon \
		libwayland-client.so:graphics/wayland \
		libwayland-cursor.so:graphics/wayland
WAYLAND_CFLAGS=			-I${LOCALBASE}/include/libepoll-shim
WAYLAND_LDFLAGS=		-lepoll-shim
WAYLAND_MESON_TRUE=		wl
WAYLAND_BROKEN=			Wayland bits compile but don't yet work at runtime

GSTREAMER_USE=			GSTREAMER1=core
GSTREAMER_MESON_TRUE=		gstreamer

V4L_BUILD_DEPENDS=		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_MESON_TRUE=			v4l2

IBUS_LIB_DEPENDS=		libibus-1.0.so:textproc/ibus
IBUS_USES=			gnome
IBUS_USE=			GNOME=glib20
IBUS_MESON_TRUE=		glib

SCIM_LIB_DEPENDS=		libscim-1.0.so:textproc/scim

OPENJPEG_LIB_DEPENDS=		libopenjp2.so:graphics/openjpeg
# PR 247427
OPENJPEG_PREVENTS=		DOXYGEN
OPENJPEG_PREVENTS_MSG=		devel/doxygen installs graphics/openjpeg15 which breaks build of all ports that depend on graphics/openjpeg

GNUTLS_LIB_DEPENDS=		libgcrypt.so:security/libgcrypt \
				libgnutls.so:security/gnutls
GNUTLS_MESON_ON=		-Dcrypto=gnutls
GNUTLS_MESON_OFF=		-Dcrypto=openssl
GNUTLS_CFLAGS=			-I${LOCALBASE}/include/gnutls/
GNUTLS_BROKEN=			GNUTLS option is broken by the upstream bug: https://phab.enlightenment.org/T8807

PDF_LIB_DEPENDS=		libpoppler.so:graphics/poppler

PS_LIB_DEPENDS=			libspectre.so:print/libspectre

RAW_LIB_DEPENDS=		libraw.so:graphics/libraw

SVG_USES=			gnome
SVG_USE=			GNOME=cairo GNOME=librsvg2

AV1_LIB_DEPENDS=		libavif.so:graphics/libavif
AV1_BROKEN=			AV1 option is broken actually (according to the information from upstream)

WEBP_LIB_DEPENDS=		libwebp.so:graphics/webp

LUAJIT_BUILD_DEPENDS=		luajit:lang/luajit
LUAJIT_RUN_DEPENDS=		luajit:lang/luajit
LUAJIT_MESON_ON=		-Dlua-interpreter=luajit
LUAJIT_PREVENTS=		LUALANG

LUALANG_USES=			lua:51,build,run
LUALANG_MESON_ON=		-Dlua-interpreter=lua
LUALANG_PREVENTS=		LUAJIT

OPENGL_USES=			gl
OPENGL_USE=			GL=gl
OPENGL_MESON_ON=		-Dopengl=full
OPENGL_PREVENTS=		OPENGLES NONE

OPENGLES_USES=			gl
OPENGLES_USE=			GL=glesv2
OPENGLES_MESON_ON=		-Dopengl=es-egl
OPENGLES_PREVENTS=		OPENGL NONE

NONE_MESON_ON=			-Dopengl=none
NONE_PREVENTS=			OPENGL OPENGLES

SDL_USES=			sdl
SDL_USE=			SDL=sdl2
SDL_MESON_TRUE=			sdl

.include <bsd.port.options.mk>

ECORE-IMF-LOADERS-DISABLER-BASE=	-Decore-imf-loaders-disabler=
ECORE-IMF-LOADERS-DISABLER:=		${ECORE-IMF-LOADERS-DISABLER-BASE}

.if empty(PORT_OPTIONS:MIBUS)
ECORE-IMF-LOADERS-DISABLER:=	"${ECORE-IMF-LOADERS-DISABLER-BASE}ibus"
.endif

.if empty(PORT_OPTIONS:MSCIM)
.if ${ECORE-IMF-LOADERS-DISABLER} != ${ECORE-IMF-LOADERS-DISABLER-BASE}
ECORE-IMF-LOADERS-DISABLER-BASE:=${ECORE-IMF-LOADERS-DISABLER}
ECORE-IMF-LOADERS-DISABLER:=	"${ECORE-IMF-LOADERS-DISABLER-BASE},scim"
.else
ECORE-IMF-LOADERS-DISABLER:=	"${ECORE-IMF-LOADERS-DISABLER-BASE}scim"
.endif
.endif

.if empty(PORT_OPTIONS:MXIM)
.if ${ECORE-IMF-LOADERS-DISABLER} != ${ECORE-IMF-LOADERS-DISABLER-BASE}
ECORE-IMF-LOADERS-DISABLER-BASE:=${ECORE-IMF-LOADERS-DISABLER}
ECORE-IMF-LOADERS-DISABLER:=	"${ECORE-IMF-LOADERS-DISABLER-BASE},xim"
.else
ECORE-IMF-LOADERS-DISABLER:=	"${ECORE-IMF-LOADERS-DISABLER-BASE}xim"
.endif
.endif

MESON_ARGS+=			${ECORE-IMF-LOADERS-DISABLER}

EVAS-LOADERS-DISABLER-BASE=	-Devas-loaders-disabler=
EVAS-LOADERS-DISABLER:=		${EVAS-LOADERS-DISABLER-BASE}

EVAS-LOADERS-DISABLER-BASE:=	${EVAS-LOADERS-DISABLER}
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE}json"

.if empty(PORT_OPTIONS:MOPENJPEG)
.if ${EVAS-LOADERS-DISABLER} != ${EVAS-LOADERS-DISABLER-BASE}
EVAS-LOADERS-DISABLER-BASE:=	${EVAS-LOADERS-DISABLER}
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE},jp2k"
.else
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE}jp2k"
.endif
.endif

.if empty(PORT_OPTIONS:MPDF)
.if ${EVAS-LOADERS-DISABLER} != ${EVAS-LOADERS-DISABLER-BASE}
EVAS-LOADERS-DISABLER-BASE:=	${EVAS-LOADERS-DISABLER}
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE},pdf"
.else
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE}pdf"
.endif
.endif

.if empty(PORT_OPTIONS:MPS)
.if ${EVAS-LOADERS-DISABLER} != ${EVAS-LOADERS-DISABLER-BASE}
EVAS-LOADERS-DISABLER-BASE:=	${EVAS-LOADERS-DISABLER}
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE},ps"
.else
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE}ps"
.endif
.endif

.if empty(PORT_OPTIONS:MRAW)
.if ${EVAS-LOADERS-DISABLER} != ${EVAS-LOADERS-DISABLER-BASE}
EVAS-LOADERS-DISABLER-BASE:=	${EVAS-LOADERS-DISABLER}
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE},raw"
.else
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE}raw"
.endif
.endif

.if empty(PORT_OPTIONS:MSVG)
.if ${EVAS-LOADERS-DISABLER} != ${EVAS-LOADERS-DISABLER-BASE}
EVAS-LOADERS-DISABLER-BASE:=	${EVAS-LOADERS-DISABLER}
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE},rsvg"
.else
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE}rsvg"
.endif
.endif

.if empty(PORT_OPTIONS:MWEBP)
.if ${EVAS-LOADERS-DISABLER} != ${EVAS-LOADERS-DISABLER-BASE}
EVAS-LOADERS-DISABLER-BASE:=	${EVAS-LOADERS-DISABLER}
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE},webp"
.else
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE}webp"
.endif
.endif

.if empty(PORT_OPTIONS:MXCF)
.if ${EVAS-LOADERS-DISABLER} != ${EVAS-LOADERS-DISABLER-BASE}
EVAS-LOADERS-DISABLER-BASE:=	${EVAS-LOADERS-DISABLER}
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE},xcf"
.else
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE}xcf"
.endif
.endif

.if empty(PORT_OPTIONS:MAV1)
.if ${EVAS-LOADERS-DISABLER} != ${EVAS-LOADERS-DISABLER-BASE}
EVAS-LOADERS-DISABLER-BASE:=	${EVAS-LOADERS-DISABLER}
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE},avif"
.else
EVAS-LOADERS-DISABLER:=		"${EVAS-LOADERS-DISABLER-BASE}avif"
.endif
.endif

MESON_ARGS+=			${EVAS-LOADERS-DISABLER}

# Work-around build failure, which is caused by subtle problem in lld and -as-needed flag
.if ${ARCH} == i386
MESON_ARGS+=	-Db_asneeded=false
.endif

.if ${PORT_OPTIONS:MLUA} && ${PORT_OPTIONS:MCXX}
EFL_BINDINGS=	-Dbindings=lua,cxx
.else
.if ${PORT_OPTIONS:MLUA}
EFL_BINDINGS=	-Dbindings=lua
.else
.if ${PORT_OPTIONS:MCXX}
EFL_BINDINGS=	-Dbindings=cxx
.endif
.endif
.endif

MESON_ARGS+=			${EFL_BINDINGS}

.if ${PORT_OPTIONS:MOPENGLES} && ${PORT_OPTIONS:MWAYLAND}
LIB_DEPENDS+=		libwayland-egl.so:graphics/wayland
MESON_ARGS+=		-Degl=true
USE_GL=			egl
.endif

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == powerpc64 || ${ARCH} == powerpc64le
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif

.if ${ARCH:Mpowerpc64*}
LUAJIT_BUILD_DEPENDS=		luajit:lang/luajit-openresty
LUAJIT_RUN_DEPENDS=		luajit:lang/luajit-openresty
.endif

post-install:
	#@${RM} -r ${STAGEDIR}${PREFIX}/share/gdb
	@for i in `${FIND} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/lib -type f`; do \
		if ${FILE} $$i | ${GREP} -q "not stripped"; then ${STRIP_CMD} $$i; fi; \
	done

post-stage:
	@${ECHO_CMD} "autogenerating plist";
	@cd ${STAGEDIR}${PREFIX} && ${FIND} * -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>
