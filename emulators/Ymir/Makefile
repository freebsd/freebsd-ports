PORTNAME=	Ymir
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.6
CATEGORIES=	emulators

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Sega Saturn emulator
WWW=		https://github.com/StrikerX3/Ymir/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		https://github.com/StrikerX3/Ymir/pull/389 \
			https://github.com/StrikerX3/Ymir/pull/421 \
			https://github.com/llvm/llvm-project/issues/69524
ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	upstream only supports aarch64 and amd64

BUILD_DEPENDS=	cereal>0:devel/cereal \
		concurrentqueue>0:devel/concurrentqueue \
		cxxopts>0:devel/cxxopts \
		glslangValidator:graphics/glslang \
		glslc:graphics/shaderc \
		stb>0:devel/stb \
		tomlplusplus>0:devel/tomlplusplus \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libchdr.so:devel/libchdr \
		libfmt.so:devel/libfmt \
		libglfw.so:graphics/glfw \
		libimgui.so:x11-toolkits/imgui \
		liblz4.so:archivers/liblz4 \
		librtmidi.so:audio/rtmidi \
		libvulkan.so:graphics/vulkan-loader \
		libxxhash.so:devel/xxhash

FLAVORS=			gtk3 gtk4
FLAVOR?=			${FLAVORS:[1]}
gtk4_PKGNAMESUFFIX=		-gtk4
_gtk3_BR_DEPENDS=		zenity:x11/zenity
_gtk4_BR_DEPENDS=		zenity:x11/zenity4
${FLAVOR}_BUILD_DEPENDS=	${_${FLAVOR}_BR_DEPENDS}
${FLAVOR}_RUN_DEPENDS=		${_${FLAVOR}_BR_DEPENDS}

USES=		cmake compiler:c++20-lang gl llvm pkgconfig sdl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	StrikerX3
GH_TUPLE=	StrikerX3:mio:c9dbe3a6f74b2c2c4a6c9621005c3df213a33eaa:mio/vendor/mio
USE_GL=		glut
USE_SDL=	sdl3
USE_XORG=	xi xmu

CMAKE_OFF=	Ymir_DEV_BUILD \
		Ymir_ENABLE_IMGUI_DEMO \
		Ymir_ENABLE_SANDBOX \
		Ymir_ENABLE_TESTS \
		Ymir_INCLUDE_PACKAGING \
		Ymir_SHARED_LIBS

CFLAGS+=	-I${LOCALBASE}/include/concurrentqueue/moodycamel \
		-I${LOCALBASE}/include/stb \
		-I${WRKSRC}/vendor/imgui/ymir

PLIST_FILES=	bin/ymir-sdl3 \
		share/applications/io.github.strikerx3.ymir.desktop \
		share/icons/hicolor/256x256/apps/ymir.png \
		share/metainfo/io.github.strikerx3.ymir.xml

OPTIONS_DEFINE=		LTO YMDASM
OPTIONS_DEFAULT=	LTO

YMDASM_DESC=		Include Ymir disassembly tool

LTO_CMAKE_BOOL=		Ymir_ENABLE_IPO

YMDASM_CMAKE_BOOL=	Ymir_ENABLE_YMDASM
YMDASM_PLIST_FILES=	bin/ymdasm

post-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/apps/ymir-sdl3/ymir-sdl3-${DISTVERSION} \
		${STAGEDIR}${PREFIX}/bin/ymir-sdl3
	${INSTALL_DATA} ${WRKSRC}/apps/ymir-sdl3/res/io.github.strikerx3.ymir.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps \
		 ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/apps/ymir-sdl3/res/ymir.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${INSTALL_DATA} ${WRKSRC}/apps/ymir-sdl3/res/io.github.strikerx3.ymir.xml \
		${STAGEDIR}${PREFIX}/share/metainfo

post-install-YMDASM-on:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/apps/ymdasm/ymdasm-${DISTVERSION} \
		${STAGEDIR}${PREFIX}/bin/ymdasm

.include <bsd.port.mk>
