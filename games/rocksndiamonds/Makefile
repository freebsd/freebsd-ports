# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rocksndiamonds
PORTVERSION=	3.3.0.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/rocksndiamonds/ \
		http://www.jb-line.de/rnd/ \
		SF/${PORTNAME}.mirror/ \
		http://www.artsoft.org/RELEASES/rocksndiamonds/levels/:levels \
		http://www.bd-fans.com/Files/RnD/Levels/ \
		SF/nemysisfreebsdp/${PORTNAME}/:icons
# Please contact the MAINTAINER if a Level is missing
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		rnd_jue-3.3.0.0.tar.gz \
		Sokoban-1.0.0.zip:levels \
		Contributions-1.2.0.zip:levels \
		${LEVELS_BD_FANS:S/$/.zip/} \
		Gavin_Davidson_2006.zip \
		Trucky_Cargos_v0.1.zip \
		Walpurgis_Collection.zip \
		${PORTNAME}_icons.zip:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		rnd_jue-3.3.0.0.tar.gz \
		${PORTNAME}_icons.zip

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Colorful Boulderdash'n'Emerald Mine'n'Sokoban'n'Stuff

LICENSE=	GPLv2

LIB_DEPENDS=	smpeg:${PORTSDIR}/multimedia/smpeg
EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

USE_ICONV=	yes
USE_SDL=	image mixer net sdl
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" MAKE="${GMAKE}" OPTIONS="${CFLAGS}" \
		RO_GAME_DIR="${DATADIR}" \
		X11_PATH="${LOCALBASE}"
ALL_TARGET=	sdl
MAKE_JOBS_SAFE=	yes

SUB_FILES=	pkg-message

LEVELS_ARTSOFT=	rnd_jue Sokoban Contributions

LEVELS_BD_FANS=	Bug_Hunter Colourful_World Earth_Shaker_Collection \
		Glasses Love_Pac Maniac_Mines Negundo_Dash Pipemania Rockfighter \
		Step_Puzzles Super_Jetset_Willy_Bros_3 Through_the_Ages \
		rnd_the_h_world

MAN1=		rocksndiamonds.1

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CREDITS ChangeLog README

DOCSRCDIR2=	${WRKSRC}/docs/elements
DOCSDIR2=	${DOCSDIR}/docs/elements
DOC_FILES2=	*.txt

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="Rocks'n'Diamonds" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-extract-script:
	${MKDIR} ${WRKDIR}/${PORTNAME}
	@(cd ${WRKDIR}/rnd_jue* && ${COPYTREE_SHARE} levels/rnd_jue ${WRKDIR}/${PORTNAME})
	@(cd ${WRKDIR}/${PORTNAME}/levels ; ${MV} rnd_jue .. ; cd .. ; ${RMDIR} levels)
.for l in Sokoban-1.0.0.zip Contributions-1.2.0.zip
	@${UNZIP_CMD} -qo -d ${WRKDIR}/${PORTNAME} ${DISTDIR}/${DIST_SUBDIR}/${l}
.endfor

.for l in ${LEVELS_BD_FANS:S/$/.zip/} Gavin_Davidson_2006.zip Trucky_Cargos_v0.1.zip Walpurgis_Collection.zip
	@${UNZIP_CMD} -qo -d ${WRKDIR}/${PORTNAME} ${DISTDIR}/${DIST_SUBDIR}/${l}
.endfor
	@${RM} -f ${WRKDIR}/${PORTNAME}/Readme.txt

post-patch:
	@${REINPLACE_CMD} \
		-e 's|sdl-config|$${SDL_CONFIG}|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} \
		-e 's|machine/soundcard.h|sys/soundcard.h|' ${WRKSRC}/src/libgame/sound.c
	@${REINPLACE_CMD} \
		-e 's|machine/joystick.h|sys/joystick.h|' ${WRKSRC}/src/libgame/joystick.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1

.for dir in graphics levels music sounds
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${DATADIR})
.endfor
	@cd ${WRKDIR}/${PORTNAME} && ${COPYTREE_SHARE} \* ${DATADIR}/levels

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

# Dynamically generate part of the PLIST, because the Levels are large
.for l in ${LEVELS_ARTSOFT}
	@${FIND} ${DATADIR}/levels/${l}/ ! -type d | ${SED} 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} -ds ${DATADIR}/levels/${l}/ -type d | \
		${SED} -E -e 's,(.*),@unexec ${RMDIR} "\1" 2>/dev/null || true,' >> ${TMPPLIST}
.endfor

.for l in ${LEVELS_BD_FANS} "Gavin Davidson 2006" Trucky_Cargos "Walpurgis Collection"
	@${FIND} ${DATADIR}/levels/${l}/ ! -type d | ${SED} 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} -ds ${DATADIR}/levels/${l}/ -type d | \
		${SED} -E -e 's,(.*),@unexec ${RMDIR} "\1" 2>/dev/null || true,' >> ${TMPPLIST}
.endfor
	@${ECHO} "@unexec ${RMDIR} \"${DATADIR}/levels\" 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO} "@unexec ${RMDIR} \"${DATADIR}\" 2>/dev/null || true" >> ${TMPPLIST}

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
