PORTNAME=	pcsx2
PORTVERSION=	1.7.4970
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	emulators

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Free and open-source PlayStation 2 emulator
WWW=	https://pcsx2.net

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64

# Notes on dependencies (see cmake/SearchForStuff.cmake):
# - glad comes from 3rdparty/ (conflicts with libglvnd)
# - fmt, rapidyaml, soundtouch, zydis, zstd, libzip
#   are always included from 3rdparty/
LIB_DEPENDS=	libpng.so:graphics/png \
		libdbus-1.so:devel/dbus \
		libavcodec.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libpulse.so:audio/pulseaudio \
		libjack.so:audio/jack \
		libsndio.so:audio/sndio \
		libbacktrace.so:devel/libbacktrace
# XXX Necessary for Qt6/FindWrapVulkanHeaders.cmake
# then vulkan-haders and glslang are unconditionnaly included from 3rdparty/
BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake compiler:c++20-lang \
		desktop-file-utils elfctl gl pkgconfig qt:6 sdl xorg

USE_GITHUB=	yes
GH_PROJECT=	pcsx2
.include "${.CURDIR}/Makefile.tuples"

USE_GL=		egl
USE_SDL=	sdl2
USE_XORG=	ice x11 xcb xext xpm xrandr
USE_QT=		base tools
ELF_FEATURES=	+wxneeded:bin/pcsx2-qt

# SSE 4.1 instructions are a hard requirement, if CPUTYPE is defined
# use whatever is set and let the build fail if it falls below
# baseline requirements. If it's undefined set penryn as target
# as it's the oldest CPU arch that supports SSE 4.1
.if defined(CPUTYPE)
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-no-march-native
.else
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-no-march-minimum-req
.endif

# See: cmake/BuildParameters.cmake
CMAKE_ARGS+=	\
		-DCMAKE_REQUIRED_INCLUDES:STRING=${LOCALBASE}/include/ \
		-DPCSX2_RESOURCES_PATH:STRING=${DATADIR}/resources \
		-DUSE_VTUNE:BOOL=OFF \
		-DWAYLAND_API=OFF \
		-DENABLE_TESTS:BOOL=OFF

OPTIONS_DEFINE=	DOCS
PORTDOCS=	Debugger.pdf GameIndex.pdf

# - Program and resources are copied from target dir ${CONFIGURE_WRKSRC}/bin
#   because only necessary resources are installed there (e.g. no dx11 stuff)
do-install:
	cd ${CONFIGURE_WRKSRC}/bin && \
		${COPYTREE_SHARE} resources/ ${STAGEDIR}${DATADIR}/
	${INSTALL_PROGRAM} ${CONFIGURE_WRKSRC}/bin/pcsx2-qt \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/pcsx2-qt/resources/icons/AppIcon64.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/PCSX2.png
	${INSTALL_DATA} ${WRKSRC}/.github/workflows/scripts/linux/pcsx2-qt.desktop \
		${STAGEDIR}${PREFIX}/share/applications/PCSX2.desktop

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/bin/docs/|} \
			${STAGEDIR}${DOCSDIR}

# For maintainer (do not forget to clean up Makefile.tuples afterwards to
# remove useless submodules)
Makefile.tuples::
	@${RM} -f ${.CURDIR}/Makefile.tuples
	@${RM} -rf ${WRKDIR}/.maintainer.checkout
	@${MKDIR} ${WRKDIR}/.maintainer.checkout && \
		cd ${WRKDIR}/.maintainer.checkout && \
		git clone --recursive --branch=v${PORTVERSION} \
			https://github.com/${PORTNAME}/${PORTNAME} . && \
		${SH} ${FILESDIR}/gen_gh_tuple.sh >> ${.CURDIR}/Makefile.tuples

.include <bsd.port.mk>
