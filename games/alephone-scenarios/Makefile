PORTNAME=	scenarios
PORTVERSION=	1.0
PORTREVISION=	10
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
WWW=		http://source.bungie.org/get/

RUN_DEPENDS=	alephone:games/alephone

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS_MULTI=	PACKS
OPTIONS_MULTI_PACKS=	EMR ETERNAL EVIL RED RUBICON TI GRAY
OPTIONS_DEFAULT=	EVIL RED
OPTIONS_SUB=	yes

EMR_DESC=	Excalibur: Morgana's Revenge data
ETERNAL_DESC=	Eternal X data
EVIL_DESC=	Marathon Evil data
RED_DESC=	Marathon Red data
RUBICON_DESC=	Rubicon X data
TI_DESC=	Tempus Irae data
GRAY_DESC=	The Gray Incident data

SUB_FILES=	wrapper

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
. if ${PORT_OPTIONS:METERNAL} || ${PORT_OPTIONS:MRUBICON}
USES=		zip:infozip
. endif
.endif

DATADIR!=	cd ${PORTSDIR}/games/alephone && ${MAKE} -V DATADIR

.if ${PORT_OPTIONS:MEMR}
. if ${OPSYS} == FreeBSD
EXTRACT_DEPENDS=gtar:archivers/gtar
TAR=		${LOCALBASE}/bin/gtar
. endif
EMR_FILE=	emr-3.0-0602.tgz
DISTFILES+=	${EMR_FILE}:emr
AO_PACKS+=	emr
DESKTOP_ENTRIES+="Excalibur: Morgana's Revenge" "" "" "alephone-emr" \
		"Game;ActionGame;" false
.endif

.if ${PORT_OPTIONS:METERNAL}
DISTFILES+=	EternalXv103Full${EXTRACT_SUFX}:eternal
EXTRACT_ONLY+=	EternalXv103Full${EXTRACT_SUFX}
AO_PACKS+=	eternal
DESKTOP_ENTRIES+="Eternal X" "" "" "alephone-eternal" \
		"Game;ActionGame;" false
.endif

.if ${PORT_OPTIONS:MEVIL}
DISTFILES+=	MarathonEvil${EXTRACT_SUFX}:bungie
EXTRACT_ONLY+=	MarathonEvil${EXTRACT_SUFX}
AO_PACKS+=	evil
DESKTOP_ENTRIES+="Evil" "" "" "alephone-evil" \
		"Game;ActionGame;" false
.endif

.if ${PORT_OPTIONS:MRED}
DISTFILES+=	MarathonRED${EXTRACT_SUFX}:bungie
EXTRACT_ONLY+=	MarathonRED${EXTRACT_SUFX}
AO_PACKS+=	red
DESKTOP_ENTRIES+="Marathon Red" "" "" "alephone-red" \
		"Game;ActionGame;" false
.endif

.if ${PORT_OPTIONS:MRUBICON}
DISTFILES+=	marathonRubiconX${EXTRACT_SUFX}:rubicon
EXTRACT_ONLY+=	marathonRubiconX${EXTRACT_SUFX}
AO_PACKS+=	rubicon
DESKTOP_ENTRIES+="Rubicon X" "" "" "alephone-rubicon" \
		"Game;ActionGame;" false
.endif

.if ${PORT_OPTIONS:MTI}
DISTFILES+=	Tempus_Irae${EXTRACT_SUFX}:nardofiles
EXTRACT_ONLY+=	Tempus_Irae${EXTRACT_SUFX}
AO_PACKS+=	tempus_irae
DESKTOP_ENTRIES+="Tempus Irae" "" "" "alephone-tempus_irae" \
		"Game;ActionGame;" false
.endif

.if ${PORT_OPTIONS:MGRAY}
DISTFILES+=	tgi${EXTRACT_SUFX}:gray
EXTRACT_ONLY+=	tgi${EXTRACT_SUFX}
AO_PACKS+=	gray
DESKTOP_ENTRIES+="The Gray Incident" "" "" "alephone-gray" \
		"Game;ActionGame;" false
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
.endif
.if ${PORT_OPTIONS:MGRAY}
	@cd ${WRKSRC} && ${MV} "The Gray Incident" gray
.endif

pre-install:
.for f in ${AO_PACKS}
	@cd ${WRKDIR} && ${SED} -e 's|%%GAMEDIR%%|${f}|' wrapper > alephone-${f}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in ${AO_PACKS}
	${INSTALL_SCRIPT} ${WRKDIR}/alephone-${f} ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${DATADIR})
.endfor
.if ${PORT_OPTIONS:MRUBICON}
. for f in Fonts MML Themes
	@${LN} -s ${DATADIR}/${f} ${STAGEDIR}${DATADIR}/rubicon
. endfor
.endif

.include <bsd.port.mk>
