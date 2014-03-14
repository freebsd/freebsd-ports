# Created by: Michael Alyn Miller <malyn@strangeGizmo.com>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	1.0
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://www.mariusnet.com/files/Marathon/
PKGNAMEPREFIX=	alephone-
DISTFILES=	#
DIST_SUBDIR=	alephone

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Released Marathon data files for the Aleph One port

RUN_DEPENDS=	alephone:${PORTSDIR}/games/alephone

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_CDROM=	Bungie/Microsoft do not allow charging for Marathon data files

OPTIONS_MULTI=	AO
OPTIONS_MULTI_AO=	MARATHON DURANDAL INFINITY
OPTIONS_DEFAULT=	MARATHON DURANDAL INFINITY

MARATHON_DESC=	Install Marathon data
DURANDAL_DESC=	Install Marathon 2: Durandal data
INFINITY_DESC=	Install Marathon Infinity data

SUB_FILES=	wrapper

NO_STAGE=	yes
.include <bsd.port.options.mk>

DATADIR!=	cd ${PORTSDIR}/games/alephone && ${MAKE} -V DATADIR

.if ${PORT_OPTIONS:MMARATHON}
DISTFILES+=	M1A1${EXTRACT_SUFX}
PLIST_SUB+=	MARATHON=""
AO_PACKS+=	marathon
DESKTOP_ENTRIES+="Marathon" "" "" "alephone-marathon" \
		"Game;ActionGame;" false
.else
PLIST_SUB+=	MARATHON="@comment "
.endif

.if ${PORT_OPTIONS:MDURANDAL}
DISTFILES+=	Marathon2${EXTRACT_SUFX}
PLIST_SUB+=	DURANDAL=""
AO_PACKS+=	durandal
DESKTOP_ENTRIES+="Marathon 2: Durandal" "" "" "alephone-durandal" \
		"Game;ActionGame;" false
.else
PLIST_SUB+=	DURANDAL="@comment "
.endif

.if ${PORT_OPTIONS:MINFINITY}
DISTFILES+=	MarathonInfinity${EXTRACT_SUFX}
PLIST_SUB+=	INFINITY=""
AO_PACKS+=	infinity
DESKTOP_ENTRIES+="Marathon Infinity" "" "" "alephone-infinity" \
		"Game;ActionGame;" false
.else
PLIST_SUB+=	INFINITY="@comment "
.endif

post-extract:
.if ${PORT_OPTIONS:MMARATHON}
	@cd ${WRKSRC} && ${MV} M1A1 marathon
.endif
.if ${PORT_OPTIONS:MDURANDAL}
	@cd ${WRKSRC} && ${MV} "Marathon 2" durandal
.endif
.if ${PORT_OPTIONS:MINFINITY}
	@cd ${WRKSRC} && ${MV} "Marathon Infinity" infinity
.endif

pre-install:
.for f in ${AO_PACKS}
	@cd ${WRKSRC} && ${SED} -e 's|%%GAMEDIR%%|${f}|' wrapper > alephone-${f}
.endfor

do-install:
.for f in ${AO_PACKS}
	${INSTALL_SCRIPT} ${WRKSRC}/alephone-${f} ${PREFIX}/bin
	${CP} -R ${WRKSRC}/${f} ${DATADIR}
.endfor

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
