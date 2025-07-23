PORTNAME=	openal-soft
PORTVERSION=	1.24.3
CATEGORIES=	audio
MASTER_SITES=	https://openal-soft.org/openal-releases/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Software implementation of the OpenAL specification
WWW=		https://openal-soft.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus

USES=		cmake compiler:c++17-lang pkgconfig tar:bzip2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INSTALL_DATADIR:STRING="${PREFIX}/etc"
CMAKE_ON=	ALSOFT_BACKEND_WAVE
CMAKE_OFF=	ALSOFT_BACKEND_ALSA ALSOFT_DLOPEN ALSOFT_EXAMPLES \
		ALSOFT_REQUIRE_SOLARIS

# Use pthread instead of C11 threads
CFLAGS+=	-D__STDC_NO_THREADS__
# do not link with librt and libdl.
LDFLAGS+=	-Wl,--as-needed
LDFLAGS_i386=	-Wl,-z,notext

PLIST_SUB=	SOVERSION=${PORTVERSION}

OPTIONS_DEFINE=		CONFIG EXAMPLES JACK OSS PIPEWIRE PORTAUDIO \
			PULSEAUDIO SDL SNDIO UTILS
OPTIONS_DEFINE_aarch64=	SIMD
OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT=	OSS UTILS
OPTIONS_DEFAULT_aarch64=SIMD
OPTIONS_DEFAULT_amd64=	SIMD
OPTIONS_DEFAULT_i386=	SIMD

OPTIONS_SUB=		yes

CONFIG_DESC=		Install configuration utility (needs Qt 5)
UTILS_DESC=		Build and install utility programs

CONFIG_IMPLIES=		UTILS
CONFIG_USES=		qt:5
CONFIG_USE=		QT=core,gui,widgets,buildtools:build,qmake:build
CONFIG_CMAKE_BOOL_OFF=	ALSOFT_NO_CONFIG_UTIL

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	ALSOFT_BACKEND_JACK ALSOFT_REQUIRE_JACK

OSS_CMAKE_BOOL=		ALSOFT_BACKEND_OSS ALSOFT_REQUIRE_OSS

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_USES=		localbase:ldflags
PIPEWIRE_CMAKE_BOOL=	ALSOFT_BACKEND_PIPEWIRE ALSOFT_REQUIRE_PIPEWIRE

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL=	ALSOFT_BACKEND_PORTAUDIO ALSOFT_REQUIRE_PORTAUDIO

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	ALSOFT_BACKEND_PULSEAUDIO ALSOFT_REQUIRE_PULSEAUDIO

SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SDL_CMAKE_BOOL=		ALSOFT_BACKEND_SDL2 ALSOFT_REQUIRE_SDL2

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_BOOL=	ALSOFT_BACKEND_SNDIO ALSOFT_REQUIRE_SNDIO

UTILS_LIB_DEPENDS=	libmysofa.so:audio/libmysofa
UTILS_CMAKE_BOOL=	ALSOFT_UTILS

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSIMD}
.  if !${MACHINE_CPU:Msse}
CMAKE_OFF+=	ALSOFT_CPUEXT_SSE
.  endif
.  if !${MACHINE_CPU:Msse2}
CMAKE_OFF+=	ALSOFT_CPUEXT_SSE2
.  endif
.  if !${MACHINE_CPU:Msse3}
CMAKE_OFF+=	ALSOFT_CPUEXT_SSE3
.  endif
.  if !${MACHINE_CPU:Msse41}
CMAKE_OFF+=	ALSOFT_CPUEXT_SSE4_1
.  endif
.else
CMAKE_OFF+=	ALSOFT_CPUEXT_NEON \
		ALSOFT_CPUEXT_SSE \
		ALSOFT_CPUEXT_SSE2 \
		ALSOFT_CPUEXT_SSE3 \
		ALSOFT_CPUEXT_SSE4_1
.endif

# The following is actually meant for lld 15.0 and later, but the ports
# framework does not support LINKER_TYPE and LINKER_VERSION yet.
.if ${COMPILER_TYPE} == "clang"
# Turn off checking of dynamic relocations, to avoid lld diagnostics about
# possibly incorrect addend values.
LDFLAGS_i386+=	-Wl,--no-check-dynamic-relocations
.endif

post-patch:
	@${REINPLACE_CMD} 's|/etc/openal|${ETCDIR}|' \
		${WRKSRC}/alc/alconfig.cpp

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.post.mk>
