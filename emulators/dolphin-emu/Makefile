PORTNAME=	dolphin-emu
PORTVERSION=	2509
CATEGORIES=	emulators

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Gamecube and Wii Emulator
WWW=		https://www.dolphin-emu.org

LICENSE=	BSD3CLAUSE CC0-1.0 GPLv2+ MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto
# Notes on dependencies:
# - alsa support has been disabled (not optimal)
# - enet comes from Externals/ as Dolphin's version diverges
#   (see comments in CMakeLists.txt)
# Various problems that may be addressed in the future:
# - freesurround comes from Externals/ as it is not available from ports yet
# - cubeb comes from Externals/ as it is not available from ports yet
# - gtest detection is missing (Externals/ version enforced by CMakeLists.txt)
# - SFML comes from Externals/ as v3.0 is needed
# - mbedtls2 comes from Externals/ as it has been deprecated in the ports tree
# - mGBA comes from Externals/ as building with our ports' version fails
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libavdevice.so:multimedia/ffmpeg \
		libavfilter.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libfmt.so:devel/libfmt \
		libpugixml.so:textproc/pugixml \
		libxxhash.so:devel/xxhash \
		libzstd.so:archivers/zstd \
		libminizip-ng.so:archivers/minizip-ng \
		liblzo2.so:archivers/lzo2 \
		liblz4.so:archivers/liblz4 \
		libspng.so:graphics/libspng \
		libspeexdsp.so:audio/speexdsp \
		libpulse.so:audio/pulseaudio \
		libjack.so:audio/jack \
		libsndio.so:audio/sndio \
		libminiupnpc.so:net/miniupnpc \
		libcurl.so:ftp/curl \
		libhidapi.so:comms/hidapi \
		libxkbcommon.so:x11/libxkbcommon \
		libudev.so:devel/libudev-devd \
		libevdev.so:devel/libevdev

USES=		cmake compiler:c++17-lang desktop-file-utils elfctl gl iconv \
		pkgconfig python qmake qt:6 sdl xorg

ELF_FEATURES=	+noaslr:Binaries/dolphin-emu*

# See: https://dolphin-emu.org/download/ for latest release
USE_GITHUB=	yes
GH_PROJECT=	dolphin
GH_TAGNAME=	${PORTVERSION}
.include "${.CURDIR}/Makefile.tuples"

USE_GL=		egl gl
USE_SDL=	sdl3
USE_XORG=	ice sm x11 xext xi xrandr
USE_QT=		base svg

CMAKE_ARGS+=	-DUSE_UPNP:BOOL=ON \
		-DENABLE_QT:BOOL=ON \
		-DENABLE_ALSA:BOOL=OFF \
		-DENABLE_PULSEAUDIO:BOOL=ON \
		-DUSE_DISCORD_PRESENCE:BOOL=OFF \
		-DUSE_MGBA:BOOL=ON \
		-DENABLE_AUTOUPDATE:BOOL=OFF \
		-DENABLE_EVDEV:BOOL=ON
MAKE_ENV+=	DESTDIR="${STAGEDIR}"

# XXX Fix build on archs where 'unsigned long' is 32bit
CXXFLAGS+=	-DLZO_CFG_PREFER_TYPEOF_ACC_INT32E_T=LZO_TYPEOF_INT

# Bypass git check (and set a dummy -unused- revision)
CMAKE_ARGS+=	-DDOLPHIN_WC_BRANCH:STRING="stable" \
		-DDOLPHIN_WC_REVISION:STRING="${PORTVERSION}"

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
CMAKE_ARGS+=	-DENABLE_LLVM:BOOL=ON \
		-DLLVM_DIR=${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/cmake/llvm
LIB_DEPENDS+=	libLLVM-${LLVM_DEFAULT:C/^([6-9])0/\1/}.so:devel/llvm${LLVM_DEFAULT}
.else
CMAKE_ARGS+=	-DENABLE_LLVM:BOOL=OFF
.endif

# For maintainer (do not forget to clean up Makefile.tuples afterwards to
# remove useless submodules)
Makefile.tuples::
	@${ECHO_CMD} -n > ${.CURDIR}/Makefile.tuples
	@${RM} -rf ${WRKDIR}/.maintainer.checkout
	@${MKDIR} ${WRKDIR}/.maintainer.checkout && \
		cd ${WRKDIR}/.maintainer.checkout && \
		git clone https://github.com/${GH_ACCOUNT}/${GH_PROJECT} . && \
		git checkout ${GH_TAGNAME} && \
		git submodule init && \
		git submodule update --recursive && \
		${SH} ${FILESDIR}/gen_gh_tuple.sh > ${.CURDIR}/Makefile.tuples

.include <bsd.port.post.mk>
