# New ports collection makefile for:	mame-extras
# Date created:				2007-01-15
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	mame
PORTVERSION=	0.125
CATEGORIES=	emulators
MASTER_SITES=	http://www.mame.net/:mame \
		http://www.mameworld.net/mameinfo/update/:mameinfo \
		http://zemamu.free.fr/:icons \
		http://cheat.retrogames.com/:cheats \
		http://www.mameworld.net/highscore/:hiscore \
		http://www.arcade-history.com/dats/:history
PKGNAMESUFFIX=	-extras
DISTFILES=	#
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Additional files for MAME (Multi Arcade Machine Emulator)

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	ARTWORK "Install artwork files" off \
		CHEATS "Install game cheats" on \
		HISCORE "Install high scores" on \
		HISTORY "Install game history, hints and tips" on \
		ICONS "Install game icons" off \
		MAMEINFO "Install information about the games" on \
		SAMPLES "Install sound samples (required by some games)" off

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not install on powerpc
.endif

.if defined(WITH_ARTWORK)
ARTWORK=	maze armora asteroid astdelux astdelu1 atarifb barrier bzone \
		boothill buckrog clowns demon destroyr dotron dragrace frogs \
		gollygho gorf gunfight minferno lagunar llander missile \
		nitedrvr omegrace portrait skydiver solarq spcenctr sitv \
		invaders invadpt2 invaddlx spacewar spyhunt subroc3d sspeedr \
		turbo videopin warlords warrior
BEZEL=		1942 1943 1943kai assault astinvad berzerk bbonk bnj btime \
		bbros captaven carnival commando deadeye desertgu digdug \
		dkong dkongjr ddragon2 eyes frogger galagamw gorfpgm1 \
		gypsyjug gyruss irobot ikari inthunt jumpbug junglek kangaroo \
		kchamp mplanets mappy mario mspacman offtwall pacman pepper2 \
		puckman polepos poleps2a popeye redbaron robotbwl robotron \
		robotryo slammast scramble slyspy panic spiders sprint2 \
		stratvox sf2ui superbug sbbros suprglob term2 turtles venture \
		wotw xevious \
		airwolf archrivl arknid2u baddudes ballbomb bsktball bionicc \
		centiped colony7 crash crossbow cbuster defender dkong3 \
		ddragon dyger elevator eyes2 forgottn galaga galaxian ghoulsu \
		ikari3 journey joust kidniki kungfum ladybug msword maniach \
		marinedt msh matmania opwolf polepos2 qbert qbertqub qix \
		rallybik ripoff seawolf seawolf2 sharkatt skyshark snapjack \
		snowbros starcas stargate sf2ce scobra scontra superman targ \
		tknight theend timber timeplt triplep upndown wardner xmcota \
		zookeep
DISTFILES+=	${ARTWORK:S|^|artwork/|:S/$/${EXTRACT_SUFX}:mame/} \
		${BEZEL:S|^|bezel/|:S/$/${EXTRACT_SUFX}:mame/}
PLIST_SUB+=	ARTWORK=""
.else
PLIST_SUB+=	ARTWORK="@comment "
.endif

.if !defined(WITHOUT_CHEATS)
DISTFILES+=	cheat117${EXTRACT_SUFX}:cheats
EXTRACT_ONLY+=	cheat117${EXTRACT_SUFX}
PLIST_SUB+=	CHEATS=""
.else
PLIST_SUB+=	CHEATS="@comment "
.endif

.if !defined(WITHOUT_HISCORE)
DISTFILES+=	hs17032007${EXTRACT_SUFX}:hiscore
EXTRACT_ONLY+=	hs17032007${EXTRACT_SUFX}
PLIST_SUB+=	HISCORE=""
.else
PLIST_SUB+=	HISCORE="@comment "
.endif

.if !defined(WITHOUT_HISTORY)
DISTFILES+=	mamehistory${PORTVERSION:S/0.//}${EXTRACT_SUFX}:history
EXTRACT_ONLY+=	mamehistory${PORTVERSION:S/0.//}${EXTRACT_SUFX}
PLIST_SUB+=	HISTORY=""
.else
PLIST_SUB+=	HISTORY="@comment "
.endif

.if defined(WITH_ICONS)
DISTFILES+=	icons${EXTRACT_SUFX}:icons
EXTRACT_ONLY+=	icons${EXTRACT_SUFX}
PLIST_SUB+=	ICONS=""
.else
PLIST_SUB+=	ICONS="@comment "
.endif

.if !defined(WITHOUT_MAMEINFO)
EXTRACT_DEPENDS+=	7z:${PORTSDIR}/archivers/p7zip
MAMEINFO=	Mameinfo${PORTVERSION:S/.//}
MAMEINFO_N_UP=	#
. for f in ${MAMEINFO_N_UP}
MAMEINFO_UP+=	update${PORTVERSION:S/.//}u${f}/Update
. endfor
DISTFILES+=	${MAMEINFO:S/$/${EXTRACT_SUFX}:mameinfo/} \
		${MAMEINFO_UP:S/$/${EXTRACT_SUFX}:mameinfo/}
EXTRACT_ONLY+=	${MAMEINFO:S/$/${EXTRACT_SUFX}/}
PLIST_SUB+=	MAMEINFO=""
.else
PLIST_SUB+=	MAMEINFO="@comment "
.endif

.if defined(WITH_SAMPLES)
SAMPLES=	armora astrob astrof battles berzerk blockade boothill bosco \
		buckrog carnival circus congo cosmicg depthch dkong dkongjr \
		elim2 fantasy frogs galaga gaplus gorf gridlee invinco mario \
		monsterb natodef polepos pulsar qbert rallyx reactor ripoff \
		sasuke seawolf sharkatt solarq spacefb spacfury invaders \
		spaceod panic spacewar starcas starcrus subroc3d sundance \
		tailg tankbatt targ thehand thief turbo vanguard warrior wow \
		xevious xevios zaxxon zektor
DISTFILES+=	${SAMPLES:S|^|samples/|:S/$/${EXTRACT_SUFX}:mame/}
EXTRACT_ONLY+=	${SAMPLES:S|^|samples/|:S/$/${EXTRACT_SUFX}/}
PLIST_SUB+=	SAMPLES=""
.else
PLIST_SUB+=	SAMPLES="@comment "
.endif

post-extract:
.if defined(WITH_ICONS)
	@cd ${WRKSRC} && ${MV} "unneeded + UI" unneeded_+_ui
.endif
.if !defined(WITHOUT_MAMEINFO)
	@cd ${WRKDIR} && 7z x ${MAMEINFO}.exe
. for f in ${MAMEINFO_UP:S|^|${DISTDIR}/${DIST_SUBDIR}/|:S/$/${EXTRACT_SUFX}/}
	@cd ${WRKDIR} && ${UNZIP_CMD} -c ${f} mameinfo.dif | ${PATCH} -p1 \
		2>/dev/null
. endfor
.endif

do-install:
	${MKDIR} ${DATADIR}
.if defined(WITH_ARTWORK)
	${MKDIR} ${DATADIR}/artwork
. for f in ${ARTWORK:S|^|artwork/|} ${BEZEL:S|^|bezel/|}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f}${EXTRACT_SUFX} \
		${DATADIR}/artwork
. endfor
.endif
.if !defined(WITHOUT_CHEATS)
	${INSTALL_DATA} ${WRKSRC}/cheat.dat ${DATADIR}
.endif
.if !defined(WITHOUT_HISCORE)
	${INSTALL_DATA} ${WRKSRC}/hiscore.dat ${DATADIR}
.endif
.if !defined(WITHOUT_HISTORY)
	${INSTALL_DATA} ${WRKSRC}/history.dat ${DATADIR}
.endif
.if defined(WITH_ICONS)
	${MKDIR} ${DATADIR}/icons
	${FIND} ${WRKSRC} -type f -depth 1 -name "*.ico" | ${XARGS} -J % \
		${INSTALL_DATA} % ${DATADIR}/icons
. for f in unneeded_+_ui daphne agemame zinc pinmame
	${MKDIR} ${DATADIR}/icons/${f}
	${INSTALL_DATA} ${WRKSRC}/${f}/*.ico ${DATADIR}/icons/${f}
. endfor
.endif
.if !defined(WITHOUT_MAMEINFO)
	${INSTALL_DATA} ${WRKSRC}/mameinfo.dat ${DATADIR}
	${MKDIR} ${DATADIR}/docs
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DATADIR}/docs
.endif
.if defined(WITH_SAMPLES)
	${MKDIR} ${DATADIR}/samples
	${INSTALL_DATA} ${WRKSRC}/*.wav ${DATADIR}/samples
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
