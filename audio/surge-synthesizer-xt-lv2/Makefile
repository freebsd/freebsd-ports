PORTNAME=	surge-synthesizer-xt
DISTVERSIONPREFIX=	release_xt_
DISTVERSION=	1.3.2
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	8a2fb0c5522d9872b79aa6053253cf252dcf81fa.patch:-p1 \
		373971b24477abb1b7f5a18657b0fb48ef5177ca.patch:-p1 \
		90e36f5be98ba12a513e53401c89732ae7fd11b3.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Surge Synthesizer (XT) LV2 and VST plug-in
WWW=		https://surge-synthesizer.github.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv7 i386 powerpc riscv64 # see https://github.com/surge-synthesizer/surge/issues/6363
NOT_FOR_ARCHS_REASON=	32 Bit Builds are only available on Windows; simde doesn't support riscv64

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/nanosvg.h:graphics/nanosvg \
		${LOCALBASE}/include/simde/simde-common.h:devel/simde \
		xcb-util-keysyms>0:x11/xcb-util-keysyms \
		bash:shells/bash
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjack.so:audio/jack \
		libsamplerate.so:audio/libsamplerate \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-util.so:x11/xcb-util
LIB_DEPENDS+=	libasound.so:audio/alsa-lib # pending https://github.com/surge-synthesizer/surge/issues/5997 resolution

USES=		cmake compiler:c++17-lang gnome localbase:ldflags pkgconfig python:build shebangfix xorg
USE_GNOME=	cairo
USE_XORG=	x11 xcb xcursor xinerama xrandr

USE_GITHUB=	yes
GH_ACCOUNT=	surge-synthesizer
GH_PROJECT=	surge

DATADIR=	${PREFIX}/share/surge-xt

CMAKE_ON=	SURGE_BUILD_LV2 \
		SURGE_SKIP_VST3
CMAKE_OFF=	JUCE_PLUGINHOST_VST3 JUCE_PLUGINHOST_VST

CFLAGS+=	-Wno-nan-infinity-disabled # workaround for https://github.com/surge-synthesizer/surge/issues/7730
CXXFLAGS+=	-DPLUGIN_API="" -Dstricmp=strcasecmp -Dstrnicmp=strncasecmp -Dstrnicmp16=strncasecmp # for Juce

.if !defined(WITH_DEBUG)
CFLAGS+=	-O3 -ffast-math
CXXFLAGS+=	-O3 -ffast-math
.endif

GH_TUPLE=	surge-synthesizer:eurorack:f7614460cd3e295f6f6132f9052984c7bca9a69d:surge_synthesizer_eurorack/libs/eurorack/eurorack \
		fmtlib:fmt:67c0c0c09cf74d407d71a29c194761981614df3e:fmtlib_fmt/libs/fmt \
		surge-synthesizer:JUCE:cf5754b:surge_synthesizer_JUCE/libs/JUCE \
		libsndfile:libsamplerate:d0ea53db94a329bce56e9382852e0931d7744651:libsndfile_libsamplerate/libs/libsamplerate \
		LuaJIT:LuaJIT:ec6edc5c39c25e4eb3fca51b753f9995e97215da:LuaJIT_LuaJIT/libs/LuaJitLib/LuaJIT \
		simd-everywhere:simde:71fd833d9666141edcd1d3c109a80e228303d8d7:simd_everywhere_simde/libs/simde \
		surge-synthesizer:tuning-library:4cbe55f2da86c0302368a681406553a1dd7074dd:surge_synthesizer_tuning_library/libs/tuning-library \
		ODDSound:MTS-ESP:3eb56f2452244b343ce738efd067d1082b67f9b4:ODDSound_MTS_ESP/libs/oddsound-mts/MTS-ESP \
		taocpp:PEGTL:64af78c6a7959cd5753ad165ec9f65591aa96f2d:taocpp_PEGTL/libs/PEGTL \
		surge-synthesizer:pffft:96292e6965f74d5e08108f5f717df0bf8aa06b57:surge_synthesizer_pffft/libs/pffft \
		pybind:pybind11:0bd8896a4010f2d91b2340570c24fa08606ec406:pybind_pybind11/libs/pybind11 \
		surge-synthesizer:sst-basic-blocks:42675840a0dd18bfd997f6394b874e0ec984b651:surge_synthesizer_sst_basic_blocks/libs/sst/sst-basic-blocks \
		surge-synthesizer:sst-cpputils:9418be4d6e059e236db43f99925f46492203ec55:surge_synthesizer_sst_cpputils/libs/sst/sst-cpputils \
		surge-synthesizer:sst-effects:e63fe46e38166ca0658639b66e706f740b468c44:surge_synthesizer_sst_effects/libs/sst/sst-effects \
		surge-synthesizer:sst-filters:1733117d051b2b1d09296547af28dec0bcb3dc69:surge_synthesizer_sst_filters/libs/sst/sst-filters \
		surge-synthesizer:sst-plugininfra:49ee7eb761bc06d0c0a012659f975d59b868e3e8:surge_synthesizer_sst_plugininfra/libs/sst/sst-plugininfra \
		surge-synthesizer:sst-waveshapers:42bfa678e4f2447d0f4c9a51b7ba7ea68f6da108:surge_synthesizer_sst_waveshapers/libs/sst/sst-waveshapers \
		sudara:melatonin_inspector:b7a0f2de07ed8692963605561fe1a3793885994b:sudara_melatonin_inspector/libs/melatonin_inspector \
		free-audio:clap:df8f16c69ba1c1a15fb105f0c5a2e5b9ac6be742:free_audio_clap/libs/clap-juce-extensions/clap-libs/clap \
		free-audio:clap-helpers:7b53a685e11465154b4ccba3065224dbcbf8a893:free_audio_clap_helpers/libs/clap-juce-extensions/clap-libs/clap-helpers \
		free-audio:clap-juce-extensions:087dd16e2d17e6b3f1c9a92817a8a7348ea08168:free_audio_clap_juce_extensions/libs/clap-juce-extensions \
		nemequ:munit:da8f73412998e4f1adf1100dc187533a51af77fd:nemequ_munit/libs/simde/test/munit \
		gulrak:filesystem:614bbe87b80435d87ab8791564370e0c1d13627d:gulrak_filesystem/libs/sst/sst-plugininfra/libs/filesystem/ghc-filesystem \
		richgel999:miniz:16413c213de38e703d883006193734e8b1178d5d:richgel999_miniz/libs/sst/sst-plugininfra/libs/miniz

BINARY_ALIAS=	python=${PYTHON_CMD}

PORTSCOUT=	ignore:1 # conflicts with old-gen audio/surge-synthesizer-lv2

.include <bsd.port.options.mk>

.if ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == aarch64
CMAKE_ARGS+=	-DARM_NATIVE=native # based on https://github.com/surge-synthesizer/surge/tree/release/1.9.0#building-for-arm-platforms
.endif

.include <bsd.port.pre.mk>

post-patch:
.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
	#@${REINPLACE_CMD} -e 's|move (group)|std::move (group)|g' \
	#	${WRKSRC}/libs/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.cpp
.endif

.include <bsd.port.post.mk>
