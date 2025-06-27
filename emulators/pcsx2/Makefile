PORTNAME=	pcsx2
PORTVERSION=	2.3.439
DISTVERSIONPREFIX=	v
CATEGORIES=	emulators

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Free and open-source PlayStation 2 emulator
WWW=	https://pcsx2.net

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
# Notes on dependencies (see cmake/SearchForStuff.cmake):
# - glad comes from 3rdparty/ (conflicts with libglvnd)
# - fmt, rapidyaml, soundtouch, zydis, libzip
#   are always included from 3rdparty/
LIB_DEPENDS=	libpng.so:graphics/png \
		libzstd.so:archivers/zstd \
		liblz4.so:archivers/liblz4 \
		libwebp.so:graphics/webp \
		libfreetype.so:print/freetype2 \
		libplutovg.so:graphics/plutovg \
		libplutosvg.so:graphics/plutosvg \
		libshaderc_shared.so:graphics/shaderc \
		libcurl.so:ftp/curl \
		libavcodec.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libbacktrace.so:devel/libbacktrace \
		libdbus-1.so:devel/dbus \
		libpulse.so:audio/pulseaudio \
		libjack.so:audio/jack \
		libsndio.so:audio/sndio \
		libkddockwidgets-qt6.so:x11-toolkits/kddockwidgets \
		libsysinfo.so:devel/libsysinfo

USES=		cmake compiler:c++20-lang \
		desktop-file-utils elfctl gl jpeg pkgconfig qt:6 sdl xorg

USE_GITHUB=	yes
GH_PROJECT=	pcsx2

USE_GL=		egl
USE_SDL=	sdl3 ttf3
USE_XORG=	ice x11 xcb xext xi xpm xrandr xrender
USE_QT=		base declarative tools
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
# XXX Vulkan comes from 3rdparty/
CMAKE_ARGS+=	\
		-DCMAKE_REQUIRED_INCLUDES:STRING=${LOCALBASE}/include/ \
		-DCMAKE_LOCALBASE:STRING=${LOCALBASE} \
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
		${COPYTREE_SHARE} resources/ ${STAGEDIR}${DATADIR}/ && \
		${RM} -rf ${STAGEDIR}${DATADIR}/resources/docs/
	${INSTALL_PROGRAM} ${CONFIGURE_WRKSRC}/bin/pcsx2-qt \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/pcsx2-qt/resources/icons/AppIcon64.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/PCSX2.png
	${INSTALL_DATA} ${WRKSRC}/.github/workflows/scripts/linux/pcsx2-qt.desktop \
		${STAGEDIR}${PREFIX}/share/applications/PCSX2.desktop

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${PORTDOCS:S|^|${CONFIGURE_WRKSRC}/bin/resources/docs/|} \
			${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
