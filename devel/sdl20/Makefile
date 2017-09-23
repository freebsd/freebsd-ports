# $FreeBSD$

PORTNAME=	sdl2
PORTVERSION=	2.0.6
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/release/
DISTNAME=	SDL2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform multimedia development API

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING.txt

GNU_CONFIGURE=	yes
USES=		gmake iconv libtool localbase:ldflags pathfix pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--disable-video-opengles \
			--disable-altivec \
			--disable-arts \
			--enable-diskaudio \
			--enable-dummyaudio \
			--enable-video-dummy \
			--disable-dbus \
			--disable-input-tslib \
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

OPTIONS_DEFINE=		ALSA ASM DLOPEN ESOUND JACK NAS OSS SAMPLERATE	\
			PULSEAUDIO SNDIO PTHREADS SDL_ATOMIC SDL_AUDIO	\
			SDL_CPUINFO SDL_EVENTS SDL_FILE SDL_HAPTIC	\
			SDL_JOYSTICK SDL_LOADSO SDL_POWER SDL_RENDER	\
			SDL_THREADS SDL_TIMERS SDL_VIDEO VIDEO_KMSDRM	\
			VIDEO_OPENGL VIDEO_X11
OPTIONS_DEFAULT=	ASM DLOPEN OSS PTHREADS SDL_ATOMIC SDL_AUDIO	\
			SDL_CPUINFO SDL_EVENTS SDL_FILE SDL_HAPTIC	\
			SDL_JOYSTICK SDL_LOADSO SDL_POWER SDL_RENDER	\
			SDL_THREADS SDL_TIMERS SDL_VIDEO VIDEO_KMSDRM	\
			VIDEO_OPENGL VIDEO_X11

ALSA_DESC=		Audio output via the ALSA audio architecture
DLOPEN_DESC=		Use dlopen for loading 3rd party libraries
ESOUND_DESC=		Audio output via the EsounD sound server
JACK_DESC=		Audio output via the JackD sound server
NAS_DESC=		Audio output via the Network Audio System
OSS_DESC=		Audio output via the Open Sound System
PULSEAUDIO_DESC=	Audio output via the PulseAudio sound server
PTHREADS_DESC=		Use POSIX threads for multi-threading
SAMPLERATE_DESC=	Audio rate conversion via libsamplerate
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
VIDEO_KMSDRM_DESC=	KMSDRM rendering support
VIDEO_OPENGL_DESC=	OpenGL rendering support
VIDEO_X11_DESC=		X11 rendering support

ASM_CONFIGURE_ENABLE=		assembly
DLOPEN_CONFIGURE_ENABLE=	sdl-dlopen
PTHREADS_CONFIGURE_ENABLE=	pthreads pthread-sem
SAMPLERATE_CONFIGURE_ENABLE=	libsamplerate libsamplerate-shared
SAMPLERATE_LIB_DEPENDS=		libsamplerate.so:audio/libsamplerate
SDL_ATOMIC_CONFIGURE_ENABLE=	atomic gcc-atomics
SDL_AUDIO_CONFIGURE_ENABLE=	audio
SDL_CPUINFO_CONFIGURE_ENABLE=	cpuinfo
SDL_EVENTS_CONFIGURE_ENABLE=	events
SDL_FILE_CONFIGURE_ENABLE=	filesystem
SDL_HAPTIC_CONFIGURE_ENABLE=	haptic
SDL_JOYSTICK_CONFIGURE_ENABLE=	joystick
SDL_LOADSO_CONFIGURE_ENABLE=	loadso
SDL_POWER_CONFIGURE_ENABLE=	power
SDL_RENDER_CONFIGURE_ENABLE=	render
SDL_THREADS_CONFIGURE_ENABLE=	threads
SDL_TIMERS_CONFIGURE_ENABLE=	timers
SDL_VIDEO_CONFIGURE_ENABLE=	video

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
.if !${PORT_OPTIONS:MSDL_AUDIO}
IGNORE=	option ALSA requires SDL_AUDIO
.endif
CONFIGURE_ARGS+=	--enable-alsa --enable-alsa-shared
LIB_DEPENDS+=		libasound.so:audio/alsa-lib
.else
CONFIGURE_ARGS+=	--disable-alsa --disable-alsa-shared
.endif

.if ${PORT_OPTIONS:MJACK}
.if !${PORT_OPTIONS:MSDL_AUDIO}
IGNORE=	option JACK requires SDL_AUDIO
.endif
CONFIGURE_ARGS+=	--enable-jack --enable-jack-shared
LIB_DEPENDS+=		libjack.so:audio/jack
.else
CONFIGURE_ARGS+=	--disable-jack --disable-jack-shared
.endif

.if ${PORT_OPTIONS:MESOUND}
.if !${PORT_OPTIONS:MSDL_AUDIO}
IGNORE=	option ESOUND requires SDL_AUDIO
.endif
CONFIGURE_ARGS+=	--enable-esd --enable-esd-shared
USE_GNOME+=		esound
.else
CONFIGURE_ARGS+=	--disable-esd --disable-esd-shared
.endif

.if ${PORT_OPTIONS:MNAS}
.if !${PORT_OPTIONS:MSDL_AUDIO}
IGNORE=	option NAS requires SDL_AUDIO
.endif
CONFIGURE_ARGS+=	--enable-nas --enable-nas-shared
LIB_DEPENDS+=		libaudio.so:audio/nas
.else
CONFIGURE_ARGS+=	--disable-nas --disable-nas-shared
.endif

.if ${PORT_OPTIONS:MOSS}
.if !${PORT_OPTIONS:MSDL_AUDIO}
IGNORE=	option OSS requires SDL_AUDIO
.endif
CONFIGURE_ARGS+=	--enable-oss
.else
CONFIGURE_ARGS+=	--disable-oss
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
.if !${PORT_OPTIONS:MSDL_AUDIO}
IGNORE=	option PULSEAUDIO requires SDL_AUDIO
.endif
CONFIGURE_ARGS+=	--enable-pulseaudio --enable-pulseaudio-shared
.else
CONFIGURE_ARGS+=	--disable-pulseaudio --disable-pulseaudio-shared
.endif

.if ${PORT_OPTIONS:MSNDIO}
.if !${PORT_OPTIONS:MSDL_AUDIO}
IGNORE=	option SNDIO requires SDL_AUDIO
.endif
CONFIGURE_ARGS+=	--enable-sndio --enable-sndio-shared
LIB_DEPENDS+=		libsndio.so:audio/sndio
.else
CONFIGURE_ARGS+=	--disable-sndio --disable-sndio-shared
.endif

.if ${PORT_OPTIONS:MVIDEO_KMSDRM}
.if !${PORT_OPTIONS:MSDL_VIDEO}
IGNORE=	option VIDEO_KMSDRM requires SDL_VIDEO
.endif
CONFIGURE_ARGS+=	--enable-video-kmsdrm --enable-kmsdrm-shared
BUILD_DEPENDS+=		${LOCALBASE}/libdata/pkgconfig/libdrm.pc:graphics/libdrm \
			${LOCALBASE}/libdata/pkgconfig/gbm.pc:graphics/mesa-libs
.else
CONFIGURE_ARGS+=	--disable-video-kmsdrm --disable-video-kmsdrm
.endif

.if ${PORT_OPTIONS:MVIDEO_OPENGL}
.if !${PORT_OPTIONS:MSDL_VIDEO}
IGNORE=	option VIDEO_OPENGL requires SDL_VIDEO
.endif
CONFIGURE_ARGS+=	--enable-video-opengl
USE_GL+=		gl
.else
CONFIGURE_ARGS+=	--disable-video-opengl
.endif

.if ${PORT_OPTIONS:MVIDEO_X11}
.if !${PORT_OPTIONS:MSDL_VIDEO}
IGNORE=	option VIDEO_X11 requires SDL_VIDEO
.endif
CONFIGURE_ARGS+=	--enable-video-x11 \
			--enable-x11-shared \
			--enable-video-x11-xcursor \
			--enable-video-x11-xinerama \
			--enable-video-x11-xinput \
			--enable-video-x11-xrandr \
			--enable-video-x11-scrnsaver \
			--enable-video-x11-xshape \
			--enable-video-x11-vm
USE_XORG+=	xinerama xcursor xi xrandr xscrnsaver xxf86vm xext
.else
CONFIGURE_ARGS+=	--disable-video-x11 \
			--disable-x11-shared \
			--disable-video-x11-xcursor \
			--disable-video-x11-xinerama \
			--disable-video-x11-xinput \
			--disable-video-x11-xrandr \
			--disable-video-x11-scrnsaver \
			--disable-video-x11-xshape \
			--disable-video-x11-vm
.endif

.include <bsd.port.pre.mk>

.if !empty(ICONV_LIB)
CONFIGURE_ARGS+=	ac_cv_lib_iconv_iconv_open=yes ac_cv_func_iconv=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e '/ CheckInputEvents$$/d' \
		-e 's/-liconv/${ICONV_LIB}/g' ${WRKSRC}/configure
# Clang does not provide _m_prefetch
	@${REINPLACE_CMD} 's/_m_prefetch/__builtin_prefetch/' \
		${WRKSRC}/configure ${WRKSRC}/src/video/SDL_blit_A.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libSDL2.so

.include <bsd.port.post.mk>
