PORTNAME=	noise-suppression-for-voice
DISTVERSIONPREFIX=	v
DISTVERSION=	1.03
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Real-time noise suppression plugin
WWW=		https://github.com/werman/noise-suppression-for-voice

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	juce>0:devel/juce \
		lv2>0:audio/lv2
LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		cmake compiler:c11 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	werman

CMAKE_OFF=	BUILD_VST_PLUGIN # https://github.com/werman/noise-suppression-for-voice/issues/65
CXXFLAGS+=	-DJUCE_CUSTOM_VST3_SDK=1

PLIST_SUB=	XARCH=${ARCH:S/amd64/x86_64/}

post-extract: # remove bundled JUCE
	@${RM} -rf ${WRKSRC}/external/JUCE

post-install: # move plugins to a proper place: workaround for https://github.com/juce-framework/JUCE/issues/1237
	# LV2 plugin
	@${MV} ${STAGEDIR}${WRKDIR}/.lv2 ${STAGEDIR}${PREFIX}/lib/lv2
	# VST3 plugin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst3
	@${MV} `${FIND} ${STAGEDIR} -name rnnoise.vst3` ${STAGEDIR}${PREFIX}/lib/vst3
	# remove empty directories
	@${FIND} ${STAGEDIR} -type d -empty -delete
	# strip binaries
	cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
		lib/lv2/rnnoise_mono.lv2/librnnoise_mono.so \
		lib/lv2/rnnoise_stereo.lv2/librnnoise_stereo.so \
		lib/vst3/rnnoise.vst3/Contents/*/rnnoise.so

# the LADSPA plugin can be used directly from PulseAudio's config file

.include <bsd.port.mk>
