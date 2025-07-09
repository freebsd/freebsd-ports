PORTNAME=	efl
DISTVERSION=	1.28.1
PORTREVISION=	3
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/libs/${PORTNAME}/
DIST_SUBDIR=	enlightenment

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Enlightenment Foundation Libraries
WWW=		https://docs.enlightenment.org/efl/current/

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

# lib/libeio.so.1
CONFLICTS_INSTALL=	libeio

USES=		compiler:c++14-lang gettext-tools gnome iconv \
		jpeg libtool localbase:ldflags meson ninja ssl pathfix pkgconfig \
		python shared-mime-info shebangfix tar:xz xorg
SHEBANG_FILES=	src/tests/elementary/spec/generator.py \
		src/bin/exactness/exactness_play.in \
		src/bin/exactness/exactness_record.in
USE_XORG=	x11 xcb xcursor xcomposite xdamage xext xfixes xi xinerama \
		xrandr xrender xtst xscrnsaver
USE_LDCONFIG=	yes

MESON_ARGS=	-Dsystemd=false -Deeze=false -Dinput=false

PLIST_SUB=	BRANCHVERSION=${PORTVERSION:R} PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		AVAHI FRIBIDI HARFBUZZ NLS PHYSICS PULSEAUDIO SDL VNC EFLONE ELUA EXAMPLES DOXYGEN WAYLAND
OPTIONS_GROUP=		EMOTION INPUT LOADER BINDINGS
OPTIONS_GROUP_EMOTION=	GSTREAMER V4L
OPTIONS_GROUP_INPUT=	IBUS SCIM XIM
OPTIONS_GROUP_LOADER=	OPENJPEG PDF PS RAW SVG WEBP XCF AVIF HEIF JXL
OPTIONS_GROUP_BINDINGS=	LUA CXX
OPTIONS_GROUP_WAYLAND=	WAYLAND
OPTIONS_SINGLE=		CRYPTO ENGINE LUAL
OPTIONS_SINGLE_ENGINE=	OPENGL OPENGLES NONE
OPTIONS_SINGLE_LUAL=	LUAJIT LUALANG
OPTIONS_DEFAULT=	FRIBIDI HARFBUZZ PULSEAUDIO EXAMPLES GSTREAMER V4L SCIM XIM \
			OPENSSL OPENJPEG PDF PS RAW SVG WEBP XCF OPENGLES LUAJIT CXX
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
JXL_DESC=		JPEG XL image format support
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

NLS_USES=		gettext-runtime
NLS_MESON_TRUE=		nls

PHYSICS_LIB_DEPENDS=	libBulletDynamics.so:devel/bullet
PHYSICS_MESON_TRUE=	physics

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_MESON_TRUE=	pulseaudio

EFLONE_BROKEN_i386=	EFLONE option is broken on i386 by the upstream bug: https://phab.enlightenment.org/T8870
EFLONE_MESON_TRUE=	efl-one

ELUA_MESON_TRUE=	elua

EXAMPLES_MESON_TRUE=	build-examples

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_MESON_TRUE=	docs

VNC_MESON_TRUE=		vnc-server
VNC_LIB_DEPENDS=	libvncserver.so:net/libvncserver

LUA_IMPLIES=		ELUA
LUA_VARS=		lua_binding=lua
CXX_VARS=		cxx_binding=cxx

WAYLAND_BUILD_DEPENDS=	wayland-protocols>=1.7:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
			libxkbcommon.so:x11/libxkbcommon \
			libwayland-client.so:graphics/wayland \
			libwayland-cursor.so:graphics/wayland
WAYLAND_CFLAGS=		-I${LOCALBASE}/include/libepoll-shim
WAYLAND_LDFLAGS=	-lepoll-shim
WAYLAND_MESON_TRUE=	wl
WAYLAND_BROKEN=		Wayland bits compile but don't yet work at runtime

GSTREAMER_USES=		gstreamer
GSTREAMER_USE=		GSTREAMER=core
GSTREAMER_MESON_TRUE=	gstreamer

V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_MESON_TRUE=		v4l2

IBUS_LIB_DEPENDS=	libibus-1.0.so:textproc/ibus
IBUS_USES=		gnome
IBUS_USE=		GNOME=glib20
IBUS_MESON_TRUE=	glib
IBUS_VARS_OFF=		ibus_disabler=ibus

SCIM_LIB_DEPENDS=	libscim-1.0.so:textproc/scim
SCIM_VARS_OFF=		scim_disabler=scim

XIM_VARS_OFF=		xim_disabler=xim

OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
OPENJPEG_VARS_OFF=	openjpeg_disabler=jp2k

PDF_LIB_DEPENDS=	libpoppler.so:graphics/poppler
PDF_VARS_OFF=		pdf_disabler=pdf

PS_LIB_DEPENDS=		libspectre.so:print/libspectre
PS_VARS_OFF=		ps_disabler=ps

RAW_LIB_DEPENDS=	libraw.so:graphics/libraw
RAW_VARS_OFF=		raw_disabler=raw

SVG_USES=		gnome
SVG_USE=		GNOME=cairo GNOME=librsvg2
SVG_VARS_OFF=		svg_disabler=rsvg

AVIF_LIB_DEPENDS=	libavif.so:graphics/libavif
AVIF_VARS_OFF=		avif_disabler=avif

HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_VARS_OFF=		heif_disabler=heif

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_VARS_OFF=		webp_disabler=webp

JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_VARS_OFF=		jxl_disabler=jxl

XCF_VARS_OFF=		xcf_disabler=xcf

LUAJIT_USES=		luajit
LUAJIT_MESON_ON=	-Dlua-interpreter=luajit
LUAJIT_PREVENTS=	LUALANG

LUALANG_USES=		lua:51,build,run
LUALANG_MESON_ON=	-Dlua-interpreter=lua
LUALANG_PREVENTS=	LUAJIT

OPENGL_USES=		gl
OPENGL_USE=		GL=gl
OPENGL_MESON_ON=	-Dopengl=full

OPENGLES_USES=		gl
OPENGLES_USE=		GL=glesv2
OPENGLES_MESON_ON=	-Dopengl=es-egl

NONE_MESON_ON=		-Dopengl=none

SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SDL_MESON_TRUE=		sdl

MESON_ARGS+=		-Dcrypto=openssl

IMF_DISABLERS=		${IBUS_DISABLER} ${SCIM_DISABLER} ${XIM_DISABLER}

MESON_ARGS+=		-Decore-imf-loaders-disabler="${IMF_DISABLERS:ts,}"

EVAS_DISABLERS=		json ${OPENJPEG_DISABLER} ${PDF_DISABLER} \
			${PS_DISABLER} ${RAW_DISABLER} ${SVG_DISABLER} \
			${AVIF_DISABLER} ${HEIF_DISABLER} ${WEBP_DISABLER} \
			${XCF_DISABLER} ${JXL_DISABLER}

MESON_ARGS+=		-Devas-loaders-disabler="${EVAS_DISABLERS:ts,}"

EFL_BINDINGS=		${LUA_BINDING} ${CXX_BINDING}

MESON_ARGS+=		-Dbindings="${EFL_BINDINGS:ts,}"

.include <bsd.port.options.mk>

# Work-around build failure, which is caused by subtle problem in lld and -as-needed flag
.if ${ARCH} == i386
MESON_ARGS+=	-Db_asneeded=false
.endif

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == powerpc || ${ARCH} == powerpc64 || ${ARCH} == powerpc64le
LIB_DEPENDS+=  libunwind.so:devel/libunwind
.endif

.if ${ARCH:Marmv?}
BUILD_DEPENDS+=	as:devel/binutils
CFLAGS+=	-no-integrated-as
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
