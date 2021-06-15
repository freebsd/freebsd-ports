PORTNAME=	simutrans
DISTVERSION=	123-0-1
CATEGORIES=	games
MASTER_SITES=	SF/simutrans/simutrans/${DISTVERSION}
DISTNAME=	simutrans-src-${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Transportation simulator

LICENSE=	ART10 MIT
LICENSE_COMB=	multi
LICENSE_FILE_ART10=	${WRKSRC}/simutrans/license.txt
LICENSE_FILE_MIT=	${WRKSRC}/simutrans/license_squirrel.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++11-lib pkgconfig sdl zip
USE_SDL=	sdl2

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_CCache \
		CMAKE_DISABLE_FIND_PACKAGE_Git \
		CMAKE_DISABLE_FIND_PACKAGE_Subversion

NO_WRKSUBDIR=	yes

SUB_FILES=	simutrans

PORTDATA=	*
PORTDOCS=	change_request.txt \
		history.txt \
		problem_report.txt \
		readme.txt \
		thanks.txt

DESKTOP_ENTRIES=Simutrans "" simutrans simutrans "Game;Simulation;" false

OPTIONS_DEFINE=	DOCS UPNP FLUIDSYNTH
OPTIONS_MULTI=	PAKS
OPTIONS_MULTI_PAKS=	PAK64 PAK128 PAK128_GERMAN
OPTIONS_DEFAULT=PAK128 UPNP FLUIDSYNTH

PAKS_DESC=			Graphics sets
PAK64_DESC=			Enable low resolution graphics set
PAK64_RUN_DEPENDS=		simutrans-pak64>=0:games/simutrans-pak64
PAK128_DESC=			Enable high resolution graphics set
PAK128_RUN_DEPENDS=		simutrans-pak128>=0:games/simutrans-pak128
PAK128_GERMAN_DESC=		Enable german graphics set
PAK128_GERMAN_RUN_DEPENDS=	simutrans-pak128.german>=0:games/simutrans-pak128.german

UPNP_DESC=			Use MiniUPNP for easier server setup
UPNP_LIB_DEPENDS=		libminiupnpc.so:net/miniupnpc
UPNP_CMAKE_BOOL=		SIMUTRANS_USE_UPNP

FLUIDSYNTH_DESC=		Enable FluidSynth for MIDI playback
FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CMAKE_BOOL=		SIMUTRANS_USE_FLUIDSYNTH_MIDI

do-install:
	@cd ${WRKSRC}/simutrans && ${COPYTREE_SHARE} \
		"ai config font music script text themes" ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/simutrans/simutrans \
		${STAGEDIR}${PREFIX}/libexec/simutrans
	${INSTALL_SCRIPT} ${WRKDIR}/simutrans ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/simutrans.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/simutrans && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
