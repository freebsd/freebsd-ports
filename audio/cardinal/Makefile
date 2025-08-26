# CAVEAT cross-compilation (ex. CPUTYPE=znver3) fails, upstream needs to fix this: https://github.com/DISTRHO/Cardinal/issues/646

PORTNAME=	cardinal
DISTVERSION=	24.09
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/DISTRHO/Cardinal/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Plugin wrapper around VCV Rack
WWW=		https://cardinal.kx.studio/ \
		https://github.com/DISTRHO/Cardinal

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_13=	compilation fails, error: static assertion failed due to requirement 'is_arithmetic<rack::simd::Vector<float, 4>>::value', see https://github.com/DISTRHO/Cardinal/issues/726
BROKEN_FreeBSD_15=	compilation fails, error: static assertion failed due to requirement 'is_arithmetic<rack::simd::Vector<float, 4>>::value', see https://github.com/DISTRHO/Cardinal/issues/726
BROKEN_armv7=	compilation fails due to the variable name conflict with base header, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=279134

BUILD_DEPENDS=	${LOCALBASE}/include/FuzzySearchDatabase.hpp:textproc/fuzzysearchdatabase \
		bash:shells/bash \
		cmake:devel/cmake-core
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libdbus-1.so:devel/dbus \
		libfftw3f.so:math/fftw3-float \
		libjansson.so:devel/jansson \
		libpffft.so:math/pffft \
		libpulse-simple.so:audio/pulseaudio \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libspeexdsp.so:audio/speexdsp

USES=		compiler:c++17-lang gl gmake libarchive localbase:ldflags pkgconfig python sdl shebangfix tar:xz xorg
USE_XORG=	x11 xcursor xext xrandr
USE_GL=		gl
USE_SDL=	sdl2

SHEBANG_GLOB=	*.sh

CXXFLAGS+=	-I${LOCALBASE}/include/pffft
CXXFLAGS_powerpc64le=	-DNO_WARN_X86_INTRINSICS
LDFLAGS+=	-lpffft -lexecinfo

#MAKE_ENV=	LD_PRELOAD=/usr/lib/libpthread.so # workaround for https://github.com/DISTRHO/Cardinal/issues/128#issuecomment-1030817359
MAKE_ARGS=	SYSDEPS=true

BINARY_ALIAS=	gcc-ar=ar \
		python3=${PYTHON_CMD}

OPTIONS_DEFINE=		DOCS LIBLO LTO
OPTIONS_DEFAULT=	#LIBLO LTO

PORTDOCS=		*

LIBLO_DESC=		Support Open Sound Control protocol through liblo
LIBLO_MAKE_ARGS=	WITH_LTO=true
LIBLO_MAKE_ARGS_OFF=	WITH_LTO=false
LIBLO_LIB_DEPENDS=	liblo.so:audio/liblo
LIBLO_BROKEN=		fails to build with liblo, see https://github.com/DISTRHO/Cardinal/issues/641

LTO_MAKE_ARGS=		WITH_LTO=true
LTO_BROKEN=		Fails to build with LTO because it is gcc-centered

.include <bsd.port.options.mk>

# workaround for ld: error: undefined symbol: roundevenf
.if ${OPSYS} == FreeBSD
USES+=	llvm:max=15
.endif

.include <bsd.port.mk>
