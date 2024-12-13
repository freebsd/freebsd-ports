PORTNAME=	es-de
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1
CATEGORIES=	emulators

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Frontend for browsing and launching games
WWW=		https://es-de.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${_BR_DEPENDS} \
		${LOCALBASE}/include/CImg.h:graphics/cimg \
		${LOCALBASE}/include/glm/glm.hpp:math/glm \
		${LOCALBASE}/include/rapidjson/rapidjson.h:devel/rapidjson \
		${LOCALBASE}/include/utf8cpp/utf8.h:devel/utf8cpp
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libfreeimage.so:graphics/freeimage \
		libfreetype.so:print/freetype2 \
		libgit2.so:devel/libgit2 \
		libharfbuzz.so:print/harfbuzz \
		libicuuc.so:devel/icu \
		libpoppler.so:graphics/poppler \
		libpugixml.so:textproc/pugixml \
		librlottie.so:graphics/rlottie
RUN_DEPENDS=	${_BR_DEPENDS}

USES=		cmake compiler:c++17-lang gl pkgconfig sdl
USE_GITLAB=	yes
GL_PROJECT=	emulationstation-de
USE_GL=		opengl
USE_SDL=	sdl2

CMAKE_ARGS=	-DUTF8CPP_INCLUDE_DIR=${LOCALBASE}/include/utf8cpp
CMAKE_ON=	VIDEO_HW_DECODING

OPTIONS_DEFINE=		DEINIT DOCS NLS
OPTIONS_DEFAULT=	DEINIT
OPTIONS_SUB=		yes

DEINIT_DESC=	Deinit frontend on emulator launch

DEINIT_CMAKE_BOOL=	DEINIT_ON_LAUNCH

NLS_USES=		gettext
NLS_CMAKE_BOOL=		COMPILE_LOCALIZATIONS

_BR_DEPENDS=	dejavu>0:x11-fonts/dejavu \
		droid-fonts-ttf>0:x11-fonts/droid-fonts-ttf \
		freefont-ttf>0:x11-fonts/freefont-ttf \
		noto-emoji>0:x11-fonts/noto-emoji \
		ubuntu-font>0:x11-fonts/ubuntu-font

post-install:
	${LN} -sf ${LOCALBASE}/share/fonts/Droid/DroidSansFallbackFull.ttf \
		${STAGEDIR}${DATADIR}/resources/fonts
	${LN} -sf ${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf ${STAGEDIR}${DATADIR}/resources/fonts
	${LN} -sf ${LOCALBASE}/share/fonts/freefont-ttf/FreeMono.ttf \
		${STAGEDIR}${DATADIR}/resources/fonts
	${LN} -sf ${LOCALBASE}/share/fonts/noto/NotoColorEmoji.ttf ${STAGEDIR}${DATADIR}/resources/fonts/NotoEmoji.ttf
	${LN} -sf ${LOCALBASE}/share/fonts/ubuntu-font/Ubuntu-C.ttf ${STAGEDIR}${DATADIR}/resources/fonts

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
