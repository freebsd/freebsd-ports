# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rocksndiamonds-data
PORTVERSION=	20131106
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.artsoft.org/RELEASES/rocksndiamonds/levels/:levels \
		http://www.artsoft.org/RELEASES/unix/rocksndiamonds/levels/:unix_levels \
		SF/nemysisfreebsdp/${CATEGORIES}/rocksndiamonds/
DISTFILES=	BD2K3-1.0.0.zip:levels \
		Boulder_Dash_Dream-1.0.0.zip:levels \
		Emerald_Mine_Club-2.1.1.7z:levels \
		Snake_Bite-1.0.0.zip:levels \
		Zelda-1.0.0.zip:levels \
		ZeldaII-1.0.0.zip:levels \
		rockslevels-sp-1.0.tar.gz:unix_levels \
		rockslevels-dx-1.0.tar.gz:unix_levels \
		${LEVELS_BD_FANS:S/$/.zip/} \
		Alans_Random_Levels.zip \
		Gavin_Davidson_2006.zip \
		Puzzles_v1.8.zip \
		Veysi_Orak_2006.zip
DIST_SUBDIR=	rocksndiamonds
EXTRACT_ONLY=	#empty
EXTRACT_ONLY_7z=Emerald_Mine_Club-2.1.1.7z

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Additional Player Levels for Rocks'n'Diamonds and R'n'D jue

EXTRACT_DEPENDS+=${UNZIP_CMD}:archivers/unzip

USES=		7z:partial
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
WRKSRC=		${WRKDIR}/${PORTNAME} # for EXTRACT_WRKDIR

SUB_FILES=	pkg-message pkg-deinstall

LEVELS_ARTSOFT=	BD2K3 Boulder_Dash_Dream DX_Boulderdash Emerald_Mine_Club \
		Snake_Bite Supaplex zelda zelda2

LEVELS_BD_FANS=	42_Steps Alexanders_Levels Arcade_Levels Be_a_bug \
		Contest_Levels Danilo_Parantar_Serrano \
		Danilo_Parantar_Serrano_2 Earth_Shaker_Collection Glasses \
		Hard_Skills Haspeton Learning_Maths Little_Games Magic_CEs \
		Manuel Manuels_Sokoban_Levels Master-Rocks Memory \
		Mini_Levels_Ryan Missions Mixed_Levels Mixed_Levels_2 \
		MultiRandomLevel My_Levels_of_Fun Negundo_World_2 \
		Negundo_World_3 P98_Level_Pack_1 Pacman Random_Games \
		Rocks_n_Diamonds_Fun Ryans_Random_Levels Slippery_Ground \
		Space_Invaders Space_Invaders_2 Springlis_Levels Stinky \
		Super_BD-Rock Super_Comic_Levels Venatir Warparound_Murphy \
		Time_Gate_Rush

OPTIONS_SINGLE=	SYMLINK
OPTIONS_SINGLE_SYMLINK=	RnD RnD_jue

OPTIONS_DEFAULT=	RnD_jue

RnD_DESC=	Levels default for Rocks'n'Diamonds
RnD_jue_DESC=	Levels default for R'n'D jue

PREFIX=		/usr/local

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRnD}
RUN_DEPENDS+=	rocksndiamonds:games/rocksndiamonds
DATADIR=	${PREFIX}/share/rocksndiamonds
DATADIR1=	${PREFIX}/share/rnd_jue
.endif

.if ${PORT_OPTIONS:MRnD_jue}
RUN_DEPENDS+=	rnd_jue:games/rnd_jue
DATADIR=	${PREFIX}/share/rnd_jue
DATADIR1=	${PREFIX}/share/rocksndiamonds
.endif

post-extract-script:
.for l in BD2K3-1.0.0.zip Snake_Bite-1.0.0.zip Zelda-1.0.0.zip \
		ZeldaII-1.0.0.zip Boulder_Dash_Dream-1.0.0.zip
	@${UNZIP_CMD} -qo -d ${WRKDIR}/${PORTNAME} ${_DISTDIR}/${l}
.endfor

.for l in rockslevels-dx-1.0.tar.gz rockslevels-sp-1.0.tar.gz
	@${TAR} xfjp ${_DISTDIR}/${l} -C ${WRKDIR}/${PORTNAME}
.endfor
	@(cd ${WRKDIR}/${PORTNAME}/levels && ${MV} * .. && cd .. && \
		${RMDIR} levels)

.for l in DX_Boulderdash Supaplex
	@${FIND} ${WRKDIR}/${PORTNAME}/${l} -name '*.level' | ${XARGS} \
		${CHMOD} 644
.endfor

.for l in ${LEVELS_BD_FANS:S/$/.zip/} Alans_Random_Levels.zip \
		Gavin_Davidson_2006.zip Puzzles_v1.8.zip Veysi_Orak_2006.zip
	@${UNZIP_CMD} -qo -d ${WRKDIR}/${PORTNAME} ${_DISTDIR}/${l}
.endfor

	@(cd ${WRKDIR}/${PORTNAME} && ${MV} "Alan's_Random_Levels" \
		Alans_Random_Levels)
	@(cd ${WRKDIR}/${PORTNAME} && ${MV} "Gavin Davidson 2006" \
		Gavin_Davidson_2006)
	@(cd ${WRKDIR}/${PORTNAME} && ${MV} "Veysi Orak 2006" Veysi_Orak_2006)
	@(cd ${WRKDIR}/${PORTNAME} && ${RM} -f Readme.txt levelinfo.conf)

do-install:
	@(cd ${WRKDIR}/${PORTNAME} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DATADIR}/levels)

	@cd ${STAGEDIR}${PREFIX} && ${FIND} ${DATADIR_REL}/levels \
		-type f >> ${TMPPLIST}

# Symlink Levels which can use Rocks'n'Diamonds and R'n'D jue
.if exists(${PREFIX}/share/rocksndiamonds) && ${PORT_OPTIONS:MRnD_jue}
.for l in ${LEVELS_ARTSOFT} ${LEVELS_BD_FANS} Alans_Random_Levels \
	Gavin_Davidson_2006 Puzzles Veysi_Orak_2006
		@${LN} -sf ${DATADIR}/levels/${l} \
			${DATADIR1}/levels/
.endfor
.endif

.if exists(${PREFIX}/share/rnd_jue) && ${PORT_OPTIONS:MRnD}
.for l in ${LEVELS_ARTSOFT} ${LEVELS_BD_FANS} Alans_Random_Levels \
		 Gavin_Davidson_2006 Puzzles Veysi_Orak_2006
		@${LN} -sf ${DATADIR}/levels/${l} \
			${DATADIR1}/levels/
.endfor
.endif

.include <bsd.port.mk>
