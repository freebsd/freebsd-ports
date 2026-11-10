PORTNAME=	dexed
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	audio
PKGNAMESUFFIX=	-synth

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DX7 FM multi plaform/multi format plugin
WWW=		https://asb2m10.github.io/dexed/ \
		https://github.com/asb2m10/dexed

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails due to the 'mb' variable conflict, pending https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=283492

BUILD_DEPENDS=	libX11>0:x11/libX11 \
		libXcursor>0:x11/libXcursor \
		libXinerama>0:x11/libXinerama \
		libXrandr>0:x11/libXrandr
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjack.so:audio/jack \
		libpng16.so:graphics/png \
		libasound.so:audio/alsa-lib # see https://github.com/asb2m10/dexed/issues/343 about the ALSA use

USES=		cmake dos2unix localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	asb2m10

GH_TUPLE=	\
		surge-synthesizer:tuning-library:6fa04a0:surge_synthesizer_tuning_library/libs/tuning-library \
		asb2m10:surgesynthteam_tuningui:2446bfc:asb2m10_surgesynthteam_tuningui/libs/surgesynthteam_tuningui \
		ODDSound:MTS-ESP:803c3aa:ODDSound_MTS_ESP/libs/MTS-ESP \
		juce-framework:JUCE:c352e24:juce_framework_JUCE/libs/JUCE \
		free-audio:clap-juce-extensions:16e9d4c:free_audio_clap_juce_extensions/libs/clap-juce-extensions \
			free-audio:clap:29ffcc2:free_audio_clap/libs/clap-juce-extensions/clap-libs/clap \
			free-audio:clap-helpers:a61bcdf:free_audio_clap_helpers/libs/clap-juce-extensions/clap-libs/clap-helpers

DOS2UNIX_GLOB=	*.cpp *.h

PLIST_FILES=	bin/Dexed

OPTIONS_DEFINE=		VST3
#OPTIONS_DEFAULT=	VST3

VST3_DESC=		Build the VST3 plugin
VST3_CMAKE_OFF=		-DDEXED_SKIP_VST3=ON
VST3_BUILD_DEPENDS=	vst3sdk>0:audio/vst3sdk
VST3_CXXFLAGS=		-DJUCE_CUSTOM_VST3_SDK=1 -fPIC
VST3_PLIST_FILES=	lib/vst3/Dexed.so
VST3_BROKEN=		VST3 plugin fails to build, see https://github.com/asb2m10/dexed/issues/433

CXXFLAGS+=	-DJUCE_INCLUDE_PNGLIB_CODE=0 # to fix build on powerpc64le, see bug#265446, https://github.com/juce-framework/JUCE/issues/1094
CXXFLAGS+=	-fPIC # workaround for ld: error: relocation R_X86_64_PC32 cannot be used against symbol 'BinaryData::LFO_36_26_png'; recompile with -fPIC
#CXXFLAGS+=	-DJUCE_CUSTOM_VST3_SDK=1
LDFLAGS+=	-lpng16

PORTSCOUT=	skipv:nightly

do-install: # workaround for https://github.com/asb2m10/dexed/issues/342
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/source/Dexed_artefacts/Release/Standalone/Dexed ${STAGEDIR}${PREFIX}/bin

do-install-VST3-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst3
	${INSTALL_LIB} ${BUILD_WRKSRC}/source/Dexed_artefacts/Release/VST3/Dexed.vst3/Contents/*/Dexed.so ${STAGEDIR}${PREFIX}/lib/vst3

.include <bsd.port.mk>
