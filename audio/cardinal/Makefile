PORTNAME=	cardinal
DISTVERSION=	23.10
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://github.com/DISTRHO/Cardinal/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Plugin wrapper around VCV Rack
WWW=		https://cardinal.kx.studio/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation breaks: use of overloaded operator '[]' is ambiguous, see https://github.com/DISTRHO/Cardinal/issues/613

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

USES=		compiler:c++11-lang gl gmake libarchive localbase:ldflags pkgconfig python sdl shebangfix tar:xz xorg
USE_XORG=	x11 xcursor xext xrandr
USE_GL=		gl
USE_SDL=	sdl2

SHEBANG_GLOB=	*.sh

CXXFLAGS+=	-I${LOCALBASE}/include/pffft
CXXFLAGS_powerpc64le=	-DNO_WARN_X86_INTRINSICS
LDFLAGS+=	-lpffft -lexecinfo

MAKE_ENV=	LD_PRELOAD=/usr/lib/libpthread.so # workaround for https://github.com/DISTRHO/Cardinal/issues/128#issuecomment-1030817359
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

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
USES+=	llvm:max=15
.endif

.include <bsd.port.mk>
