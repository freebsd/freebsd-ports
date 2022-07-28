PORTNAME=	sfizz
DISTVERSION=	1.2.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SFZ parser and synth C++ library & LV2/VST3 plugins

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_riscv64=	fails to compile: src/external/atomic_queue/defs.h:45:2: Unknown CPU architecture
BROKEN_i386=	fails to compile: unknown type name 'Elf64_Auxinfo', see https://github.com/sfztools/sfizz/issues/1110

LIB_DEPENDS=	libsndfile.so:audio/libsndfile
RUN_DEPENDS=	zenity:x11/zenity

USES=		cmake compiler:c++17-lang localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	sfztools
GH_TUPLE=	\
		abseil:abseil-cpp:215105818dfde3174fe799600bb0f3cae233d0bf:abseil_abseil_cpp/external/abseil-cpp \
		steinbergmedia:vst3_base:985fe019276ee03c2751a1736ba3b390678e29f2:steinbergmedia_vst3_base/plugins/vst/external/VST_SDK/VST3_SDK/base \
		steinbergmedia:vst3_pluginterfaces:93cef1afb7061e488625045ba5a82abaa83d27fe:steinbergmedia_vst3_pluginterfaces/plugins/vst/external/VST_SDK/VST3_SDK/pluginterfaces \
		steinbergmedia:vst3_public_sdk:9589800ed94573354bc29de45eec5744523fbfcb:steinbergmedia_vst3_public_sdk/plugins/vst/external/VST_SDK/VST3_SDK/public.sdk \
		sfztools:vstgui:630db26be83f8a1d4bd04926fa45ad10995d2b85:sfztools_vstgui/plugins/editor/external/vstgui4 \
		mackron:dr_libs:cac1785cee4abb455817b43d5dee33b49d61be2f:mackron_dr_libs/external/st_audiofile/thirdparty/dr_libs \
		sfztools:stb_vorbis:fc0bd698b26888da0a632da33f4c49b90763e69b:sfztools_stb_vorbis/external/st_audiofile/thirdparty/stb_vorbis \
		sfztools:libaiff:78864a4a2e769e426be8cfd78ae7f5f72e236c33:sfztools_libaiff/external/st_audiofile/thirdparty/libaiff \
		sfztools:sfzt_auwrapper:014311ae45b86571e1ae3aaa03ebbd7db8b3a32e:sfztools_sfzt_auwrapper/plugins/vst/external/sfzt_auwrapper \
		gulrak:filesystem:614bbe87b80435d87ab8791564370e0c1d13627d:gulrak_filesystem/external/filesystem \
		simd-everywhere:simde:98075d0593f539762125dbb215d95e782a6ae344:simd_everywhere_simde/external/simde \
		\
		nemequ:munit:da8f73412998e4f1adf1100dc187533a51af77fd:nemequ_munit/external/simde/test/munit \
		\
		dr-soft:miniaudio:d1a166c83ab445b1c14bc83d37c84e18d172e5f5:dr_soft_miniaudio/external/st_audiofile/thirdparty/dr_libs/tests/external/miniaudio \

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		JACK LV2 VST
OPTIONS_DEFAULT=	JACK LV2 VST
OPTIONS_SUB=		yes

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	SFIZZ_JACK

LV2_DESC=		Install the LV2 plugin
LV2_USES=		gnome xorg
LV2_USE=		GNOME=cairo,glib20,pango XORG=x11,ice,sm,xcb,xext
LV2_BUILD_DEPENDS=	lv2>0:audio/lv2
LV2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz \
			libxcb-cursor.so:x11/xcb-util-cursor \
			libxcb-keysyms.so:x11/xcb-util-keysyms \
			libxcb-util.so:x11/xcb-util \
			libxkbcommon.so:x11/libxkbcommon
LV2_CMAKE_BOOL=		SFIZZ_LV2

VST_DESC=		Install the VST plugin
VST_USES=		${LV2_USES}
VST_USE=		${LV2_USE}
VST_LIB_DEPENDS=	${LV2_LIB_DEPENDS}
VST_CMAKE_BOOL=		SFIZZ_VST

post-install-LV2-on:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/lib/lv2/sfizz.lv2/Contents/Binary/sfizz.so \
		${STAGEDIR}${PREFIX}/lib/lv2/sfizz.lv2/Contents/Binary/sfizz_ui.so

post-install-VST-on:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/lib/vst3/sfizz.vst3/Contents/x86_64-linux/sfizz.so

.include <bsd.port.mk>
