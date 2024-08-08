PORTNAME=	dexed
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.7
CATEGORIES=	audio
PKGNAMESUFFIX=	-synth

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DX7 FM multi plaform/multi format plugin
WWW=		https://asb2m10.github.io/dexed/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libX11>0:x11/libX11 \
		libXcursor>0:x11/libXcursor \
		libXinerama>0:x11/libXinerama \
		libXrandr>0:x11/libXrandr
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libjack.so:audio/jack \
		libpng16.so:graphics/png \
		libasound.so:audio/alsa-lib # see https://github.com/asb2m10/dexed/issues/343 about the ALSA use

USES=		cmake dos2unix localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	asb2m10

GH_TUPLE= \
		steinbergmedia:vst3sdk:e9895dc9ef20bedd93a0fde5ad664bc8b56d4338:steinbergmedia_vst3sdk/libs/vst3sdk \
		surge-synthesizer:tuning-library:601c0eabff31fff8a543b49d3e48073f338f413c:surge_synthesizer_tuning_library/libs/tuning-library \
		surge-synthesizer:surgesynthteam_tuningui:54f9a74cd55cdb33fb4d32d706067626857cfc75:surge_synthesizer_surgesynthteam_tuningui/libs/surgesynthteam_tuningui \
		ODDSound:MTS-ESP:514ed958b38e5ab501999f902a2427ebe6232a78:ODDSound_MTS_ESP/libs/MTS-ESP \
		juce-framework:JUCE:d054f0d14dcac387aebda44ce5d792b5e7a625b3:juce_framework_JUCE/libs/JUCE \
		free-audio:clap-juce-extensions:4491bc30223cecf8ff495de943510863b71a7a81:free_audio_clap_juce_extensions/libs/clap-juce-extensions \
		free-audio:clap:df8f16c69ba1c1a15fb105f0c5a2e5b9ac6be742:free_audio_clap/libs/clap-juce-extensions/clap-libs/clap \
		free-audio:clap-helpers:7b53a685e11465154b4ccba3065224dbcbf8a893:free_audio_clap_helpers/libs/clap-juce-extensions/clap-libs/clap-helpers

DOS2UNIX_GLOB=	*.cpp *.h

PLIST_FILES=	bin/Dexed

OPTIONS_DEFINE=		VST3
#OPTIONS_DEFAULT=	VST3

VST3_DESC=		Build the VST3 plugin
VST3_BUILD_DEPENDS=	vst3sdk>0:audio/vst3sdk
VST3_CXXFLAGS=		-DJUCE_CUSTOM_VST3_SDK=1 -fPIC
VST3_PLIST_FILES=	lib/vst3/Dexed.so
VST3_BROKEN=		VST3 plugin fails to build, see https://github.com/asb2m10/dexed/issues/433

CXXFLAGS+=	-DJUCE_INCLUDE_PNGLIB_CODE=0 # to fix build on powerpc64le, see bug#265446, https://github.com/juce-framework/JUCE/issues/1094
CXXFLAGS+=	-fPIC # workaround for ld: error: relocation R_X86_64_PC32 cannot be used against symbol 'BinaryData::LFO_36_26_png'; recompile with -fPIC
#CXXFLAGS+=	-DJUCE_CUSTOM_VST3_SDK=1
LDFLAGS+=	-lpng16

PORTSCOUT=	skipv:nightly

post-patch-VST3-off:
	@${REINPLACE_CMD} -e 's/FORMATS AU VST3 Standalone/FORMATS AU Standalone/' ${WRKSRC}/Source/CMakeLists.txt

do-install: # workaround for https://github.com/asb2m10/dexed/issues/342
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/Source/Dexed_artefacts/Release/Standalone/Dexed ${STAGEDIR}${PREFIX}/bin

do-install-VST3-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst3
	${INSTALL_LIB} ${BUILD_WRKSRC}/Source/Dexed_artefacts/Release/VST3/Dexed.vst3/Contents/*/Dexed.so ${STAGEDIR}${PREFIX}/lib/vst3

.include <bsd.port.mk>
