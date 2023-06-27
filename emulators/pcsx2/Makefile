PORTNAME=	pcsx2
PORTVERSION=	1.7.4097
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	emulators

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Free and open-source PlayStation 2 emulator
WWW=	https://pcsx2.net

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64

# Notes on dependencies (see cmake/SearchForStuff.cmake):
# - rapidyaml (and c4core) come from 3rdparty/ (0.4.0 is needed)
# - glad comes from 3rdparty/ (conflicts with libglvnd)
# - zydis comes from 3rdparty/
LIB_DEPENDS=	libpng.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libSoundTouch.so:audio/soundtouch \
		libfmt.so:devel/libfmt \
		libzip.so:archivers/libzip \
		libcurl.so:ftp/curl \
		libpulse.so:audio/pulseaudio \
		libjack.so:audio/jack \
		libsndio.so:audio/sndio \
		libzstd.so:archivers/zstd
#		libryml.so:devel/rapidyaml \
#		libglad.so:graphics/glad \

USES=		cmake desktop-file-utils gl pkgconfig qt:6 sdl xorg

USE_GITHUB=	yes
GH_PROJECT=	pcsx2
.include "${.CURDIR}/Makefile.tuples"

USE_GL=		egl
USE_SDL=	sdl2
USE_XORG=	ice x11 xcb xext xpm xrandr
USE_QT=		base tools

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
		-DQT_BUILD:BOOL=ON \
		-DUSE_VTUNE:BOOL=OFF \
		-DUSE_VULKAN:BOOL=OFF \
		-DENABLE_TESTS:BOOL=OFF \
		-DPCSX2_RESOURCES_PATH:STRING=${DATADIR}/resources

OPTIONS_DEFINE=	DOCS
PORTDOCS=	Debugger.pdf GameIndex.pdf PCSX2_FAQ.pdf

# - Program and resources are copied from target dir ${CONFIGURE_WRKSRC}/bin
#   because only necessary resources are installed there (e.g. no dx11 stuff)
do-install:
	cd ${CONFIGURE_WRKSRC}/bin && \
		${COPYTREE_SHARE} resources/ ${STAGEDIR}${DATADIR}/
	${INSTALL_PROGRAM} ${CONFIGURE_WRKSRC}/bin/pcsx2-qt \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/pcsx2/Resources/AppIcon64.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/PCSX2.png
	${INSTALL_DATA} ${WRKSRC}/.github/workflows/scripts/linux/pcsx2-qt.desktop \
		${STAGEDIR}${PREFIX}/share/applications/PCSX2.desktop
	${INSTALL_MAN} ${WRKSRC}/bin/docs/PCSX2.1 ${STAGEDIR}${MANPREFIX}/man/man1/

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
