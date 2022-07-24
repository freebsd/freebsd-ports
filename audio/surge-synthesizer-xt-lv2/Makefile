PORTNAME=	surge-synthesizer-xt
DISTVERSIONPREFIX=	release_xt_
DISTVERSION=	1.0.1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Surge Synthesizer (XT) LV2 and VST plug-in

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	riscv64 # see https://github.com/surge-synthesizer/surge/issues/6363
NOT_FOR_ARCHS_REASON=	simde doesn't support riscv64

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/nanosvg.h:graphics/nanosvg \
		${LOCALBASE}/include/simde/simde-common.h:devel/simde \
		xcb-util-keysyms>0:x11/xcb-util-keysyms \
		bash:shells/bash
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjack.so:audio/jack \
		libmidifile.so:audio/midifile \
		libsamplerate.so:audio/libsamplerate \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-util.so:x11/xcb-util
LIB_DEPENDS+=	libasound.so:audio/alsa-lib # pending https://github.com/surge-synthesizer/surge/issues/5997 resolution

USES=		cmake compiler:c++17-lang gnome localbase:ldflags pkgconfig python:build shebangfix xorg
USE_GNOME=	cairo
USE_XORG=	x11 xcb

USE_GITHUB=	yes
GH_ACCOUNT=	surge-synthesizer
GH_PROJECT=	surge

DATADIR=	${PREFIX}/share/surge-xt

CMAKE_OFF=	JUCE_PLUGINHOST_VST3 JUCE_PLUGINHOST_VST

CXXFLAGS+=	-I${LOCALBASE}/include/midifile # see https://github.com/surge-synthesizer/surge/issues/4358
CXXFLAGS+=	-DPLUGIN_API="" -Dstricmp=strcasecmp -Dstrnicmp=strncasecmp -Dstrnicmp16=strncasecmp # for Juce
LDFLAGS+=	-lmidifile

GH_TUPLE=	surge-synthesizer:tuning-library:bdb107f58ea22720bfa2a6d7a910fc77e69d72fc:surge_synthesizer_tuning_library/libs/tuning-library \
		pybind:pybind11:30eb39ed79d1e2eeff15219ac00773034300a5e6:pybind_pybind11/libs/pybind11 \
		surge-synthesizer:eurorack:1b46769c2404ab88d988bd91f5772d79ac6d5353:surge_synthesizer_eurorack/libs/eurorack/eurorack \
		gulrak:filesystem:8166dd1546c620cfdd4f1bc1d1cd723a91b8f390:gulrak_filesystem/libs/filesystem/ghc-filesystem \
		ODDSound:MTS-ESP:2ec61b536fd1329bf358771eb3f15615a4be7154:ODDSound_MTS_ESP/libs/oddsound-mts/MTS-ESP \
		libsndfile:libsamplerate:d0ea53db94a329bce56e9382852e0931d7744651:libsndfile_libsamplerate/libs/libsamplerate \
		LuaJIT:LuaJIT:ec6edc5c39c25e4eb3fca51b753f9995e97215da:LuaJIT_LuaJIT/libs/LuaJitLib/LuaJIT \
		surge-synthesizer:JUCE:086b21be1b08442631dcb58a9abc12acd48fce0a:surge_synthesizer_JUCE/libs/JUCE \
		fmtlib:fmt:d58d19ba323582841cbf552d1b9230817b61ed01:fmtlib_fmt/libs/fmt \
		taocpp:PEGTL:64af78c6a7959cd5753ad165ec9f65591aa96f2d:taocpp_PEGTL/libs/PEGTL \
		nemequ:munit:da8f73412998e4f1adf1100dc187533a51af77fd:nemequ_munit/libs/simde/test/munit \
		free-audio:clap:ac37c9ab03f26f639e1fc78cf29c6cab9cc65890:free_audio_clap/libs/clap-juce-extensions/clap-libs/clap \
		free-audio:clap-helpers:0b9f7ae5e24e370a4047fd1d6b5d3b83fa0ae7ee:free_audio_clap_helpers/libs/clap-juce-extensions/clap-libs/clap-helpers

BINARY_ALIAS=	python=${PYTHON_CMD}

PORTSCOUT=	ignore:1 # conflicts with old-gen audio/surge-synthesizer-lv2

.include <bsd.port.options.mk>

.if ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == aarch64
CMAKE_ARGS+=	-DARM_NATIVE=native # based on https://github.com/surge-synthesizer/surge/tree/release/1.9.0#building-for-arm-platforms
.endif

.include <bsd.port.mk>
