PORTNAME=	emulationstation
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.2
PORTREVISION=	5
CATEGORIES=	emulators

MAINTAINER=	freebsd@coombscloud.com
COMMENT=	Graphical front-end for emulators (RetroPie fork)
WWW=		https://github.com/RetroPie/EmulationStation

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/opensans_license.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${LOCALBASE}/include/rapidjson/document.h:devel/rapidjson \
		pugixml>0:textproc/pugixml
LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_locale.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libfreeimage.so:graphics/freeimage \
		libfreetype.so:print/freetype2 \
		libpugixml.so:textproc/pugixml \
		libvlc.so:multimedia/vlc

USES=		cmake gl pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	RetroPie
GH_PROJECT=	EmulationStation
USE_GCC=	yes
USE_GL=		gl glu
USE_SDL=	sdl2

PORTDOCS=	CREDITS.md DEVNOTES.md GAMELISTS.md README.md SYSTEMS.md \
		THEMES.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|<pugixml/src/pugixml.hpp>|<pugixml.hpp>|g' \
		${WRKSRC}/es-app/src/CollectionSystemManager.cpp \
		${WRKSRC}/es-app/src/Gamelist.cpp \
		${WRKSRC}/es-app/src/MetaData.cpp \
		${WRKSRC}/es-app/src/SystemData.cpp \
		${WRKSRC}/es-app/src/scrapers/GamesDBJSONScraper.cpp \
		${WRKSRC}/es-app/src/scrapers/ScreenScraper.cpp \
		${WRKSRC}/es-core/src/InputConfig.cpp \
		${WRKSRC}/es-core/src/InputManager.cpp \
		${WRKSRC}/es-core/src/MameNames.cpp \
		${WRKSRC}/es-core/src/Settings.cpp \
		${WRKSRC}/es-core/src/ThemeData.cpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
