PORTNAME=	vst3sdk
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.7_build_19
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	VST3 SDK (VST3 audio plugins Software Development Kit)
WWW=		https://github.com/steinbergmedia/vst3sdk

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	fails to build: static_assert failed due to requirement 'alignof(Steinberg::Vst::ProcessContext) == (0 ? 8U : 0 ? 1U : 1 ? 8U : 8U)
BROKEN_FreeBSD_14=	fails to compile: 'experimental/filesystem' file not found

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-util.so:x11/xcb-util \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++14-lang gnome localbase:ldflags pkgconfig shebangfix xorg
USE_GNOME=	cairo gtk30 gtkmm30
USE_XORG=	ice sm x11 xcb xext

USE_GITHUB=	yes
GH_ACCOUNT=	steinbergmedia
GH_TUPLE=	\
		steinbergmedia:vst3_base:ea2bac9:steinbergmedia_vst3_base/base \
		steinbergmedia:vst3_cmake:bd2a55a:steinbergmedia_vst3_cmake/cmake \
		steinbergmedia:vst3_doc:d5397c9:steinbergmedia_vst3_doc/doc \
		steinbergmedia:vst3_pluginterfaces:bc5ff0f:steinbergmedia_vst3_pluginterfaces/pluginterfaces \
		steinbergmedia:vst3_public_sdk:bbb0538:steinbergmedia_vst3_public_sdk/public.sdk \
		steinbergmedia:vstgui:91c4105:steinbergmedia_vstgui/vstgui4

SHEBANG_FILES=	vstgui4/vstgui/uidescription/editing/createuidescdata.sh

PORTSCOUT=	limit:^.*\d\.\d # prevent tags like vstsdk370_31_07_2020_build_116

do-install: # workaround for https://github.com/steinbergmedia/vst3sdk/issues/77
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.for dir in base pluginterfaces public.sdk
	${INSTALL_DATA} `${FIND} ${WRKSRC}/${dir} \( -type f -iname "*.cpp" -or -iname "*.h" \)` ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst3
	${INSTALL_LIB} `${FIND} ${BUILD_WRKSRC} -type f -name "*.so"` ${STAGEDIR}${PREFIX}/lib/vst3
	${INSTALL_DATA} `${FIND} -X ${BUILD_WRKSRC} -type f -name "*.png" -o -iname "*.uidesc"` ${STAGEDIR}${PREFIX}/lib/vst3

.include <bsd.port.mk>
