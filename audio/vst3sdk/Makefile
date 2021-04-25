PORTNAME=	vst3sdk
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.1_build_50-1
DISTVERSIONSUFFIX=	-g8199057
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	VST3 SDK (VST3 audio plugins Software Development Kit)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	fails to build: static_assert failed due to requirement 'alignof(Steinberg::Vst::ProcessContext) == (0 ? 8U : 0 ? 1U : 1 ? 8U : 8U)
BROKEN_FreeBSD_11=	x11fileselector.cpp:57:9: error: use of undeclared identifier 'getline'; did you mean 'std::getline'?

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
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
		steinbergmedia:vst3_base:7b977c031f42a6bab08e8b10f4f8df0a1f516c38:steinbergmedia_vst3_base/base \
		steinbergmedia:vst3_cmake:ed8d829631a8913143f5c0f4d5d36a31c412e42c:steinbergmedia_vst3_cmake/cmake \
		steinbergmedia:vst3_doc:d8e7317751aaf7ccccbeb4d1e8103c290c2690ca:steinbergmedia_vst3_doc/doc \
		steinbergmedia:vst3_pluginterfaces:fe202edc93e9a01a1f79a614cc9a292dc9bf3e6e:steinbergmedia_vst3_pluginterfaces/pluginterfaces \
		steinbergmedia:vst3_public_sdk:a3a3ed1b1620df0b064564f1fd5423ae110234a0:steinbergmedia_vst3_public_sdk/public.sdk \
		steinbergmedia:vstgui:83c6dc9a548729e121746839da946e2b73781b70:steinbergmedia_vstgui/vstgui4

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
