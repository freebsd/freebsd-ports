# $FreeBSD$

PORTNAME=	surge-synthesizer
DISTVERSIONPREFIX=	release_
DISTVERSION=	1.8.0
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Surge Synthesizer LV2 and VST plug-in

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_11=	error: use of undeclared identifier 'getline'; did you mean 'std::getline'?

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/nanosvg.h:graphics/nanosvg \
		${LOCALBASE}/include/simde/simde-common.h:devel/simde \
		xcb-util-keysyms>0:x11/xcb-util-keysyms
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libmidifile.so:audio/midifile \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-util.so:x11/xcb-util

USES=		cmake compiler:c++17-lang gnome localbase:ldflags pkgconfig python:build shebangfix xorg
SHEBANG_FILES=	build-linux.sh
USE_GNOME=	cairo
USE_XORG=	x11 xcb

USE_GITHUB=	yes
GH_PROJECT=	surge

CXXFLAGS+=	-I${LOCALBASE}/include/midifile
LDFLAGS+=	-lmidifile

GH_TUPLE=	\
		surge-synthesizer:vst3sdk:10287bc37bbb34324b8097369e2ec4eb73a51d65:surge_synthesizer_vst3sdk/vst3sdk \
		surge-synthesizer:vstgui:8abd688c76edfb7215413080960649a532a6755c:surge_synthesizer_vstgui/vstgui.surge \
		surge-synthesizer:tuning-library:d9660eff4b59cafb9dcd712864b6c8af536089bc:surge_synthesizer_tuning_library/libs/tuning-library \
		steinbergmedia:vst3_base:37dbdb6ff7af29e518877f57f14050594164a0d6:steinbergmedia_vst3_base/vst3sdk/base \
		steinbergmedia:vst3_cmake:f7ae22417019aa355de6f7ec46ecf890d3c2a76f:steinbergmedia_vst3_cmake/vst3sdk/cmake \
		steinbergmedia:vst3_pluginterfaces:6c6bb30d18c3d5a553e55aa74afc5d146571be0a:steinbergmedia_vst3_pluginterfaces/vst3sdk/pluginterfaces \
		steinbergmedia:vst3_public_sdk:ced72c00d5c1365a4cca16cdbfb871be2496848b:steinbergmedia_vst3_public_sdk/vst3sdk/public.sdk \

LDFLAGS+=	-lexecinfo

BINARY_ALIAS=	python=${PYTHON_CMD} # git=false

PORTSCOUT=	limit:^\d+\. # prevent alpha-numeric strings

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr/share/Surge/"|"${DATADIR}/"|' ${WRKSRC}/src/common/SurgeStorage.cpp

do-install:
	# LV2 plugin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/lv2
	cd ${BUILD_WRKSRC}/surge_products && ${COPYTREE_SHARE} Surge.lv2 ${STAGEDIR}${PREFIX}/lib/lv2
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/Surge.lv2/Surge.so
	# VST plugin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst
	${INSTALL_LIB} ${BUILD_WRKSRC}/surge_products/Surge.vst3/Contents/*/Surge.so ${STAGEDIR}${PREFIX}/lib/vst
	# data
	cd ${WRKSRC}/resources/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
