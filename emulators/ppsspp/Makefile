PORTNAME=	ppsspp
DISTVERSIONPREFIX=	v
DISTVERSION?=	1.17.1
PORTREVISION?=	1
CATEGORIES=	emulators
# XXX Get from Debian once #697821 lands
MASTER_SITES=	https://bazaar.launchpad.net/~sergio-br2/${PORTNAME}/debian-sdl/download/5/${PORTNAME}.1-20140802045408-dd26dik367ztj5xg-8/:manpage
DISTFILES=	${PORTNAME}.1:manpage
EXTRACT_ONLY=	${DISTFILES:N*\:manpage:C/:.*//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PSP emulator in C++ with dynarec JIT for x86, ARM, MIPS
WWW=		https://www.ppsspp.org/

LICENSE=	GPLv2+

# Bi-endian architectures default to big for some reason
NOT_FOR_ARCHS=	mips mips64 powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	only little-endian is supported, see \
		https://github.com/hrydgard/ppsspp/issues/8823

LIB_DEPENDS=	libzip.so:archivers/libzip \
		libsnappy.so:archivers/snappy \
		libzstd.so:archivers/zstd \
		libavcodec.so:multimedia/ffmpeg \
		libminiupnpc.so:net/miniupnpc
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		cmake compiler:c++11-lib gl localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	hrydgard
GH_TUPLE?=	hrydgard:glslang:8.13.3743-948-gb34f619e:glslang/ext/glslang \
		google:cpu_features:v0.8.0-27-gfd4ffc1:cpu_features/ext/cpu_features \
		rtissera:libchdr:26d27ca:libchdr/ext/libchdr \
		unknownbrackets:ppsspp-debugger:9776332:debugger/assets/debugger \
		KhronosGroup:SPIRV-Cross:sdk-1.3.239.0:SPIRV/ext/SPIRV-Cross \
		Kingcom:armips:v0.11.0-195-ga8d71f0:armips/ext/armips \
		Kingcom:filesystem:v1.3.2-12-g3f1c185:filesystem/ext/armips/ext/filesystem \
		RetroAchievements:rcheevos:v11.0.0-26-ge7989c3:rcheevos/ext/rcheevos \
		Tencent:rapidjson:v1.1.0-415-g73063f50:rapidjson/ext/rapidjson
EXCLUDE=	libzip zlib
USE_GL=		glew opengl
CMAKE_ON=	${FFMPEG LIBZIP MINIUPNPC SNAPPY ZSTD:L:S/^/USE_SYSTEM_/} USE_VULKAN_DISPLAY_KHR
CMAKE_OFF=	USE_DISCORD
LDFLAGS+=	-Wl,--as-needed # ICE/SM/X11/Xext, Qt5Network
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
OPTIONS_SINGLE_GUI=	LIBRETRO QT5 SDL
OPTIONS_EXCLUDE:=	${OPTIONS_EXCLUDE} ${OPTIONS_SINGLE_GUI}
OPTIONS_SLAVE?=		SDL

LIBRETRO_DESC=		libretro core for games/retroarch
VULKAN_DESC=		Vulkan renderer
LIBRETRO_LIB_DEPENDS=	libpng.so:graphics/png
LIBRETRO_CMAKE_BOOL=	LIBRETRO
LIBRETRO_PLIST_FILES=	lib/libretro/${PORTNAME}_libretro.so
LIBRETRO_VARS=		CONFLICTS_INSTALL= DESKTOP_ENTRIES= PLIST= PORTDATA= PKGMESSAGE= SUB_FILES=
QT5_LIB_DEPENDS=	libpng.so:graphics/png
QT5_USES=		desktop-file-utils elfctl qt:5 shared-mime-info sdl
QT5_USE=		QT=qmake:build,buildtools:build,linguisttools:build,core,gui,multimedia,opengl,widgets
QT5_USE+=		SDL=sdl2 # audio, joystick
QT5_CMAKE_BOOL=		USING_QT_UI
QT5_VARS=		EXENAME=PPSSPPQt ELF_FEATURES=+wxneeded:PPSSPPQt
SDL_CATEGORIES=		wayland
SDL_LIB_DEPENDS=	libpng.so:graphics/png
SDL_USES=		elfctl shared-mime-info sdl
SDL_USE=		SDL=sdl2
SDL_VARS=		EXENAME=PPSSPPSDL ELF_FEATURES=+wxneeded:PPSSPPSDL
VULKAN_RUN_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

post-patch:
	@${REINPLACE_CMD} -e 's/Linux/${OPSYS}/' ${WRKSRC}/assets/gamecontrollerdb.txt
	@${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,' ${WRKSRC}/UI/NativeApp.cpp
	@${REINPLACE_CMD} -e 's/"unknown"/"${DISTVERSIONFULL}"/' ${WRKSRC}/git-version.cmake

do-install-LIBRETRO-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${LIBRETRO_PLIST_FILES:H}
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/${LIBRETRO_PLIST_FILES:T} \
		${STAGEDIR}${PREFIX}/${LIBRETRO_PLIST_FILES:H}
.if ${OPTIONS_SLAVE} == LIBRETRO
.  for d in applications icons man mime ${PORTNAME}
	${RM} -r ${STAGEDIR}${PREFIX}/share/${d}
.  endfor
.endif

do-install-QT5-on do-install-SDL-on:
	${MV} ${STAGEDIR}${PREFIX}/bin/${EXENAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${_DISTDIR}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
