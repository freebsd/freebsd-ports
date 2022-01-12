PORTNAME=	sdl2
DISTVERSION=	2.0.20
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://www.libsdl.org/release/
DISTNAME=	SDL2-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform multimedia development API

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

OPTIONS_DEFINE=		ASM DBUS FCITX IBUS HIDAPI PTHREADS SAMPLERATE	\
			UDEV
OPTIONS_GROUP=		AUDIO VIDEO SUBSYSTEM
OPTIONS_GROUP_AUDIO=	ALSA JACK NAS OSS PIPEWIRE PULSEAUDIO SNDIO
OPTIONS_GROUP_VIDEO=	KMSDRM OPENGL OPENGLES1 OPENGLES2 VULKAN 	\
			WAYLAND X11
OPTIONS_GROUP_SUBSYSTEM=SDL_ATOMIC SDL_AUDIO SDL_CPUINFO SDL_EVENTS 	\
			SDL_FILE SDL_HAPTIC SDL_JOYSTICK SDL_LOADSO	\
			SDL_POWER SDL_RENDER SDL_THREADS SDL_TIMERS	\
			SDL_VIDEO
OPTIONS_DEFAULT=	ASM OSS PTHREADS SDL_ATOMIC SDL_AUDIO		\
			SDL_CPUINFO SDL_EVENTS SDL_FILE SDL_HAPTIC	\
			SDL_JOYSTICK SDL_LOADSO SDL_POWER SDL_RENDER	\
			SDL_THREADS SDL_TIMERS SDL_VIDEO KMSDRM	OPENGL 	\
			OPENGLES1 OPENGLES2 VULKAN WAYLAND X11
OPTIONS_DEFINE_powerpc=	ALTIVEC
OPTIONS_DEFINE_powerpc64=	ALTIVEC
OPTIONS_DEFAULT_powerpc=	ALTIVEC
OPTIONS_DEFAULT_powerpc64=	ALTIVEC

AUDIO_DESC=		Audio drivers
VIDEO_DESC=		Video drivers
SUBSYSTEM_DESC=		SDL subsystems support

HIDAPI_DESC=		Use HIDAPI for low level joystick drivers
PIPEWIRE_DESC=		Pipewire sound server support
PTHREADS_DESC=		Use POSIX threads for multi-threading
SDL_ATOMIC_DESC=	Enable the SDL Atomic subsystem
SDL_AUDIO_DESC=		Enable the SDL Audio subsystem
SDL_CPUINFO_DESC=	Enable the SDL CPUinfo subsystem
SDL_EVENTS_DESC=	Enable the SDL Events subsystem
SDL_FILE_DESC=		Enable the SDL File subsystem
SDL_HAPTIC_DESC=	Enable the SDL Haptic subsystem
SDL_JOYSTICK_DESC=	Enable the SDL Joystick subsystem
SDL_LOADSO_DESC=	Enable the SDL Loadso subsystem
SDL_POWER_DESC=		Enable the SDL Power subsystem
SDL_RENDER_DESC=	Enable the SDL Render subsystem
SDL_THREADS_DESC=	Enable the SDL Threads subsystem
SDL_TIMERS_DESC=	Enable the SDL Timers subsystem
SDL_VIDEO_DESC=		Enable the SDL Video subsystem
UDEV_DESC=		Use udev for input device detection
KMSDRM_DESC=		KMSDRM display support
OPENGL_DESC=		OpenGL rendering support
OPENGLES1_DESC=		OpenGL ES 1.x rendering support
OPENGLES2_DESC=		OpenGL ES 2.x rendering support
VULKAN_DESC=		Vulkan rendering support
WAYLAND_DESC=		Wayland display support
X11_DESC=		X11 display support
IBUS_DESC=		IBus support
FCITX_DESC=		fcitx support

ALTIVEC_CONFIGURE_ENABLE=	altivec
ALSA_CONFIGURE_ENABLE=		alsa alsa-shared
ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSA_IMPLIES=			SDL_AUDIO
ASM_CONFIGURE_ENABLE=		assembly
HIDAPI_CONFIGURE_ENABLE=	hidapi
HIDAPI_IMPLIES=			SDL_JOYSTICK
JACK_CONFIGURE_ENABLE=		jack jack-shared
JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_IMPLIES=			SDL_AUDIO
NAS_CONFIGURE_ENABLE=		nas nas-shared
NAS_LIB_DEPENDS=		libaudio.so:audio/nas
NAS_IMPLIES=			SDL_AUDIO
OSS_CONFIGURE_ENABLE=		oss
OSS_IMPLIES=			SDL_AUDIO
PIPEWIRE_CONFIGURE_ENABLE=	pipewire pipewire-shared
PIPEWIRE_LIB_DEPENDS=		libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_IMPLIES=		SDL_AUDIO
PTHREADS_CONFIGURE_ENABLE=	pthreads pthread-sem
PULSEAUDIO_CONFIGURE_ENABLE=	pulseaudio pulseaudio-shared
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_IMPLIES=		SDL_AUDIO
SAMPLERATE_CONFIGURE_ENABLE=	libsamplerate libsamplerate-shared
SAMPLERATE_LIB_DEPENDS=		libsamplerate.so:audio/libsamplerate
SDL_ATOMIC_CONFIGURE_ENABLE=	atomic gcc-atomics
SDL_AUDIO_CONFIGURE_ENABLE=	audio
SDL_CPUINFO_CONFIGURE_ENABLE=	cpuinfo
SDL_EVENTS_CONFIGURE_ENABLE=	events
SDL_FILE_CONFIGURE_ENABLE=	filesystem
SDL_HAPTIC_CONFIGURE_ENABLE=	haptic
SDL_JOYSTICK_CONFIGURE_ENABLE=	joystick
SDL_JOYSTICK_BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
SDL_JOYSTICK_LIB_DEPENDS=	libinotify.so:devel/libinotify
SDL_LOADSO_CONFIGURE_ENABLE=	loadso
SDL_POWER_CONFIGURE_ENABLE=	power
SDL_RENDER_CONFIGURE_ENABLE=	render
SDL_THREADS_CONFIGURE_ENABLE=	threads
SDL_TIMERS_CONFIGURE_ENABLE=	timers
SDL_VIDEO_CONFIGURE_ENABLE=	video
SNDIO_CONFIGURE_ENABLE=		sndio sndio-shared
SNDIO_LIB_DEPENDS=		libsndio.so:audio/sndio
SNDIO_IMPLIES=			SDL_AUDIO
UDEV_CONFIGURE_ENABLE=		libudev
UDEV_LIB_DEPENDS=		libudev.so:devel/libudev-devd
UDEV_BUILD_DEPENDS=		${LOCALBASE}/include/linux/input.h:devel/evdev-proto
KMSDRM_CONFIGURE_ENABLE=	video-kmsdrm kmsdrm-shared
KMSDRM_USES=			gl
KMSDRM_USE=	 		GL=gbm
KMSDRM_IMPLIES=			SDL_VIDEO
OPENGL_CONFIGURE_ENABLE=	video-opengl
OPENGL_USES=			gl
OPENGL_USE=			GL=opengl
OPENGL_IMPLIES=			SDL_VIDEO
OPENGLES1_CONFIGURE_ENABLE=	video-opengles1
OPENGLES1_USES=			gl
OPENGLES1_USE=			GL=egl,glesv1
OPENGLES1_IMPLIES=		SDL_VIDEO OPENGLES
OPENGLES2_CONFIGURE_ENABLE=	video-opengles2
OPENGLES2_USES=			gl
OPENGLES2_USE=			GL=egl,glesv2
OPENGLES2_IMPLIES=		SDL_VIDEO OPENGLES
VULKAN_CONFIGURE_ENABLE=	video-vulkan
VULKAN_IMPLIES=			SDL_LOADSO SDL_VIDEO
WAYLAND_CONFIGURE_ENABLE=	video-wayland wayland-shared video-wayland-qt-touch
WAYLAND_BUILD_DEPENDS=		wayland-protocols>0:graphics/wayland-protocols \
				${LOCALBASE}/include/linux/input.h:devel/evdev-proto
WAYLAND_LIB_DEPENDS=		libwayland-egl.so:graphics/wayland \
				libxkbcommon.so:x11/libxkbcommon
WAYLAND_IMPLIES=		SDL_VIDEO OPENGLES2
X11_CONFIGURE_ENABLE=		video-x11 x11-shared \
				video-x11-xcursor \
				video-x11-xdbe \
				video-x11-xinerama \
				video-x11-xinput \
				video-x11-xfixes \
				video-x11-xrandr \
				video-x11-scrnsaver \
				video-x11-xshape \
				video-x11-vm
X11_USES=			xorg
X11_USE=			XORG=xcursor,xext,xinerama,xi,xfixes,xrandr,xscrnsaver,xxf86vm
X11_IMPLIES=			SDL_VIDEO
DBUS_LIB_DEPENDS=		libdbus-1.so:devel/dbus
DBUS_CONFIGURE_ENABLE=		dbus
FCITX_LIB_DEPENDS=		libfcitx-config.so:chinese/fcitx
FCITX_CONFIGURE_ENABLE=		fcitx
FCITX_IMPLIES=			DBUS
IBUS_LIB_DEPENDS=		libibus-1.0.so:textproc/ibus
IBUS_CONFIGURE_ENABLE=		ibus
IBUS_IMPLIES=			DBUS

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
# Clang does not provide _m_prefetch
	@${REINPLACE_CMD} 's/_m_prefetch/__builtin_prefetch/' \
		${WRKSRC}/configure ${WRKSRC}/src/video/SDL_blit_A.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libSDL2.so

.include <bsd.port.post.mk>
