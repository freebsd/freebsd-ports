# $FreeBSD$

PORTNAME=	sfizz
DISTVERSION=	0.3.2
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SFZ parser and synth C++ library & LV2/VST3 plugins

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=		cmake compiler:c++11-lib localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	sfztools
GH_TUPLE=	\
		abseil:abseil-cpp:df3ea785d8c30a9503321a3d35ee7d35808f190d:abseil_abseil_cpp/external/abseil-cpp \
		steinbergmedia:vst3_base:4f6a7184f20f40a7c940a6717e6e0d8b35eeea63:steinbergmedia_vst3_base/vst/external/VST_SDK/VST3_SDK/base \
		steinbergmedia:vst3_pluginterfaces:227ea1d8f749c6a66dd591582061d58682b4aa9f:steinbergmedia_vst3_pluginterfaces/vst/external/VST_SDK/VST3_SDK/pluginterfaces \
		steinbergmedia:vst3_public_sdk:c04e9bd690f50893742e2a082abab47af2c3efc8:steinbergmedia_vst3_public_sdk/vst/external/VST_SDK/VST3_SDK/public.sdk \
		sfztools:vstgui:c6a7f607c21a7353e922a6d45e54d6c56d5a6745:sfztools_vstgui/vst/external/VST_SDK/VST3_SDK/vstgui4
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		JACK LV2 VST
OPTIONS_DEFAULT=	JACK LV2
OPTIONS_SUB=		yes

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	SFIZZ_JACK

LV2_DESC=		Install the LV2 plugin
LV2_BUILD_DEPENDS=	lv2>0:audio/lv2
LV2_CMAKE_BOOL=		SFIZZ_LV2

VST_DESC=		Install the VST plugin
VST_CMAKE_BOOL=		SFIZZ_VST
VST_BROKEN=		Compilation issues, need to investogate

post-install-LV2-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/sfizz.lv2/sfizz.so

.include <bsd.port.mk>
