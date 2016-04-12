# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	efl
PORTVERSION=	1.16.1
PORTREVISION=	1
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/libs/${PORTNAME}/

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

DIST_SUBDIR=	enlightenment
GNU_CONFIGURE=	yes
USES=		autoreconf compiler:c++11-lib gettext-tools gmake jpeg libtool \
		pathfix pkgconfig shared-mime-info tar:xz
USE_XORG=	x11 xcursor xcomposite xdamage xext xinerama xp xrandr xtst xscrnsaver
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-profile=release \
		--enable-i-really-know-what-i-am-doing-and-that-this-will-probably-break-things-and-i-will-fix-them-myself-and-send-patches-aba
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	BRANCHVERSION=${PORTVERSION:R} PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		AVAHI FRIBIDI HARFBUZZ NLS NVIDIA PHYSICS PULSEAUDIO SSL
OPTIONS_GROUP=		EMOTION INPUT LOADER
OPTIONS_GROUP_EMOTION=	GSTREAMER LIBXINE V4L
OPTIONS_GROUP_INPUT=	IBUS SCIM
OPTIONS_GROUP_LOADER=	OPENJPEG WEBP
OPTIONS_RADIO=		ENGINE
OPTIONS_RADIO_ENGINE=	OPENGL SDL
OPTIONS_DEFAULT=	FRIBIDI HARFBUZZ PHYSICS SSL GSTREAMER OPENGL
OPTIONS_SUB=		yes

HARFBUZZ_DESC=		OpenType text shaping engine
NVIDIA_DESC=		Apply Nvidia workaround
PHYSICS_DESC=		Physics effects
IBUS_DESC=		Intelligent Input Bus
SCIM_DESC=		Smart Common Input Method

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

GSTREAMER_USE=			GSTREAMER1=core
GSTREAMER_CONFIGURE_ENABLE=	gstreamer1

LIBXINE_LIB_DEPENDS=		libxine.so:multimedia/libxine
LIBXINE_CONFIGURE_ENABLE=	xine

V4L_BUILD_DEPENDS=		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_CONFIGURE_ENABLE=		v4l2

IBUS_LIB_DEPENDS=		libibus-1.0.so:textproc/ibus

SCIM_LIB_DEPENDS=		libscim-1.0.so:textproc/scim
SCIM_CONFIGURE_ENABLE=		scim

OPENJPEG_LIB_DEPENDS=		libopenjpeg.so:graphics/openjpeg15
OPENJPEG_CONFIGURE_ENABLE=	image-loader-jp2k

WEBP_LIB_DEPENDS=		libwebp.so:graphics/webp
WEBP_CONFIGURE_ENABLE=		image-loader-webp

OPENGL_USE=			GL=gl

SDL_USE=			SDL=sdl2
SDL_CONFIGURE_ENABLE=		sdl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNVIDIA}
EXTRA_PATCHES+=			${FILESDIR}/extra-patch-src-lib-ecore_x-ecore_x_vsync_tool.c
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
PLIST_SUB+=			AUDIO=""
.else
CONFIGURE_ARGS+=		--disable-audio
PLIST_SUB+=			AUDIO="@comment "
.endif

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=			yes
WITH_OPENSSL_PORT=		yes
.else
CONFIGURE_ARGS+=		--with-crypto=none
.endif

.if ${PORT_OPTIONS:MGSTREAMER} || ${PORT_OPTIONS:MLIBXINE} || ${PORT_OPTIONS:MV4L}
PLIST_SUB+=			EMOTION=""
.else
PLIST_SUB+=			EMOTION="@comment "
.endif

.if ${PORT_OPTIONS:MIBUS}
CONFIGURE_ARGS+=		--with-glib=yes
.else
CONFIGURE_ARGS+=		--disable-ibus --with-glib=no
.endif

.if empty(PORT_OPTIONS:MOPENGL)
CONFIGURE_ARGS+=		--with-opengl=none
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
USES+=				lua
CONFIGURE_ARGS+=		--enable-lua-old
PLIST_SUB+=			ELUA="@comment "
.else
LIB_DEPENDS+=			libluajit-5.1.so:lang/luajit
PLIST_SUB+=			ELUA=""
.endif

pre-patch:
	@${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am

post-stage:
	${RM} -rf ${STAGEDIR}${PREFIX}/share/gdb
	for i in `${FIND} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/lib -type f`; do \
	    if ${FILE} $$i | ${GREP} -q "not stripped"; then ${STRIP_CMD} $$i; fi; \
	done

.include <bsd.port.mk>
