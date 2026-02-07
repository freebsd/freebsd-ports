PORTNAME=	odin2-synthesizer
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.4-13
DISTVERSIONSUFFIX=	-gc8d3861f
PORTREVISION=	2
CATEGORIES=	audio multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Polyphonic synthesizer
WWW=		https://thewavewarden.com/pages/odin-2 \
		https://github.com/TheWaveWarden/odin2

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=279134

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfreetype.so:print/freetype2

USES=		gl cmake localbase:ldflags pkgconfig xorg
USE_GL=		gl
USE_XORG=	x11 xcursor xext xinerama xrandr xrender # for juce

USE_GITHUB=	yes
GH_ACCOUNT=	TheWaveWarden
GH_PROJECT=	odin2
GH_TUPLE=	surge-synthesizer:tuning-library:8eb7232ac24ac2f97a052063161c0c4f5fd763e3:surge_synthesizer_tuning_library/libs/tuning-library \
		juce-framework:JUCE:53b04877c6ebc7ef3cb42e84cb11a48e0cf809b5:juce_framework_JUCE/libs/JUCE \
		free-audio:clap-juce-extensions:f11e8c3284e7ff2629534148cbd98da9f602bfea:free_audio_clap_juce_extensions/libs/clap-juce-extensions \
			free-audio:clap:84ad6fe9739d3070ed0eb05c24be303a899ab813:free_audio_clap/libs/clap-juce-extensions/clap-libs/clap \
			free-audio:clap-helpers:2bb43c18788c689708ead6f127a2d75e772ab389:free_audio_clap_helpers/libs/clap-juce-extensions/clap-libs/clap-helpers \
		lv2-porting-project:JUCE:b8fb637be2f7d6bb3bd2f104c4c798ec79b2f2f1:lv2_porting_project_JUCE/libs/JUCELV2

CXXFLAGS+=	-DJUCE_CUSTOM_VST3_SDK=1

post-patch: # remove PLUGIN_API: -DPLUGIN_API= doesn't work for some reason
	@${FIND} ${WRKSRC} -name "*.h" -o -name "*.cpp" | ${XARGS} ${REINPLACE_CMD} -i '' -e 's| PLUGIN_API | |'

do-install:
	# LV2 plugin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/lv2
	cd ${BUILD_WRKSRC}/Odin2_artefacts/Release/LV2 && ${COPYTREE_SHARE} Odin2.lv2 ${STAGEDIR}${PREFIX}/lib/lv2
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/Odin2.lv2/Odin2.so
	# CLAP plugin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/clap
	${INSTALL_DATA} ${BUILD_WRKSRC}/Odin2_artefacts/Release/CLAP/Odin2.clap ${STAGEDIR}${PREFIX}/lib/clap
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/clap/Odin2.clap
	# VST3 plugin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst
	${INSTALL_LIB} ${BUILD_WRKSRC}/Odin2_artefacts/Release/VST3/Odin2.vst3/Contents/*/Odin2.so ${STAGEDIR}${PREFIX}/lib/vst

.include <bsd.port.mk>
