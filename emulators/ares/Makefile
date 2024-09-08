PORTNAME=	ares
DISTVERSIONPREFIX=	v
DISTVERSION=	140
CATEGORIES=	emulators

# committed upstream, remove with next version update
# * contains 'unbreak FreeBSD build'
#   https://github.com/Themaister/Granite/pull/135
# * contains 'NVIDIA fix'
#   https://github.com/ares-emulator/ares/issues/1547
#   https://github.com/Themaister/Granite/issues/133
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	7135646c447ab7eb3eff18132dbddf7dc03135fa.patch:-p1

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Multi-system emulator
WWW=		https://ares-emu.net

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++17-lang gmake gnome localbase:ldflags pkgconfig \
		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	ares-emulator
USE_GNOME=	gtksourceview3
USE_XORG=	x11 xext xrandr

MAKEFILE=	GNUmakefile
MAKE_ARGS=	compiler=${CC} \
		cores= \
		hiro=gtk3-se \
		local=false \
		lto=false \
		prefix=${PREFIX} \
		ruby=video.none \
		sdl2=false \
		symbols=false \
		threaded=true

OPTIONS_DEFINE=		DEBUG DOCS HOTKEYS OPENMP SHADER
OPTIONS_DEFAULT=	A26 ALSA AO CV FC GB GBA GLX MD MS MSX MYVISION N64 NG \
			NGP OPENAL OPENMP OSS PCE PERFORMANCE PS1 SDLAUDIO \
			SDLINPUT SFC SG SHADER SPEC UDEV UHID WS XLIB XVIDEO
OPTIONS_GROUP=		AUDIO CORES INPUT VIDEO
OPTIONS_GROUP_AUDIO=	ALSA AO OPENAL OSS PULSEAUDIO SDLAUDIO
OPTIONS_GROUP_CORES=	A26 CV FC GB GBA MD MS MSX MYVISION N64 NG NGP PCE PS1 \
			SFC SG SPEC WS
OPTIONS_GROUP_INPUT=	SDLINPUT UDEV UHID XLIB
OPTIONS_GROUP_VIDEO=	GLX XVIDEO
OPTIONS_SINGLE=		PROFILE
OPTIONS_SINGLE_PROFILE=	ACCURACY PERFORMANCE

A26_DESC=		Atari 2600
ACCURACY_DESC=		Slower but more accurate
CV_DESC=		ColecoVision
FC_DESC=		NES / Famicom
GBA_DESC=		Game Boy Advance
GB_DESC=		Game Boy
HOTKEYS_DESC=		Inofficial hotkeys locking patch
MD_DESC=		Mega Drive / Genesis
MSX_DESC=		MSX
MS_DESC=		Master System / Mark III
MYVISION_DESC=		My Vision
N64_DESC=		Nintendo 64
NGP_DESC=		Neo Geo Pocket
NG_DESC=		Neo Geo (AES/MVS)
PCE_DESC=		PC-Engine / TurboGrafx
PERFORMANCE_DESC=	Faster but less accurate
PROFILE_DESC=
PS1_DESC=		PlayStation
SDLAUDIO_DESC=		${SDL_DESC}
SDLINPUT_DESC=		${SDL_DESC}
SFC_DESC=		SNES / Super Famicom
SG_DESC=		SG-1000
SHADER_DESC=		Build with shader support
SPEC_DESC=		ZX Spectrum
UDEV_DESC=		UDEV input support
UHID_DESC=		UHID input support
VIDEO_DESC=
WS_DESC=		WonderSwan
XLIB_DESC=		XLIB input support

A26_MAKE_ARGS=		cores+=a26

ACCURACY_MAKE_ARGS=	profile=accuracy

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_MAKE_ARGS=		ruby+=audio.alsa

AO_LIB_DEPENDS=		libao.so:audio/libao
AO_MAKE_ARGS=		ruby+=audio.ao

CV_MAKE_ARGS=		cores+=cv

DEBUG_MAKE_ARGS=	build=debug
DEBUG_MAKE_ARGS_OFF=	build=release

FC_MAKE_ARGS=		cores+=fc

GBA_MAKE_ARGS=		cores+=gba

GB_MAKE_ARGS=		cores+=gb

GLX_USES=		gl
GLX_USE=		GL=gl
GLX_MAKE_ARGS=		ruby+=video.glx

HOTKEYS_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-hotkeys

MD_MAKE_ARGS=		cores+=md

MSX_MAKE_ARGS=		cores+=msx

MS_MAKE_ARGS=		cores+=ms

MYVISION_MAKE_ARGS=	cores+=myvision

N64_RUN_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader
N64_MAKE_ARGS=		cores+=n64 \
			vulkan=true
N64_MAKE_ARGS_OFF=	vulkan=false

NGP_MAKE_ARGS=		cores+=ngp

NG_MAKE_ARGS=		cores+=ng

OPENAL_USES=		openal
OPENAL_MAKE_ARGS=	ruby+=audio.openal

OPENMP_MAKE_ARGS=	openmp=true
OPENMP_MAKE_ARGS_OFF=	openmp=false

OSS_MAKE_ARGS=		ruby+=audio.oss

PCE_MAKE_ARGS=		cores+=pce

PERFORMANCE_MAKE_ARGS=	profile=performance

PS1_MAKE_ARGS=		cores+=ps1

PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio \
			libpulse.so:audio/pulseaudio
PULSEAUDIO_MAKE_ARGS=	ruby+=audio.pulseaudio \
			ruby+=audio.pulseaudiosimple

SDLAUDIO_USES=		sdl
SDLAUDIO_USE=		SDL=sdl2
SDLAUDIO_MAKE_ARGS=	ruby+=audio.sdl \
			sdl2=true

SDLINPUT_USES=		sdl
SDLINPUT_USE=		SDL=sdl2
SDLINPUT_MAKE_ARGS=	ruby+=input.sdl \
			sdl2=true

SFC_MAKE_ARGS=		cores+=sfc

SG_MAKE_ARGS=		cores+=sg

SHADER_BUILD_DEPENDS=	${LOCALBASE}/include/librashader/librashader.h:devel/librashader
SHADER_RUN_DEPENDS=	${LOCALBASE}/${_SHADERS}/bilinear.slangp:games/libretro-shaders-slang \
			${LOCALBASE}/lib/librashader.so:devel/librashader
SHADER_MAKE_ARGS=	librashader=true
SHADER_MAKE_ARGS_OFF=	librashader=false
SHADER_CFLAGS=		-DLIBRA_RUNTIME_OPENGL
SHADER_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-desktop-ui_desktop-ui.cpp

SPEC_MAKE_ARGS=		cores+=spec

UDEV_LIB_DEPENDS=	libudev.so:devel/libudev-devd
UDEV_MAKE_ARGS=		ruby+=input.udev

UHID_MAKE_ARGS=		ruby+=input.uhid

WS_MAKE_ARGS=		cores+=ws

XLIB_MAKE_ARGS=		ruby+=input.xlib

XVIDEO_USE=		XORG=xv
XVIDEO_MAKE_ARGS=	ruby+=video.xvideo

_SHADERS=		share/libretro/shaders/shaders_slang

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENAL} && ${ARCH} == "i386"
LLD_UNSAFE=	yes
.endif

post-patch:
	${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/hiro/GNUmakefile

post-patch-SHADER-on:
	${REINPLACE_CMD} 's|-I../thirdparty/librashader/include||g' \
		${WRKSRC}/desktop-ui/GNUmakefile
	${REINPLACE_CMD} 's|"librashader_ld.h"|<librashader/librashader_ld.h>|g' \
		${WRKSRC}/ruby/video/opengl/opengl.hpp
	${REINPLACE_CMD} 's|@@SHADERS@@|${LOCALBASE}/${_SHADERS}/|g' \
		${WRKSRC}/desktop-ui/desktop-ui.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/desktop-ui/out/ares \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/desktop-ui/resource/ares.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${INSTALL_DATA} ${WRKSRC}/desktop-ui/resource/ares.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${MKDIR} ${STAGEDIR}${DATADIR}/Database
	(cd ${WRKSRC}/mia/Database && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/Database)

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
