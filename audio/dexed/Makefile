PORTNAME=	dexed
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.6-16
DISTVERSIONSUFFIX=	-g1df9a58
PORTREVISION=	4
CATEGORIES=	audio
PKGNAMESUFFIX=	-synth

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DX7 FM multi plaform/multi format plugin

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

GH_TUPLE=	steinbergmedia:vst3sdk:2cc517019a2681fccf211e6a95776a0af1e16d04:steinbergmedia_vst3sdk/libs/vst3sdk \
		steinbergmedia:vst3_base:985fe019276ee03c2751a1736ba3b390678e29f2:asb2m10_vst3_base/libs/vst3sdk/base \
		steinbergmedia:vst3_cmake:31b3f3c3e5c4e1bcfee221e5076b6b56296214d7:asb2m10_vst3_cmake/libs/vst3sdk/cmake \
		steinbergmedia:vst3_doc:a3ad6a147ed8347c802dd2a946d84939a3572164:asb2m10_vst3_doc/libs/vst3sdk/doc \
		steinbergmedia:vst3_pluginterfaces:93cef1afb7061e488625045ba5a82abaa83d27fe:asb2m10_vst3_pluginterfaces/libs/vst3sdk/pluginterfaces \
		steinbergmedia:vst3_public_sdk:9589800ed94573354bc29de45eec5744523fbfcb:asb2m10_vst3_public_sdk/libs/vst3sdk/public.sdk \
		steinbergmedia:vstgui:6c48e17c174abaf2f1dc8ae41e5fab70599eca6c:asb2m10_vstgui/libs/vst3sdk/vstgui4 \
		surge-synthesizer:tuning-library:b3069450045fe439206628f08220300864e5a958:surge_synthesizer_tuning_library/libs/tuning-library \
		surge-synthesizer:surgesynthteam_tuningui:54f9a74cd55cdb33fb4d32d706067626857cfc75:surge_synthesizer_surgesynthteam_tuningui/libs/surgesynthteam_tuningui \
		juce-framework:JUCE:2f980209cc4091a4490bb1bafc5d530f16834e58:juce_framework_JUCE/libs/JUCE

DOS2UNIX_GLOB=	*.cpp *.h

PLIST_FILES=	bin/Dexed

OPTIONS_DEFINE=		VST3
OPTIONS_DEFAULT=	VST3

VST3_DESC=		Build the VST3 plugin
VST3_BUILD_DEPENDS=	vst3sdk>0:audio/vst3sdk
VST3_CXXFLAGS=		-DJUCE_CUSTOM_VST3_SDK=1 -fPIC
VST3_PLIST_FILES=	lib/vst3/Dexed.so

CXXFLAGS+=	-DJUCE_INCLUDE_PNGLIB_CODE=0 # to fix build on powerpc64le, see bug#265446, https://github.com/juce-framework/JUCE/issues/1094
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
