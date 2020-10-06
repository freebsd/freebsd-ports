# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	dolphin-emu
PORTVERSION=	5.0.12716
CATEGORIES=	emulators

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Gamecube and Wii Emulator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

# Notes on dependencies:
# - alsa support has been disabled (not optimal)
# - enet and soundtouch come from Externals/ as Dolphin's versions diverge
#   (see comments in CMakeLists.txt)
# Various problems that may be addressed in the future:
# - xxhash comes from Externals/ as it cannot be properly detected yet
# - minizip comes from Externals/ as v>=2.0.0 is not available from ports yet
# - freesurround comes from Externals/ as it is not available from ports yet
# - cubeb comes from Externals/ as it is not available from ports yet
# - gtest detection is missing (Externals/ version enforced by CMakeLists.txt)
LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
		libavcodec.so:multimedia/ffmpeg \
		libavdevice.so:multimedia/ffmpeg \
		libavfilter.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libpugixml.so:textproc/pugixml \
		liblzo2.so:archivers/lzo2 \
		libpng.so:graphics/png \
		libjack.so:audio/jack \
		libsndio.so:audio/sndio \
		libsfml-system.so:devel/sfml \
		libminiupnpc.so:net/miniupnpc \
		libmbedtls.so:security/mbedtls \
		libcurl.so:ftp/curl \
		libhidapi.so:comms/hidapi \
		libzstd.so:archivers/zstd \
		libfmt.so:devel/libfmt

USES=		cmake compiler:c++17-lang desktop-file-utils gl iconv \
		pkgconfig qmake qt:5 sdl xorg

# See: https://fr.dolphin-emu.org/download/?ref=btn
# for latest beta version and associated commit
USE_GITHUB=	yes
GH_PROJECT=	dolphin
GH_TAGNAME=	3152428

USE_GL=		gl glew glu
USE_SDL=	sdl2
USE_XORG=	ice sm x11 xext xi xrandr
USE_QT=		buildtools_build core gui widgets

CMAKE_ARGS+=	-DUSE_UPNP:BOOL=ON \
		-DENABLE_QT:BOOL=ON \
		-DENABLE_ALSA:BOOL=OFF \
		-DENABLE_PULSEAUDIO:BOOL=ON \
		-DUSE_DISCORD_PRESENCE:BOOL=OFF \
		-DCMAKE_REQUIRED_INCLUDES:PATH="${LOCALBASE}/include" \
		-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib"
MAKE_ENV+=	DESTDIR="${STAGEDIR}"

# XXX Fix build on archs where 'unsigned long' is 32bit
CXXFLAGS+=	-DLZO_CFG_PREFER_TYPEOF_ACC_INT32E_T=LZO_TYPEOF_INT

# XXX Bypass git check (and set a dummy -unused- revision)
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

.include <bsd.port.post.mk>
