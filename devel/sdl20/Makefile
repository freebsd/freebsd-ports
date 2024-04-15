PORTNAME=	sdl2
DISTVERSION=	2.30.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libsdl-org/SDL/releases/download/release-${DISTVERSION}/ \
		https://www.libsdl.org/release/
DISTNAME=	SDL2-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform multimedia development API
WWW=		https://www.libsdl.org/ \
		https://github.com/libsdl-org/SDL

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

GNU_CONFIGURE=	yes
USES=		gmake iconv libtool localbase:ldflags pathfix pkgconfig
USE_CSTD=	c99
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-arts \
		--disable-esd \
		--disable-rpath
.if defined(MACHINE_CPU) && ${MACHINE_CPU:Mmmx}
CONFIGURE_ARGS+=	--enable-mmx
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif
.if defined(MACHINE_CPU) && ${MACHINE_CPU:M3dnow}
CONFIGURE_ARGS+=	--enable-3dnow
.else
CONFIGURE_ARGS+=	--disable-3dnow
.endif
.if defined(MACHINE_CPU) && ${MACHINE_CPU:Msse}
CONFIGURE_ARGS+=	--enable-sse
.else
CONFIGURE_ARGS+=	--disable-sse
.endif
.if defined(MACHINE_CPU) && ${MACHINE_CPU:Msse2}
CONFIGURE_ARGS+=	--enable-sse2
.else
CONFIGURE_ARGS+=	--disable-sse2
.endif
.if defined(MACHINE_CPU) && ${MACHINE_CPU:Msse3}
CONFIGURE_ARGS+=	--enable-sse3
.else
CONFIGURE_ARGS+=	--disable-sse3
.endif

MAKE_ENV=	V=1

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		ASM CSD DBUS FCITX IBUS JOYSTICK HIDAPI \
			SAMPLERATE UDEV
OPTIONS_GROUP=		AUDIO VIDEO
OPTIONS_GROUP_AUDIO=	ALSA JACK NAS OSS PIPEWIRE PULSEAUDIO SNDIO
OPTIONS_GROUP_VIDEO=	KMSDRM OPENGL OPENGLES1 OPENGLES2 VULKAN \
			WAYLAND X11
OPTIONS_DEFAULT=	ASM JOYSTICK OSS KMSDRM OPENGL \
			OPENGLES1 OPENGLES2 VULKAN WAYLAND X11
OPTIONS_DEFINE_powerpc=	ALTIVEC
OPTIONS_DEFINE_powerpc64=	ALTIVEC
OPTIONS_DEFAULT_powerpc=	ALTIVEC
OPTIONS_DEFAULT_powerpc64=	ALTIVEC

AUDIO_DESC=		Audio drivers
VIDEO_DESC=		Video drivers

CSD_DESC=		Client-side decorations for Wayland via libdecor
FCITX_DESC=		fcitx support
HIDAPI_DESC=		Use HIDAPI for low level joystick drivers
IBUS_DESC=		IBus support
JOYSTICK_DESC=		Joystick and haptic support
KMSDRM_DESC=		KMSDRM display support
OPENGLES1_DESC=		OpenGL ES 1.x rendering support
OPENGLES2_DESC=		OpenGL ES 2.x rendering support
UDEV_DESC=		Use udev for input device detection
VULKAN_DESC=		Vulkan rendering support

ALSA_CONFIGURE_ENABLE=		alsa alsa-shared
ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib

ALTIVEC_CONFIGURE_ENABLE=	altivec

ASM_CONFIGURE_ENABLE=		assembly

CSD_CONFIGURE_ENABLE=		libdecor libdecor-shared
CSD_LIB_DEPENDS=		libdecor-0.so:x11-toolkits/libdecor
CSD_IMPLIES=			WAYLAND

DBUS_LIB_DEPENDS=		libdbus-1.so:devel/dbus
DBUS_CONFIGURE_ENABLE=		dbus

FCITX_LIB_DEPENDS=		libfcitx-config.so:chinese/fcitx
FCITX_CONFIGURE_ENABLE=		fcitx
FCITX_IMPLIES=			DBUS

HIDAPI_CONFIGURE_ENABLE=	hidapi
HIDAPI_IMPLIES=			JOYSTICK

IBUS_LIB_DEPENDS=		libibus-1.0.so:textproc/ibus
IBUS_CONFIGURE_ENABLE=		ibus
IBUS_IMPLIES=			DBUS

JACK_CONFIGURE_ENABLE=		jack jack-shared
JACK_LIB_DEPENDS=		libjack.so:audio/jack

JOYSTICK_CONFIGURE_ENABLE=	joystick haptic
JOYSTICK_BUILD_DEPENDS=		${LOCALBASE}/include/linux/input.h:devel/evdev-proto
JOYSTICK_LIB_DEPENDS=		libinotify.so:devel/libinotify

KMSDRM_CONFIGURE_ENABLE=	video-kmsdrm kmsdrm-shared
KMSDRM_USES=			gl
KMSDRM_USE=	 		GL=gbm

NAS_CONFIGURE_ENABLE=		nas nas-shared
NAS_LIB_DEPENDS=		libaudio.so:audio/nas

OPENGL_CONFIGURE_ENABLE=	video-opengl
OPENGL_USES=			gl
OPENGL_USE=			GL=opengl

OPENGLES1_CONFIGURE_ENABLE=	video-opengles1
OPENGLES1_USES=			gl
OPENGLES1_USE=			GL=egl,glesv1
OPENGLES1_IMPLIES=		OPENGLES

OPENGLES2_CONFIGURE_ENABLE=	video-opengles2
OPENGLES2_USES=			gl
OPENGLES2_USE=			GL=egl,glesv2
OPENGLES2_IMPLIES=		OPENGLES

OSS_CONFIGURE_ENABLE=		oss

PIPEWIRE_CONFIGURE_ENABLE=	pipewire pipewire-shared
PIPEWIRE_LIB_DEPENDS=		libpipewire-0.3.so:multimedia/pipewire

PULSEAUDIO_CONFIGURE_ENABLE=	pulseaudio pulseaudio-shared
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

SAMPLERATE_CONFIGURE_ENABLE=	libsamplerate libsamplerate-shared
SAMPLERATE_LIB_DEPENDS=		libsamplerate.so:audio/libsamplerate

SNDIO_CONFIGURE_ENABLE=		sndio sndio-shared
SNDIO_LIB_DEPENDS=		libsndio.so:audio/sndio

UDEV_CONFIGURE_ENABLE=		libudev
UDEV_LIB_DEPENDS=		libudev.so:devel/libudev-devd
UDEV_BUILD_DEPENDS=		${LOCALBASE}/include/linux/input.h:devel/evdev-proto

VULKAN_CONFIGURE_ENABLE=	video-vulkan
VULKAN_LIB_DEPENDS=		libvulkan.so:graphics/vulkan-loader

WAYLAND_CONFIGURE_ENABLE=	video-wayland wayland-shared video-wayland-qt-touch
WAYLAND_BUILD_DEPENDS=		wayland-protocols>0:graphics/wayland-protocols \
				${LOCALBASE}/include/linux/input.h:devel/evdev-proto
WAYLAND_LIB_DEPENDS=		libwayland-egl.so:graphics/wayland \
				libxkbcommon.so:x11/libxkbcommon
WAYLAND_IMPLIES=		OPENGLES2

X11_CONFIGURE_ENABLE=		video-x11 x11-shared \
				video-x11-xcursor \
				video-x11-xdbe \
				video-x11-xinput \
				video-x11-xfixes \
				video-x11-xrandr \
				video-x11-scrnsaver \
				video-x11-xshape
X11_USES=			xorg
X11_USE=			XORG=xcursor,xext,xi,xfixes,xrandr,xscrnsaver

.include <bsd.port.options.mk>

# Similar to x11/pixman
.if ${ARCH} == "armv6" || ${ARCH} == "armv7"
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
CFLAGS+=	-B${LOCALBASE}/bin -no-integrated-as
.endif

.include <bsd.port.pre.mk>

.if !empty(ICONV_LIB)
CONFIGURE_ARGS+=	ac_cv_lib_iconv_iconv_open=yes ac_cv_func_iconv=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-liconv/${ICONV_LIB}/g' ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libSDL2.so

.include <bsd.port.post.mk>
