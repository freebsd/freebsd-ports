# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rocksndiamonds-data
PORTVERSION=	20131106
PORTREVISION=	2
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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Additional Player Levels for Rocks'n'Diamonds and R'n'D jue

DATADIR=	${PREFIX}/share/rocksndiamonds
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

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

post-extract:
	@cd ${WRKSRC}/levels && ${MV} * .. && cd .. && ${RMDIR} levels
	@cd ${WRKSRC} && ${MV} "Alan's_Random_Levels" Alans_Random_Levels
	@cd ${WRKSRC} && ${MV} "Gavin Davidson 2006" Gavin_Davidson_2006
	@cd ${WRKSRC} && ${MV} "Veysi Orak 2006" Veysi_Orak_2006
	@cd ${WRKSRC} && ${RM} Readme.txt levelinfo.conf

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/levels
	@cd ${STAGEDIR}${PREFIX} && ${FIND} ${DATADIR_REL}/levels \
		-type f >> ${TMPPLIST}
# Create symlinks to the levels for games/rnd_jue
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/rnd_jue/levels
.for l in ${LEVELS_ARTSOFT} ${LEVELS_BD_FANS} Alans_Random_Levels \
		Gavin_Davidson_2006 Puzzles Veysi_Orak_2006
	@${RLN} ${STAGEDIR}${DATADIR}/levels/${l} \
		${STAGEDIR}${PREFIX}/share/rnd_jue/levels
	@${ECHO_CMD} share/rnd_jue/levels/${l} >> ${TMPPLIST}
.endfor

.include <bsd.port.mk>
