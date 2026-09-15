# CAVEAT cross-compilation (ex. CPUTYPE=znver3) fails, upstream needs to fix this: https://github.com/DISTRHO/Cardinal/issues/646

PORTNAME=	cardinal
DISTVERSION=	26.02
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/DISTRHO/Cardinal/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Plugin wrapper around VCV Rack
WWW=		https://cardinal.kx.studio/ \
		https://github.com/DISTRHO/Cardinal

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails due to the variable name conflict with base header, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=279134

BUILD_DEPENDS=	${LOCALBASE}/include/FuzzySearchDatabase.hpp:textproc/fuzzysearchdatabase \
		bash:shells/bash \
		cmake:devel/cmake-core
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libdbus-1.so:devel/dbus \
		libfftw3f.so:math/fftw3-float \
		libjansson.so:devel/jansson \
		liblo.so:audio/liblo \
		libpffft.so:math/pffft \
		libpulse-simple.so:audio/pulseaudio \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libspeexdsp.so:audio/speexdsp
RUN_DEPENDS=	xdg-desktop-portal>0:deskutils/xdg-desktop-portal

USES=		compiler:c++17-lang gl gmake libarchive localbase:ldflags pkgconfig python sdl shebangfix tar:xz xorg
USE_XORG=	x11 xcursor xext xrandr
USE_GL=		gl
USE_SDL=	sdl2
USE_CXXSTD=	c++14 # keep std::random_shuffle that was removed in c++17, see https://github.com/DISTRHO/Cardinal/issues/945

SHEBANG_GLOB=	*.sh

CXXFLAGS+=	-I${LOCALBASE}/include/pffft
CXXFLAGS+=	-Wno-error=missing-template-arg-list-after-template-kw # workaround for surgext/src/VCO.cpp:1051:28: error: a template argument list is expected after a name prefixed by the template keyword [-Wmissing-template-arg-list-after-template-kw]
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

LDFLAGS+=		-Wl,--allow-multiple-definition # for roundevenf fix below: multipl binaries are built with multiple modules, so we add roundevenf and alow multiple definitions of it

post-patch:
	# inject definition of missing function roundevenf, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=298503
	@cd ${WRKSRC} && \
		for f in \
			plugins/ZZC/src/FN.cpp \
			plugins/Fundamental/src/LFO.cpp \
			plugins/Biset/src/Igc/Igc.cpp \
			plugins/ML_modules/src/Quant.cpp \
			plugins/HetrickCV/src/Bitshift.cpp \
			plugins/Venom/src/XM_OP.cpp \
			plugins/Venom/src/PolyOffset.cpp \
			plugins/MindMeldModular/src/EqMaster/EqMaster.cpp \
			plugins/AnimatedCircuits/src/Folding/Folding.cpp \
			plugins/AnimatedCircuits/src/LFold/LFold.cpp \
			plugins/dBiz/src/Bench.cpp \
		; do \
			cat ${FILESDIR}/roundevenf-definition.c $$f > $$f.tmp && mv $$f.tmp $$f; \
		done

.include <bsd.port.mk>
