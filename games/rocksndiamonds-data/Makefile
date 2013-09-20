# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	rocksndiamonds-data
PORTVERSION=	20130322
CATEGORIES=	games
MASTER_SITES+=	http://www.artsoft.org/RELEASES/rocksndiamonds/levels/:levels \
		http://www.artsoft.org/RELEASES/unix/rocksndiamonds/levels/:unix_levels \
		http://www.bd-fans.com/Files/RnD/Levels/
DISTFILES=	ZeldaII-1.0.0.zip:levels \
		Zelda-1.0.0.zip:levels \
		Emerald_Mine_Club-2.1.1.7z:levels \
		Snake_Bite-1.0.0.zip:levels \
		BD2K3-1.0.0.zip:levels \
		rockslevels-sp-1.0.tar.gz:unix_levels \
		rockslevels-dx-1.0.tar.gz:unix_levels \
		Boulder_Dash_Dream-1.0.0.zip:levels \
		${LEVELS_BD_FANS:S/$/.zip/} \
		Tutorial_Alpha.zip \
		Puzzles_v1.8.zip
DIST_SUBDIR=	rocksndiamonds
EXTRACT_ONLY=	#empty

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Additional Player Levels for Rocks'n'Diamonds and R'n'D jue

EXTRACT_DEPENDS+=${UNZIP_CMD}:${PORTSDIR}/archivers/unzip \
		7z:${PORTSDIR}/archivers/p7zip

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message pkg-deinstall

LEVELS_ARTSOFT=	zelda zelda2 Emerald_Mine_Club Snake_Bite BD2K3 \
		DX_Boulderdash Supaplex Boulder_Dash_Dream

LEVELS_BD_FANS=	42_Steps Alans_Random_Levels Alexanders_Levels Arcade_Levels \
		Be_a_bug Contest_Levels Danilo_Parantar_Serrano Danilo_Parantar_Serrano_2 \
		Hard_Skills Haspeton  Learning_Maths Little_Games \
		Magic_CEs Manuel Manuels_Sokoban_Levels Master-Rocks Memory \
		Mini_Levels_Ryan Missions Mixed_Levels Mixed_Levels_2 MultiRandomLevel \
		My_Levels_of_Fun Negundo_World_2 Negundo_World_3 P98_Level_Pack_1 \
		Pacman Random_Games Rocks_n_Diamonds_Fun Ryans_Random_Levels Slippery_Ground \
		Space_Invaders Space_Invaders_2 Springlis_Levels Stinky Super_BD-Rock \
		Super_Comic_Levels Venatir Veysi_Orak_2006 Warparound_Murphy

OPTIONS_SINGLE=	SYMLINK
OPTIONS_SINGLE_SYMLINK=	RnD RnD_jue

OPTIONS_DEFAULT=	RnD_jue

RnD_DESC=	Levels default for Rocks'n'Diamonds
RnD_jue_DESC=	Levels default for R'n'D jue

PREFIX=		/usr/local

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRnD}
RUN_DEPENDS+=	rocksndiamonds:${PORTSDIR}/games/rocksndiamonds
DATADIR=	${PREFIX}/share/rocksndiamonds
DATADIR1=	${PREFIX}/share/rnd_jue
.endif

.if ${PORT_OPTIONS:MRnD_jue}
RUN_DEPENDS+=	rnd_jue:${PORTSDIR}/games/rnd_jue
DATADIR=	${PREFIX}/share/rnd_jue
DATADIR1=	${PREFIX}/share/rocksndiamonds
.endif

post-extract-script:
	${MKDIR} ${WRKDIR}/${PORTNAME}
	7z x ${_DISTDIR}/Emerald_Mine_Club-2.1.1.7z -o${WRKDIR}/${PORTNAME}
.for l in ZeldaII-1.0.0.zip Zelda-1.0.0.zip Snake_Bite-1.0.0.zip BD2K3-1.0.0.zip \
		Boulder_Dash_Dream-1.0.0.zip
	@${UNZIP_CMD} -qo -d ${WRKDIR}/${PORTNAME} ${_DISTDIR}/${l}
.endfor

.for l in rockslevels-sp-1.0.tar.gz rockslevels-dx-1.0.tar.gz
	@${TAR} xfjp ${_DISTDIR}/${l} -C ${WRKDIR}/${PORTNAME}
.endfor
	@(cd ${WRKDIR}/${PORTNAME}/levels && ${MV} * .. && cd .. && ${RMDIR} levels)
.for l in DX_Boulderdash Supaplex
	@${FIND} ${WRKDIR}/${PORTNAME}/${l} -name '*.level' | ${XARGS} ${CHMOD} 644
.endfor

.for l in ${LEVELS_BD_FANS:S/$/.zip/} Puzzles_v1.8.zip
	@${UNZIP_CMD} -qo -d ${WRKDIR}/${PORTNAME} ${_DISTDIR}/${l}
.endfor
	@${UNZIP_CMD} -qo -d ${WRKDIR}/${PORTNAME}/Tutorials ${_DISTDIR}/Tutorial_Alpha.zip
		@(cd ${WRKDIR}/${PORTNAME}/Tutorials && ${MV} "Tutorial Alpha" rnd_tutorial_alpha)
	@(cd ${WRKDIR}/${PORTNAME} && ${MV} "Alan's_Random_Levels" Alans_Random_Levels)
	@(cd ${WRKDIR}/${PORTNAME} && ${MV} "Veysi Orak 2006" Veysi_Orak_2006)
	@${RM} -f ${WRKDIR}/${PORTNAME}/Readme.txt

do-install:
	@(cd ${WRKDIR}/${PORTNAME} && ${COPYTREE_SHARE} . ${DATADIR}/levels)

post-install:
# Dynamically generate part of the PLIST, because the Levels are large
.for l in ${LEVELS_ARTSOFT}
	@${FIND} ${DATADIR}/levels/${l}/ ! -type d | ${SED} 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} -ds ${DATADIR}/levels/${l}/ -type d | \
		${SED} -E -e 's,(.*),@unexec ${RMDIR} "\1" 2>/dev/null || true,' >> ${TMPPLIST}
.endfor

.for l in ${LEVELS_BD_FANS} Puzzles
	@${FIND} ${DATADIR}/levels/${l}/ ! -type d | ${SED} 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} -ds ${DATADIR}/levels/${l}/ -type d | \
		${SED} -E -e 's,(.*),@unexec ${RMDIR} "\1" 2>/dev/null || true,' >> ${TMPPLIST}
.endfor
	@${FIND} ${DATADIR}/levels/Tutorials/rnd_tutorial_alpha/ ! -type d | ${SED} 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} -ds ${DATADIR}/levels/Tutorials/rnd_tutorial_alpha/ -type d | \
		${SED} -E -e 's,(.*),@unexec ${RMDIR} "\1" 2>/dev/null || true,' >> ${TMPPLIST}

# Symlink Levels which can use Rocks'n'Diamonds and R'n'D jue
.if exists(${PREFIX}/share/rocksndiamonds) && ${PORT_OPTIONS:MRnD_jue}
.for l in ${LEVELS_ARTSOFT} ${LEVELS_BD_FANS} Puzzles
		@${LN} -sf ${DATADIR}/levels/${l} ${PREFIX}/share/rocksndiamonds/levels
.endfor
		@${LN} -sf ${DATADIR}/levels/Tutorials/rnd_tutorial_alpha ${PREFIX}/share/rocksndiamonds/levels/Tutorials
.endif

.if exists(${PREFIX}/share/rnd_jue) && ${PORT_OPTIONS:MRnD}
.for l in ${LEVELS_ARTSOFT} ${LEVELS_BD_FANS} Puzzles
		@${LN} -sf ${DATADIR}/levels/${l} ${PREFIX}/share/rnd_jue/levels
.endfor
		@${LN} -sf ${DATADIR}/levels/Tutorials/rnd_tutorial_alpha ${PREFIX}/share/rnd_jue/levels/Tutorials
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
