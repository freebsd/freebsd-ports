# $FreeBSD$

PORTNAME=	ppsspp
DISTVERSIONPREFIX=	v
DISTVERSION?=	1.11.3
PORTREVISION?=	0
CATEGORIES=	emulators
# XXX Get from Debian once #697821 lands
MASTER_SITES=	https://bazaar.launchpad.net/~sergio-br2/${PORTNAME}/debian-sdl/download/5/${PORTNAME}.1-20140802045408-dd26dik367ztj5xg-8/:manpage
DISTFILES=	${PORTNAME}.1:manpage
EXTRACT_ONLY=	${DISTFILES:N*\:manpage:C/:.*//}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	PSP emulator in C++ with dynarec JIT for x86, ARM, MIPS

LICENSE=	GPLv2+

# Bi-endian architectures default to big for some reason
NOT_FOR_ARCHS=	mips mips64 powerpc powerpc64 powerpcspe sparc64
NOT_FOR_ARCHS_REASON=	only little-endian is supported, see \
		https://github.com/hrydgard/ppsspp/issues/8823

LIB_DEPENDS=	libzip.so:archivers/libzip \
		libsnappy.so:archivers/snappy \
		libavcodec.so:multimedia/ffmpeg
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USE_GITHUB=	yes
GH_ACCOUNT=	hrydgard
GH_TUPLE?=	hrydgard:glslang:8.13.3559-76-gd0850f87:glslang/ext/glslang \
		hrydgard:miniupnp:miniupnpd_2_1-354-g7e229dd:miniupnp/ext/miniupnp \
		hrydgard:${PORTNAME}-lang:6bd5b4b:lang/assets/lang \
		KhronosGroup:SPIRV-Cross:2019-05-20-60-ga1f7c8dc:SPIRV/ext/SPIRV-Cross \
		Kingcom:armips:v0.10.0-28-g7885552:armips/ext/armips

CONFLICTS_INSTALL=	${PORTNAME}-*

USES=		cmake compiler:c++11-lib gl localbase:ldflags pkgconfig
EXCLUDE=	libzip zlib
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ,}
USE_GL=		gl glew glu
CMAKE_ON=	USE_SYSTEM_FFMPEG USE_SYSTEM_LIBZIP USE_SYSTEM_SNAPPY USE_WAYLAND_WSI
CMAKE_OFF=	USE_DISCORD
SUB_FILES=	pkg-message
PORTDATA=	assets

DESKTOP_ENTRIES="PPSSPP" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME} %f" \
		"Game;Emulator;" \
		""

OPTIONS_DEFINE=	VULKAN
OPTIONS_DEFAULT=VULKAN
OPTIONS_SINGLE=	GUI
OPTIONS_SINGLE_GUI=	LIBRETRO QT5 SDL
OPTIONS_SLAVE?=	SDL
OPTIONS_EXCLUDE:=	${OPTIONS_EXCLUDE} ${OPTIONS_SINGLE_GUI}

LIBRETRO_DESC=	libretro core for games/retroarch
LIBRETRO_CMAKE_BOOL=	LIBRETRO
LIBRETRO_PLIST_FILES=	lib/libretro/${PORTNAME}_libretro.so
LIBRETRO_VARS=	CONFLICTS_INSTALL= DESKTOP_ENTRIES= PLIST= PORTDATA= PKGMESSAGE= SUB_FILES=
QT5_USES=	qt:5 sdl
QT5_USE=	QT=qmake_build,buildtools_build,linguisttools_build,gui,multimedia,opengl,widgets
QT5_USE+=	SDL=sdl2 # audio, joystick
QT5_CMAKE_BOOL=	USING_QT_UI
QT5_VARS=	EXENAME=PPSSPPQt
SDL_BUILD_DEPENDS=	png>=1.6:graphics/png
SDL_LIB_DEPENDS=	libpng.so:graphics/png
SDL_USES=	sdl
SDL_USE=	SDL=sdl2
SDL_VARS=	EXENAME=PPSSPPSDL
VULKAN_DESC=		Vulkan renderer
VULKAN_RUN_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

post-patch:
	@${REINPLACE_CMD} -e 's/Linux/${OPSYS}/' \
		${WRKSRC}/assets/gamecontrollerdb.txt
	@${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,' \
		${WRKSRC}/UI/NativeApp.cpp
	@${REINPLACE_CMD} -e 's/"unknown"/"${DISTVERSIONFULL}"/' \
		${WRKSRC}/git-version.cmake

do-install-QT5-on do-install-SDL-on:
	${MV} ${STAGEDIR}${PREFIX}/bin/${EXENAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${_DISTDIR}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

do-install-LIBRETRO-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${LIBRETRO_PLIST_FILES:H}
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/${LIBRETRO_PLIST_FILES:T} \
		${STAGEDIR}${PREFIX}/${LIBRETRO_PLIST_FILES:H}

.include <bsd.port.mk>
