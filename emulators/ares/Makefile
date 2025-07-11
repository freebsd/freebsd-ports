PORTNAME=	ares
DISTVERSIONPREFIX=	v
DISTVERSION=	145
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/${PORTNAME}-emulator/${PORTNAME}/releases/download/${DISTVERSIONFULL}/
DISTNAME=	${PORTNAME}-source

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Multi-system emulator
WWW=		https://ares-emu.net

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	librashader>0:devel/librashader

USES=		cmake compiler:c++17-lang gl gnome pkgconfig xorg
USE_GL=		opengl
USE_GNOME=	gtk30
USE_XORG=	x11 xext xrandr xrender

CMAKE_ARGS=	-DARES_CORES="${_CORES:S/ /;/gW}" \
		-DENABLE_CCACHE=${CCACHE_ENABLED}
CMAKE_ON=	ARES_BUILD_OFFICIAL \
		ARES_SKIP_DEPS \
		ARES_UNITY_CORES
CMAKE_OFF=	ARES_BUILD_LOCAL \
		ARES_BUNDLE_SHADERS \
		ARES_ENABLE_MINIMUM_CPU

EXTRACT_AFTER_ARGS=	--exclude thirdparty/librashader \
			--no-same-owner --no-same-permissions

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFINE=			CHD SDL TOOLS
OPTIONS_DEFAULT=		A26 ALSA AO CHD CV FC GB GBA LIBRASHADER \
				LIBRETRO LTO MD MS MSX MYVISION N64 NG NGP \
				OPENAL OPTIMIZED_CFLAGS OSS PCE PS1 SDL SFC SG \
				SPEC UDEV USBHID WS
OPTIONS_GROUP=			AUDIO CORES INPUT OPTIMIZATION SHADER
OPTIONS_GROUP_AUDIO=		ALSA AO OPENAL OSS PULSEAUDIO
OPTIONS_GROUP_CORES=		A26 CV FC GB GBA MD MS MSX MYVISION N64 NG NGP \
				PCE PS1 SFC SG SPEC WS
OPTIONS_GROUP_INPUT=		HOTKEYS UDEV USBHID
OPTIONS_GROUP_OPTIMIZATION=	ACCURACY LTO OPTIMIZED_CFLAGS
OPTIONS_GROUP_SHADER=		LIBRASHADER LIBRETRO

# linking openal fails on i386, LLD_UNSAFE workaround fails with
# /usr/local/bin/i386-unknown-freebsd14.1-ld.bfd: /usr/bin/../lib/LLVMgold.so:
# error loading plugin: Cannot open "/usr/bin/../lib/LLVMgold.so"
# on tools/sourcery target, so exclude OPENAL on i386
OPTIONS_EXCLUDE_i386=	OPENAL

OPTIONS_SUB=	yes

A26_DESC=		Atari 2600
ACCURACY_DESC=		Emulation accuracy over performance
CHD_DESC=		CHD format support via libchdr
CV_DESC=		ColecoVision
FC_DESC=		NES / Famicom
GBA_DESC=		Game Boy Advance
GB_DESC=		Game Boy / Game Boy Color
HOTKEYS_DESC=		Inofficial hotkeys locking patch
LIBRASHADER_DESC=	Slang-shader support via librashader
LIBRETRO_DESC=		Install slang-shaders from libretro (implies ${LIBRETRO_IMPLIES})
MD_DESC=		Sega Mega Drive / Genesis
MSX_DESC=		Microsoft MSX
MS_DESC=		Sega Master System / Mark III
MYVISION_DESC=		My Vision
N64_DESC=		Nintendo 64
NGP_DESC=		Neo Geo Pocket / Neo Geo Pocket Color
NG_DESC=		Neo Geo (AES/MVS)
PCE_DESC=		PC-Engine / TurboGrafx
PS1_DESC=		PlayStation
SFC_DESC=		SNES / Super Famicom
SG_DESC=		Sega SG-1000
SPEC_DESC=		ZX Spectrum
TOOLS_DESC=		Include supplemental tools and tests
UDEV_DESC=		Input support via UDEV
USBHID_DESC=		Input support via USBHID
WS_DESC=		WonderSwan / WonderSwan Color

A26_VARS=			_CORES+=a26

ACCURACY_CMAKE_BOOL=		ARES_PROFILE_ACCURACY

ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=		ARES_ENABLE_ALSA

AO_LIB_DEPENDS=			libao.so:audio/libao
AO_CMAKE_BOOL=			ARES_ENABLE_AO

CHD_CMAKE_BOOL=			ARES_ENABLE_CHD \
				WITH_SYSTEM_ZLIB

CV_VARS=			_CORES+=cv

FC_VARS=			_CORES+=fc

GBA_VARS=			_CORES+=gba

GB_VARS=			_CORES+=gb

HOTKEYS_EXTRA_PATCHES=		${PATCHDIR}/extra-patch-desktop-ui_input_hotkeys.cpp

LIBRASHADER_LIB_DEPENDS=	librashader.so:devel/librashader
LIBRASHADER_CMAKE_BOOL=		ARES_ENABLE_LIBRASHADER

LIBRETRO_IMPLIES=		LIBRASHADER
_LIBRETRO_BR_DEPENDS=		libretro-shaders-slang<0:games/libretro-shaders-slang
LIBRETRO_BUILD_DEPENDS=		${_LIBRETRO_BR_DEPENDS}
LIBRETRO_RUN_DEPENDS=		${_LIBRETRO_BR_DEPENDS}

LTO_CMAKE_BOOL=			ENABLE_IPO

MD_VARS=			_CORES+=md

MSX_VARS=			_CORES+=msx

MS_VARS=			_CORES+=ms

MYVISION_VARS=			_CORES+=myvision

_N64_BR_DEPENDS=		vulkan-loader>0:graphics/vulkan-loader
N64_BUILD_DEPENDS=		${_N64_BR_DEPENDS}
N64_RUN_DEPENDS=		${_N64_BR_DEPENDS}
N64_VARS=			_CORES+=n64

NGP_VARS=			_CORES+=ngp

NG_VARS=			_CORES+=ng

OPENAL_USES=			openal
OPENAL_CMAKE_BOOL=		ARES_ENABLE_OPENAL

OPTIMIZED_CFLAGS_CFLAGS=	-O3

OSS_CMAKE_BOOL=			ARES_ENABLE_OSS

PCE_VARS=			_CORES+=pce

PS1_VARS=			_CORES+=ps1

PULSEAUDIO_LIB_DEPENDS=		libpulse-simple.so:audio/pulseaudio \
				libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=		ARES_ENABLE_PULSEAUDIO

SDL_USES=			sdl
SDL_USE=			SDL=sdl3
SDL_CMAKE_BOOL=			ARES_ENABLE_SDL

SFC_VARS=			_CORES+=sfc

SG_VARS=			_CORES+=sg

SPEC_VARS=			_CORES+=spec

# https://github.com/ares-emulator/ares/issues/2090
TOOLS_IMPLIES=			GBA MD NG SFC
TOOLS_CMAKE_BOOL=		ARES_BUILD_OPTIONAL_TARGETS

UDEV_LIB_DEPENDS=		libudev.so:devel/libudev-devd
UDEV_CMAKE_BOOL=		ARES_ENABLE_UDEV

USBHID_CMAKE_BOOL=		ARES_ENABLE_USBHID

WS_VARS=			_CORES+=ws

post-patch:
	${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/cmake/finders/*

post-install-LIBRETRO-on:
	${LN} -s ${LOCALBASE}/share/libretro/shaders/shaders_slang ${STAGEDIR}${DATADIR}/Shaders

.include <bsd.port.mk>
