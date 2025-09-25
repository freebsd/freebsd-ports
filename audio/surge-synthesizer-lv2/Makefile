PORTNAME=	surge-synthesizer
DISTVERSIONPREFIX=	release_
DISTVERSION=	1.9.0
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Surge Synthesizer LV2 and VST plug-in
WWW=		https://surge-synthesizer.github.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=		fatal error: error in backend: Cannot select: 0x263f6370: v4f32 = froundeven 0x263f4eb0
BROKEN_powerpc=		compilation fails due to a problem in the clang header, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=276794
BROKEN_powerpc64=	compilation fails due to a problem in the clang header, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=276794
BROKEN_powerpc64le=	compilation fails due to a problem in the clang header, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=276794
BROKEN_riscv64=	error: functions that differ only in their return type cannot be overloaded - simde-related, see https://github.com/simd-everywhere/simde/issues/962

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/nanosvg.h:graphics/nanosvg \
		${LOCALBASE}/include/simde/simde-common.h:devel/simde \
		xcb-util-keysyms>0:x11/xcb-util-keysyms \
		bash:shells/bash
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libmidifile.so:audio/midifile \
		libsamplerate.so:audio/libsamplerate \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-util.so:x11/xcb-util

USES=		cmake compiler:c++17-lang gnome localbase:ldflags pkgconfig python:build shebangfix xorg
SHEBANG_FILES=	build-linux.sh scripts/linux/package-vst3.sh
USE_GNOME=	cairo
USE_XORG=	x11 xcb

USE_GITHUB=	yes
GH_PROJECT=	surge

CXXFLAGS+=	-I${LOCALBASE}/include/midifile # see https://github.com/surge-synthesizer/surge/issues/4358
LDFLAGS+=	-lmidifile

GH_TUPLE=	\
		ODDSound:MTS-ESP:2ec61b5:MTS_ESP/libs/oddsound-mts/MTS-ESP \
		surge-synthesizer:eurorack:1e9e12f:eurorack/libs/eurorack/eurorack \
		surge-synthesizer:vst3sdk:10287bc37bbb34324b8097369e2ec4eb73a51d65:surge_synthesizer_vst3sdk/vst3sdk \
		surge-synthesizer:vstgui:1bcbae8:surge_synthesizer_vstgui/vstgui.surge \
		surge-synthesizer:tuning-library:cec555c:surge_synthesizer_tuning_library/libs/tuning-library \
		steinbergmedia:vst3_base:37dbdb6ff7af29e518877f57f14050594164a0d6:steinbergmedia_vst3_base/vst3sdk/base \
		steinbergmedia:vst3_cmake:f7ae22417019aa355de6f7ec46ecf890d3c2a76f:steinbergmedia_vst3_cmake/vst3sdk/cmake \
		steinbergmedia:vst3_pluginterfaces:6c6bb30d18c3d5a553e55aa74afc5d146571be0a:steinbergmedia_vst3_pluginterfaces/vst3sdk/pluginterfaces \
		steinbergmedia:vst3_public_sdk:ced72c00d5c1365a4cca16cdbfb871be2496848b:steinbergmedia_vst3_public_sdk/vst3sdk/public.sdk \

LDFLAGS+=	-lexecinfo

CMAKE_ARGS_aarch64=	-DLINUX_ON_ARM:BOOL=ON
CMAKE_ARGS_armv7=	-DLINUX_ON_ARM:BOOL=ON
CMAKE_ARGS+=	${CMAKE_ARGS_${ARCH}}

BINARY_ALIAS=	python=${PYTHON_CMD} # git=false

PORTSCOUT=	ignore:1

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr/share/Surge/"|"${DATADIR}/"|' ${WRKSRC}/src/common/SurgeStorage.cpp

do-install: # https://github.com/surge-synthesizer/surge/issues/4359
	# LV2 plugin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/lv2
	cd ${BUILD_WRKSRC}/surge_products && ${COPYTREE_SHARE} Surge.lv2 ${STAGEDIR}${PREFIX}/lib/lv2
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/Surge.lv2/Surge.so
	# VST plugin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst
	${INSTALL_LIB} ${BUILD_WRKSRC}/surge_products/Surge.vst3/Contents/*/Surge.so ${STAGEDIR}${PREFIX}/lib/vst
	# data
	cd ${WRKSRC}/resources/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${RM} ${STAGEDIR}${DATADIR}/WHERE\ TO\ PLACE\ USER\ DATA.txt

.include <bsd.port.mk>
