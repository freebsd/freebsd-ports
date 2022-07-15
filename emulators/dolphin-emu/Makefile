# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>

PORTNAME=	dolphin-emu
PORTVERSION=	5.0.16795
CATEGORIES=	emulators

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Gamecube and Wii Emulator

LICENSE=	BSD3CLAUSE CC0-1.0 GPLv2+ MIT
LICENSE_COMB=	multi

# Notes on dependencies:
# - alsa support has been disabled (not optimal)
# - enet and soundtouch come from Externals/ as Dolphin's versions diverge
#   (see comments in CMakeLists.txt)
# Various problems that may be addressed in the future:
# - xxhash comes from Externals/ as it cannot be properly detected yet
# - freesurround comes from Externals/ as it is not available from ports yet
# - cubeb comes from Externals/ as it is not available from ports yet
# - gtest detection is missing (Externals/ version enforced by CMakeLists.txt)
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libavdevice.so:multimedia/ffmpeg \
		libavfilter.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libfmt.so:devel/libfmt \
		libpugixml.so:textproc/pugixml \
		libzstd.so:archivers/zstd \
		libminizip-ng.so:archivers/minizip-ng \
		liblzo2.so:archivers/lzo2 \
		libpng.so:graphics/png \
		libpulse.so:audio/pulseaudio \
		libjack.so:audio/jack \
		libsndio.so:audio/sndio \
		libsfml-system.so:devel/sfml \
		libminiupnpc.so:net/miniupnpc \
		libmbedtls.so:security/mbedtls \
		libcurl.so:ftp/curl \
		libhidapi.so:comms/hidapi \
		libxml2.so:textproc/libxml2

USES=		cmake compiler:c++17-lang desktop-file-utils gl iconv \
		pkgconfig qmake qt:5 sdl xorg

# See: https://fr.dolphin-emu.org/download/?ref=btn
# for latest beta version and associated commit
USE_GITHUB=	yes
GH_PROJECT=	dolphin
GH_TAGNAME=	7321802

USE_GL=		gl glew glu
USE_SDL=	sdl2
USE_XORG=	ice sm x11 xext xi xrandr
USE_QT=		buildtools_build core gui widgets

# XXX USE_MGBA crashes configure step
CMAKE_ARGS+=	-DUSE_UPNP:BOOL=ON \
		-DENABLE_QT:BOOL=ON \
		-DENABLE_ALSA:BOOL=OFF \
		-DENABLE_PULSEAUDIO:BOOL=ON \
		-DUSE_DISCORD_PRESENCE:BOOL=OFF \
		-DENABLE_AUTOUPDATE=OFF \
		-DUSE_MGBA=OFF
MAKE_ENV+=	DESTDIR="${STAGEDIR}"

# XXX Fix build on archs where 'unsigned long' is 32bit
CXXFLAGS+=	-DLZO_CFG_PREFER_TYPEOF_ACC_INT32E_T=LZO_TYPEOF_INT

# Bypass git check (and set a dummy -unused- revision)
CMAKE_ARGS+=	-DDOLPHIN_WC_BRANCH:STRING="stable" \
		-DDOLPHIN_WC_REVISION:STRING="1"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CMAKE_ON=	-DDISABLE_NLS:BOOL=OFF
NLS_CMAKE_OFF=	-DDISABLE_NLS:BOOL=ON

.include <bsd.port.pre.mk>

# JIT-enabled binaries are amd64 and aarch64 only
.if ${ARCH} != "amd64" && ${ARCH} != "aarch64"
CMAKE_ARGS+=	-DENABLE_GENERIC:BOOL=ON
.endif

.if ${CHOSEN_COMPILER_TYPE:Mclang}
CMAKE_ARGS+=	-DENABLE_LLVM:BOOL=ON
LIB_DEPENDS+=	libLLVM-${COMPILER_VERSION:C/.$//}.so:devel/llvm${COMPILER_VERSION:C/.$//}
.else
CMAKE_ARGS+=	-DENABLE_LLVM:BOOL=OFF
.endif

.include <bsd.port.post.mk>
