PORTNAME=	rocksndiamonds
DISTVERSION=	4.4.0.3
CATEGORIES=	games
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/rocksndiamonds/:game \
		http://www.artsoft.org/RELEASES/rocksndiamonds/levels/:levels_artsoft \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/
# Please contact the MAINTAINER if a Level is missing
DISTFILES=	${PORTNAME}-${DISTVERSION}-linux${EXTRACT_SUFX}:game \
		rnd_jue-3.3.0.0${EXTRACT_SUFX}:game \
		${LEVELS_ARTSOFT:S/$/.zip/}:levels_artsoft \
		${LEVELS_BD_FANS:S/$/.zip/} \
		Tutorial_Alpha.zip \
		${PORTNAME}_icons.zip
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}-linux${EXTRACT_SUFX} \
		rnd_jue-3.3.0.0.tar.gz \
		${PORTNAME}_icons.zip

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Colorful Boulderdash'n'Emerald Mine'n'Sokoban'n'Stuff
WWW=		https://www.artsoft.org/rocksndiamonds/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip

USES=		gmake gnome iconv sdl
USE_SDL=	image2 mixer2 net2 sdl2
MAKE_ARGS=	BASE_PATH="${DATADIR}" \
		CC="${CC}" \
		MAKE="${MAKE_CMD}" \
		OPTIONS="${CFLAGS}" \
		RO_GAME_DIR="${DATADIR}" \
		RW_GAME_DIR="/var/games/${PORTNAME}" \
		X11_PATH="${LOCALBASE}"

DESKTOP_ENTRIES=	"Rocks'n'Diamonds" \
			"" \
			"${PORTNAME}" \
			"${PORTNAME}" \
			"Game;ArcadeGame;" \
			""

SUB_FILES=	pkg-message

LEVELS_ARTSOFT=	Sokoban-1.0.0 Contributions-1.2.0

LEVELS_BD_FANS=	Bug_Hunter Classic_Boulderdash Classic_Sokoban Classic_Supaplex \
		Colourful_World Love_Pac Maniac_Mines Negundo_Dash Pipemania \
		Rockfighter Step_Puzzles Super_Jetset_Willy_Bros_3 \
		Through_the_Ages Trucky_Cargos_v0.1 Walpurgis_Collection \
		rnd_the_h_world

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CREDITS ChangeLog

DOCSRCDIR2=	${WRKSRC}/docs/elements
DOCSDIR2=	${DOCSDIR}/docs/elements
DOC_FILES2=	*.txt

ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

OPTIONS_DEFINE=	DOCS

post-extract-script:
	@${MKDIR} ${WRKDIR}/${PORTNAME}
	@(cd ${WRKDIR}/rnd_jue*/levels/rnd_jue && ${RM} -r jue_sobigo)
	@(cd ${WRKDIR}/rnd_jue*/levels && ${COPYTREE_SHARE} rnd_jue \
		${WRKDIR}/${PORTNAME})
.for l in ${LEVELS_ARTSOFT:S/$/.zip/} ${LEVELS_BD_FANS:S/$/.zip/}
	@${UNZIP_CMD} -qo -d ${WRKDIR}/${PORTNAME} ${_DISTDIR}/${l}
.endfor
	@${UNZIP_CMD} -qo -d ${WRKDIR}/${PORTNAME}/Tutorials \
		${_DISTDIR}/Tutorial_Alpha.zip
	@(cd ${WRKDIR}/${PORTNAME}/Tutorials && \
		${MV} "Tutorial Alpha" rnd_tutorial_alpha)
	@${RM} ${WRKDIR}/${PORTNAME}/Readme.txt

post-patch:
	@${REINPLACE_CMD} \
		-e 's|sdl2-config|$${SDL2_CONFIG}|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} \
		-e 's|machine/joystick.h|sys/joystick.h|' \
		${WRKSRC}/src/libgame/joystick.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for dir in graphics levels music sounds
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR})
.endfor
	@cd ${WRKDIR}/${PORTNAME} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DATADIR}/levels/

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${RLN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

	@cd ${STAGEDIR}${PREFIX} && ${FIND} ${DATADIR_REL}/levels \
		-type f >> ${TMPPLIST}

.include <bsd.port.mk>
