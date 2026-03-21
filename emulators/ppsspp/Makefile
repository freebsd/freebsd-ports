PORTNAME=	ppsspp
DISTVERSIONPREFIX=	v
DISTVERSION?=	1.20.2
CATEGORIES=	emulators

MAINTAINER=	kreinholz@gmail.com
COMMENT=	PSP emulator in C++ with dynarec JIT for x86, ARM, MIPS
WWW=		https://www.ppsspp.org/

LICENSE=	GPLv2+ BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

# Bi-endian architectures default to big for some reason
NOT_FOR_ARCHS=	mips mips64 powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	only little-endian is supported, see \
		https://github.com/hrydgard/ppsspp/issues/8823

BUILD_DEPENDS=	${LOCALBASE}/ffmpeg3/lib/libavcodec.a:multimedia/ffmpeg3 \
		rapidjson>0:devel/rapidjson

LIB_DEPENDS=	libzip.so:archivers/libzip \
		libsnappy.so:archivers/snappy \
		libzstd.so:archivers/zstd \
		libminiupnpc.so:net/miniupnpc \
		libopenxr_loader.so:graphics/openxr \
		libfreetype.so:print/freetype2 \
		libchdr.so:devel/libchdr
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		cmake compiler:c++11-lib gl localbase:ldflags pkgconfig \
		desktop-file-utils
USE_GITHUB=	yes
GH_ACCOUNT=	hrydgard
GH_TUPLE?=	Kingcom:armips:v0.11.0-195-ga8d71f0:armips/ext/armips \
                hrydgard:glslang:2.3-3991-g50e0708e:glslang/ext/glslang \
                KhronosGroup:SPIRV-Cross:4212eef67ed0ca048cb726a6767185504e7695e5:SPIRVCross/ext/SPIRV-Cross \
		unknownbrackets:ppsspp-debugger:9776332f720c854ef26f325a0cf9e32c02115a9c:ppssppdebugger/assets/debugger \
		google:cpu_features:v0.4.1-211-gfd4ffc1:cpu_features/ext/cpu_features \
		RetroAchievements:rcheevos:v12.3.0:rcheevos/ext/rcheevos \
		erkkah:naett:5f695cfa9fcbf30668a4d3ac4b4abf1cd89a1302:naett/ext/naett \
		hrydgard:ppsspp-lua:7648485f14e8e5ee45e8e39b1eb4d3206dbd405a:ppsspplua/ext/lua \
		hrydgard:nanosvg:478dbb8f7ed11c3d9b20b3986a8ee2283f483ef7:nanosvg/ext/nanosvg \
		Kethen:aemu_postoffice:f5ae0ce8cac89cfc592047925f2064a84536eeb4:aemu_postoffice/ext/aemu_postoffice \
		Kingcom:filesystem:v1.3.2-12-g3f1c185:filesystem/ext/armips/ext/filesystem \
		libretro:libretro-common:76a3d54feb0ee0ce9d59b90aa24694f3782063d3:libretrocommon/libretro/libretro-common
EXCLUDE=	libzip zlib
USE_GL=		glew opengl
CMAKE_ON=	${FREETYPE LIBCHDR LIBZIP MINIUPNPC RAPIDJSON SNAPPY \
		ZSTD:L:S/^/USE_SYSTEM_/} USE_VULKAN_DISPLAY_KHR
CMAKE_OFF=	USE_DISCORD
LDFLAGS+=	-Wl,--as-needed # ICE/SM/X11/Xext
CONFLICTS_INSTALL=	${PORTNAME}-*
DESKTOP_ENTRIES=	"PPSSPP" \
			"" \
			"${PORTNAME}" \
			"${PORTNAME} %f" \
			"Game;Emulator;" \
			""
EXTRACT_AFTER_ARGS=	${EXCLUDE:S,^,--exclude ,}
SUB_FILES=	pkg-message
PORTDATA=	assets

OPTIONS_DEFINE=		VULKAN
OPTIONS_DEFAULT=	VULKAN
OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	LIBRETRO SDL
OPTIONS_EXCLUDE:=	${OPTIONS_EXCLUDE} ${OPTIONS_SINGLE_GUI}
OPTIONS_SLAVE?=		SDL

LIBRETRO_DESC=		libretro core for games/retroarch
VULKAN_DESC=		Vulkan renderer
LIBRETRO_LIB_DEPENDS=	libpng.so:graphics/png
LIBRETRO_CMAKE_BOOL=	LIBRETRO
LIBRETRO_PLIST_FILES=	lib/libretro/${PORTNAME}_libretro.so
LIBRETRO_VARS=		CONFLICTS_INSTALL= DESKTOP_ENTRIES= PLIST= PORTDATA= PKGMESSAGE= SUB_FILES=
SDL_CATEGORIES=		wayland
SDL_LIB_DEPENDS=	libpng.so:graphics/png
SDL_USES=		shared-mime-info sdl
SDL_USE=		SDL=sdl2
SDL_VARS=		EXENAME=PPSSPPSDL
VULKAN_RUN_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

post-patch:
	@${REINPLACE_CMD} -e 's/Linux/${OPSYS}/' ${WRKSRC}/assets/gamecontrollerdb.txt
	@${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,' ${WRKSRC}/UI/NativeApp.cpp
	@${REINPLACE_CMD} -e 's/"unknown"/"${DISTVERSIONFULL}"/' ${WRKSRC}/git-version.cmake
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/cmake/Modules/FindFFmpeg.cmake

do-install-LIBRETRO-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${LIBRETRO_PLIST_FILES:H}
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/${LIBRETRO_PLIST_FILES:T} \
		${STAGEDIR}${PREFIX}/${LIBRETRO_PLIST_FILES:H}
.if ${OPTIONS_SLAVE} == LIBRETRO
.  for d in applications icons mime ${PORTNAME}
	${RM} -r ${STAGEDIR}${PREFIX}/share/${d}
.  endfor
.endif

do-install-SDL-on:
.if exists(/usr/bin/elfctl)
	${ELFCTL} -e +wxneeded ${STAGEDIR}${PREFIX}/bin/*
.endif
	${MV} ${STAGEDIR}${PREFIX}/bin/${EXENAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
