PORTNAME=	simutrans
DISTVERSION=	124.3.1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Transportation simulator
WWW=		https://www.simutrans.com/ \
		https://github.com/aburch/simutrans/

LICENSE=	ART10 MIT
LICENSE_COMB=	multi
LICENSE_FILE_ART10=	${WRKSRC}/simutrans/license.txt
LICENSE_FILE_MIT=	${WRKSRC}/simutrans/license_squirrel.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++14-lang pkgconfig sdl
USE_GITHUB=	yes
USE_SDL=	sdl2
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_CCache \
		CMAKE_DISABLE_FIND_PACKAGE_Git \
		CMAKE_DISABLE_FIND_PACKAGE_Subversion
CMAKE_ARGS=	-DSIMUTRANS_USE_REVISION=1

PORTSCOUT=	skipv:nightly

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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/simutrans && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
