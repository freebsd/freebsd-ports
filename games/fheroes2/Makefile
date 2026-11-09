PORTNAME=	fheroes2
PORTVERSION=	1.1.18
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Free implementation of Heroes of Might and Magic II engine
WWW=		https://ihhub.github.io/fheroes2/

LICENSE=	GPLv2 CC-BY-SA-4.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE
LICENSE_FILE_CC-BY-SA-4.0=	${WRKSRC}/LICENSE-ART

USES=		cmake sdl
USE_GITHUB=	yes
GH_ACCOUNT=	ihhub
USE_SDL=	mixer2 sdl2

OPTIONS_DEFINE=	DOCS FLUIDSYNTH NLS
OPTIONS_DEFAULT=	FLUIDSYNTH NLS
OPTIONS_SUB=	yes

FLUIDSYNTH_DESC=	SoundFont for MIDI music playback via FluidSynth

FLUIDSYNTH_RUN_DEPENDS=	${LOCALBASE}/share/sounds/sf2/FluidR3_GM.sf2:audio/fluid-soundfont

# Translations are built by a GNU make Makefile in files/lang
NLS_BUILD_DEPENDS=	gmake:devel/gmake
NLS_USES=	gettext-tools
NLS_CMAKE_ON=	-DMAKE_EXECUTABLE=${LOCALBASE}/bin/gmake
NLS_CMAKE_OFF=	-DMAKE_EXECUTABLE=${TRUE}

post-install-FLUIDSYNTH-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/files/soundfonts
	${LN} -sf ${LOCALBASE}/share/sounds/sf2/FluidR3_GM.sf2 \
		${STAGEDIR}${DATADIR}/files/soundfonts/

.include <bsd.port.mk>
