PORTNAME=	noise-suppression-for-voice
DISTVERSIONPREFIX=	v
DISTVERSION=	1.03
PORTREVISION=	2
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Real-time noise suppression plugin
WWW=		https://github.com/werman/noise-suppression-for-voice

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	link fails: ld: error: undefined symbol: __atomic_store and ld: error: undefined symbol: __atomic_load

BUILD_DEPENDS=	juce>0:devel/juce \
		lv2>0:audio/lv2
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng16.so:graphics/png

USES=		cmake compiler:c11 localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	werman

CMAKE_OFF=	BUILD_TESTS
CMAKE_OFF+=	BUILD_VST_PLUGIN # https://github.com/werman/noise-suppression-for-voice/issues/65
CXXFLAGS+=	-DJUCE_CUSTOM_VST3_SDK=1 -DJUCE_INCLUDE_PNGLIB_CODE=0
LDFLAGS+=	-lpng16

PLIST_SUB=	XARCH=${ARCH:S/amd64/x86_64/}

OPTIONS_DEFINE=		LADSPA VST3
OPTIONS_DEFAULT=	LADSPA #VST3
OPTIONS_SUB=		yes

LADSPA_CMAKE_BOOL=	BUILD_LADSPA_PLUGIN

VST3_CMAKE_BOOL=	BUILD_VST3_PLUGIN
VST3_BROKEN=		fails to build with juce-7.0.6, see https://github.com/werman/noise-suppression-for-voice/issues/177

post-extract: # remove bundled JUCE
	@${RM} -rf ${WRKSRC}/external/JUCE

post-install: # move plugins to a proper place: workaround for https://github.com/juce-framework/JUCE/issues/1237 and strip binaries
	@${MV} ${STAGEDIR}${WRKDIR}/.lv2 ${STAGEDIR}${PREFIX}/lib/lv2
	# remove empty directories
	@${FIND} ${STAGEDIR} -type d -empty -delete
	# strip binaries
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
		lib/lv2/rnnoise_mono.lv2/librnnoise_mono.so \
		lib/lv2/rnnoise_stereo.lv2/librnnoise_stereo.so

post-install-VST3-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst3
	@${MV} `${FIND} ${STAGEDIR} -name rnnoise.vst3` ${STAGEDIR}${PREFIX}/lib/vst3
	# strip binaries
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
		lib/vst3/rnnoise.vst3/Contents/*/rnnoise.so

# the LADSPA plugin can be used directly from PulseAudio's config file

.include <bsd.port.mk>
