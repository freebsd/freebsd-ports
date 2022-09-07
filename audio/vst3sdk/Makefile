PORTNAME=	vst3sdk
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.4_build_25
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	VST3 SDK (VST3 audio plugins Software Development Kit)
WWW=		https://github.com/steinbergmedia/vst3sdk

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	fails to build: static_assert failed due to requirement 'alignof(Steinberg::Vst::ProcessContext) == (0 ? 8U : 0 ? 1U : 1 ? 8U : 8U)

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
		steinbergmedia:vst3_base:f69df71891fbc76f872d43d0f3a357c6fb04ae2a:steinbergmedia_vst3_base/base \
		steinbergmedia:vst3_cmake:fe588a391d77711b6d0a7ee83c10e17f1659b1dc:steinbergmedia_vst3_cmake/cmake \
		steinbergmedia:vst3_doc:6f0b515351af4f574e90eb609b38693195d27d67:steinbergmedia_vst3_doc/doc \
		steinbergmedia:vst3_pluginterfaces:2ad397ade5b51007860bedb3b01b8afd2c5f6fba:steinbergmedia_vst3_pluginterfaces/pluginterfaces \
		steinbergmedia:vst3_public_sdk:bc459feee68803346737901471441fd4829ec3f9:steinbergmedia_vst3_public_sdk/public.sdk \
		steinbergmedia:vstgui:6431f630f65f630c52ec1dfbb93d39d40600c41c:steinbergmedia_vstgui/vstgui4 \

SHEBANG_FILES=	vstgui4/vstgui/uidescription/editing/createuidescdata.sh

PORTSCOUT=	limit:^.*\d\.\d # prevent tags like vstsdk370_31_07_2020_build_116

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.for dir in base pluginterfaces public.sdk
	${INSTALL_DATA} `${FIND} ${WRKSRC}/${dir} \( -type f -iname "*.cpp" -or -iname "*.h" \)` ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst3
	${INSTALL_LIB} `${FIND} ${BUILD_WRKSRC} -type f -name "*.so"` ${STAGEDIR}${PREFIX}/lib/vst3
	${INSTALL_DATA} `${FIND} -X ${BUILD_WRKSRC} -type f -name "*.png" -o -iname "*.uidesc"` ${STAGEDIR}${PREFIX}/lib/vst3

.include <bsd.port.mk>
