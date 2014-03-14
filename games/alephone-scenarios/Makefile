# Created by: alepulver
# $FreeBSD$

PORTNAME=	scenarios
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://files3.bungie.org/trilogy/:bungie \
		http://files5.bungie.org/marathon/:rubicon \
		http://nardofiles.bungie.org/:nardofiles \
		http://eternal.bungie.org/files/_releases/:eternal \
		SF/../emr3:emr \
		http://ryoko.treellama.org/:gray
PKGNAMEPREFIX=	alephone-
DISTFILES=	#
DIST_SUBDIR=	alephone
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free scenarios for the Aleph One engine

RUN_DEPENDS=	alephone:${PORTSDIR}/games/alephone

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS_MULTI=	PACKS
OPTIONS_MULTI_PACKS=	EMR ETERNAL EVIL RED RUBICON TI GRAY
OPTIONS_DEFAULT=	EVIL RED
EMR_DESC=	Install Excalibur: Morgana's Revenge data
ETERNAL_DESC=	Install Eternal X data
EVIL_DESC=	Install Marathon Evil data
RED_DESC=	Install Marathon Red data
RUBICON_DESC=	Install Rubicon X data
TI_DESC=	Install Tempus Irae data
GRAY_DESC=	Install The gray incident data

SUB_FILES=	wrapper

NO_STAGE=	yes
.include <bsd.port.options.mk>

DATADIR!=	cd ${PORTSDIR}/games/alephone && ${MAKE} -V DATADIR

.if ${PORT_OPTIONS:MEMR}
EMR_FILE=	emr-3.0-0602.tgz
DISTFILES+=	${EMR_FILE}:emr
PLIST_SUB+=	EMR=""
AO_PACKS+=	emr
DESKTOP_ENTRIES+="Excalibur: Morgana's Revenge" "" "" "alephone-emr" \
		"Game;ActionGame;" false
.else
PLIST_SUB+=	EMR="@comment "
.endif

.if ${PORT_OPTIONS:METERNAL}
DISTFILES+=	EternalXv103Full${EXTRACT_SUFX}:eternal
EXTRACT_ONLY+=	EternalXv103Full${EXTRACT_SUFX}
PLIST_SUB+=	ETERNAL=""
AO_PACKS+=	eternal
DESKTOP_ENTRIES+="Eternal X" "" "" "alephone-eternal" \
		"Game;ActionGame;" false
.else
PLIST_SUB+=	ETERNAL="@comment "
.endif

.if ${PORT_OPTIONS:MEVIL}
DISTFILES+=	MarathonEvil${EXTRACT_SUFX}:bungie
EXTRACT_ONLY+=	MarathonEvil${EXTRACT_SUFX}
PLIST_SUB+=	EVIL=""
AO_PACKS+=	evil
DESKTOP_ENTRIES+="Evil" "" "" "alephone-evil" \
		"Game;ActionGame;" false
.else
PLIST_SUB+=	EVIL="@comment "
.endif

.if ${PORT_OPTIONS:MRED}
DISTFILES+=	MarathonRED${EXTRACT_SUFX}:bungie
EXTRACT_ONLY+=	MarathonRED${EXTRACT_SUFX}
PLIST_SUB+=	RED=""
AO_PACKS+=	red
DESKTOP_ENTRIES+="Marathon Red" "" "" "alephone-red" \
		"Game;ActionGame;" false
.else
PLIST_SUB+=	RED="@comment "
.endif

.if ${PORT_OPTIONS:MRUBICON}
DISTFILES+=	marathonRubiconX${EXTRACT_SUFX}:rubicon
EXTRACT_ONLY+=	marathonRubiconX${EXTRACT_SUFX}
PLIST_SUB+=	RUBICON=""
AO_PACKS+=	rubicon
DESKTOP_ENTRIES+="Rubicon X" "" "" "alephone-rubicon" \
		"Game;ActionGame;" false
.else
PLIST_SUB+=	RUBICON="@comment "
.endif

.if ${PORT_OPTIONS:MTI}
DISTFILES+=	Tempus_Irae${EXTRACT_SUFX}:nardofiles
EXTRACT_ONLY+=	Tempus_Irae${EXTRACT_SUFX}
PLIST_SUB+=	TI=""
AO_PACKS+=	tempus_irae
DESKTOP_ENTRIES+="Tempus Irae" "" "" "alephone-tempus_irae" \
		"Game;ActionGame;" false
.else
PLIST_SUB+=	TI="@comment "
.endif

.if ${PORT_OPTIONS:MGRAY}
DISTFILES+=	tgi${EXTRACT_SUFX}:gray
EXTRACT_ONLY+=	tgi${EXTRACT_SUFX}
PLIST_SUB+=	GRAY=""
AO_PACKS+=	gray
DESKTOP_ENTRIES+="The Gray Incident" "" "" "alephone-gray" \
		"Game;ActionGame;" false
.else
PLIST_SUB+=	GRAY="@comment "
.endif

post-extract:
.if ${PORT_OPTIONS:MEMR}
	@${TAR} zxf ${DISTDIR}/${DIST_SUBDIR}/${EMR_FILE} -C ${WRKDIR}
	@${MKDIR} ${WRKSRC}/emr
	@cd ${WRKSRC}/${EMR_FILE:S/-0602.tgz//} && \
		${MV} share-emr/* ../emr && \
		${MV} share-doc-emr ../emr/docs && \
		${MV} README ../emr/docs
.endif
.if ${PORT_OPTIONS:METERNAL}
	@cd ${WRKSRC} && ${MV} "Eternal X 1.0.3" eternal
	@cd ${WRKSRC}/eternal && \
		${FIND} . -type d -print0 | ${XARGS} -0 ${CHMOD} 755 && \
		${FIND} . -type f -print0 | ${XARGS} -0 ${CHMOD} 644
.endif
.if ${PORT_OPTIONS:MEVIL}
	@cd ${WRKSRC} && ${MV} "Marathon EVIL" evil
.endif
.if ${PORT_OPTIONS:MRED}
	@cd ${WRKSRC} && ${MV} "Marathon RED" red
.endif
.if ${PORT_OPTIONS:MRUBICON}
	@cd ${WRKSRC} && ${MV} "Rubicon X "?? rubicon
.endif
.if ${PORT_OPTIONS:MTI}
	@cd ${WRKSRC} && ${MV} Tempus_Irae tempus_irae
	@cd ${WRKSRC}/tempus_irae && \
		${FIND} . -type d -print0 | ${XARGS} -0 ${CHMOD} 755 && \
		${FIND} . -type f -print0 | ${XARGS} -0 ${CHMOD} 644
.endif
.if ${PORT_OPTIONS:MGRAY}
	@cd ${WRKSRC} && ${MV} "The Gray Incident" gray
.endif

pre-install:
.for f in ${AO_PACKS}
	@cd ${WRKSRC} && ${SED} -e 's|%%GAMEDIR%%|${f}|' wrapper > alephone-${f}
.endfor

do-install:
.for f in ${AO_PACKS}
	${INSTALL_SCRIPT} ${WRKDIR}/alephone-${f} ${PREFIX}/bin
	${CP} -R ${WRKSRC}/${f} ${DATADIR}
	@cd ${DATADIR}/${f} && \
		${FIND} . -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE} && \
		${FIND} . -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
.endfor
.if ${PORT_OPTIONS:MRUBICON}
	@${LN} -s ${DATADIR}/[A-Z]* ${DATADIR}/rubicon
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
