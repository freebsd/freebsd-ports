PORTNAME=	es-de
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.3
CATEGORIES=	emulators

# committed upstream, remove with next version update
# * Provide DEINIT_ON_LAUNCH
#   https://gitlab.com/es-de/emulationstation-de/-/issues/1818
# * Use getPathToBinary(argv[0]) fallback in setExePath
#   https://gitlab.com/es-de/emulationstation-de/-/issues/1819
# * Fix runRebootCommand() and runPoweroffCommand()
#   https://gitlab.com/es-de/emulationstation-de/-/issues/1820
PATCH_SITES=	https://gitlab.com/${PORTNAME}/${GL_PROJECT}/-/commit/
PATCHFILES=	330f36ee14525d59879a36005fa08734b21cf8fc.patch:-p1 \
		bd6956d52ffc950102613b7425eb30f668206888.patch:-p1 \
		338843ce46ee8ab78a1b3c60dcae0ec79a30aa28.patch:-p1

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Frontend for browsing and launching games
WWW=		https://es-de.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/CImg.h:graphics/cimg \
		${LOCALBASE}/include/glm/glm.hpp:math/glm \
		${LOCALBASE}/include/rapidjson/rapidjson.h:devel/rapidjson
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libfreeimage.so:graphics/freeimage \
		libfreetype.so:print/freetype2 \
		libgit2.so:devel/libgit2 \
		libpoppler.so:graphics/poppler \
		libpugixml.so:textproc/pugixml \
		librlottie.so:graphics/rlottie

USES=		cmake compiler:c++17-lang gl localbase pkgconfig sdl
USE_GITLAB=	yes
GL_PROJECT=	emulationstation-de
USE_GL=		opengl
USE_SDL=	sdl2

CMAKE_ON=	VIDEO_HW_DECODING

OPTIONS_DEFINE=		DEINIT DOCS
OPTIONS_DEFAULT=	DEINIT

DEINIT_DESC=		Deinit frontend on emulator launch

DEINIT_CMAKE_BOOL=	DEINIT_ON_LAUNCH

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
