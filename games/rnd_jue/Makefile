# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	rnd_jue
PORTVERSION=	3.3.0.0
CATEGORIES=	games
MASTER_SITES=	http://www.jb-line.de/rnd/ \
		http://www.artsoft.org/RELEASES/unix/rocksndiamonds/ \
		SF/rocksndiamonds.mirror/:rocksndiamonds \
		http://www.bd-fans.com/Files/RnD/Levels/:bd_fans_levels \
		SF/nemysisfreebsdp/rocksndiamonds/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		rocksndiamonds-3.3.0.1.tar.gz:rocksndiamonds \
		Walpurgis_Collection.zip:bd_fans_levels \
		rnd_the_h_world.zip:bd_fans_levels \
		${PORTNAME}_icons.tar.gz:icons
DIST_SUBDIR=	rocksndiamonds
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		rocksndiamonds-3.3.0.1.tar.gz \
		${PORTNAME}_icons.tar.gz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Colorful Boulderdash'n'Emerald Mine'n'Sokoban'n'Stuff jue

LICENSE=	GPLv2

LIB_DEPENDS+=	smpeg:${PORTSDIR}/multimedia/smpeg
EXTRACT_DEPENDS+=${UNZIP_CMD}:${PORTSDIR}/archivers/unzip

USE_SDL=	image mixer net sdl
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" MAKE="${GMAKE}" OPTIONS="${CFLAGS}" \
		RO_GAME_DIR="${DATADIR}" \
		X11_PATH="${LOCALBASE}"
ALL_TARGET=	sdl

SUB_FILES=	pkg-message

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CREDITS ChangeLog

DOCSRCDIR2=	${WRKSRC}/docs/elements
DOCSDIR2=	${DOCSDIR}/docs/elements
DOC_FILES2=	*.txt

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="R'n'D jue" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract-script:
	@(cd ${WRKDIR}/rocksndiamonds* && ${COPYTREE_SHARE} levels ${WRKSRC})
.for l in Walpurgis_Collection.zip rnd_the_h_world.zip
	@${UNZIP_CMD} -qo -d ${WRKSRC}/levels ${_DISTDIR}/${l}
.endfor
	@(cd ${WRKSRC}/levels/"Walpurgis Collection" && \
		${RM} -fr "Walpurgis Gardens" "Walpurgis World")
	@(cd ${WRKSRC}/levels/rnd_the_h_world && ${RM} -fr hwld_dceos)
		@${RM} -f ${WRKDIR}/${PORTNAME}/Readme.txt
	@${RM} -f ${WRKSRC}/levels/Readme.txt

post-patch:
	@${REINPLACE_CMD} \
		-e 's|sdl-config|$${SDL_CONFIG}|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} \
		-e 's|machine/soundcard.h|sys/soundcard.h|' ${WRKSRC}/src/libgame/sound.c
	@${REINPLACE_CMD} \
		-e 's|machine/joystick.h|sys/joystick.h|' ${WRKSRC}/src/libgame/joystick.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.for dir in graphics levels music sounds
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${DATADIR})
.endfor

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif
	@${ECHO} "@unexec ${RMDIR} \"${DATADIR}/levels\" 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO} "@unexec ${RMDIR} \"${DATADIR}\" 2>/dev/null || true" >> ${TMPPLIST}

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
