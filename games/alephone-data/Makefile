# New ports collection makefile for:	alephone-data
# Date created:		08 March 2001
# Whom:			Michael Alyn Miller <malyn@strangeGizmo.com>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://trilogyrelease.bungie.org/files/:bungie \
		ftp://ftp2.fileball.net/fileball/marathon/aleph1/alterations/:landscapes \
		http://nardofiles.bungie.org/:nardofiles
PKGNAMEPREFIX=	alephone-
DISTFILES=	#
DIST_SUBDIR=	alephone

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Released Marathon data files for the Aleph One port

RUN_DEPENDS=	alephone:${PORTSDIR}/games/alephone

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_CDROM=	Bungie/Microsoft do not allow charging for Marathon data files

OPTIONS=	MARATHON "Install Marathon data" on \
		DURANDAL "Install Marathon 2: Durandal data" on \
		INFINITY "Install Marathon Infinity data" on \
		LANDSCAPES "Install High Resolution landscapes" off \
		SHOTS_FIRED "Install High Resolution shots" off \
		TEXTURES "Install High Resolution textures" off

SUB_FILES=	wrapper

.include <bsd.port.pre.mk>

DATADIR!=	cd ${PORTSDIR}/games/alephone && ${MAKE} -V DATADIR

.if !defined(WITHOUT_MARATHON)
DISTFILES+=	M1A1${EXTRACT_SUFX}:bungie
PLIST_SUB+=	MARATHON=""
AO_PACKS+=	marathon
.else
PLIST_SUB+=	MARATHON="@comment "
.endif

.if !defined(WITHOUT_DURANDAL)
DISTFILES+=	Marathon2${EXTRACT_SUFX}:bungie
PLIST_SUB+=	DURANDAL=""
AO_PACKS+=	durandal
.else
PLIST_SUB+=	DURANDAL="@comment "
.endif

.if !defined(WITHOUT_INFINITY)
DISTFILES+=	MarathonInfinity${EXTRACT_SUFX}:bungie
PLIST_SUB+=	INFINITY=""
AO_PACKS+=	infinity
.else
PLIST_SUB+=	INFINITY="@comment "
.endif

.if empty(AO_PACKS)
IGNORE=		needs at least one game option (MARATHON, DURANDAL and INFINITY)
.endif

.if defined(WITH_LANDSCAPES) && \
    (!defined(WITHOUT_DURANDAL) || !defined(WITHOUT_INFINITY))
DISTFILES+=	LandscapeEnhancementPackv10${EXTRACT_SUFX}:landscapes
PLIST_SUB+=	LANDSCAPES=""
.else
PLIST_SUB+=	LANDSCAPES="@comment "
.endif

.if defined(WITH_SHOTS_FIRED)
DISTFILES+=	shots_fired${EXTRACT_SUFX}:nardofiles
PLIST_SUB+=	SHOTS_FIRED=""
.else
PLIST_SUB+=	SHOTS_FIRED="@comment "
.endif

.if defined(WITH_TEXTURES)
DISTFILES+=	TotalTextureEnhancementv61${EXTRACT_SUFX}:bungie
PLIST_SUB+=	TEXTURES=""
.else
PLIST_SUB+=	TEXTURES="@comment "
.endif

post-extract:
.if !defined(WITHOUT_MARATHON)
	@cd ${WRKSRC} && ${MV} M1A1 marathon
.endif
.if !defined(WITHOUT_DURANDAL)
	@cd ${WRKSRC} && ${MV} "Marathon 2" durandal
.endif
.if !defined(WITHOUT_INFINITY)
	@cd ${WRKSRC} && ${MV} "Marathon Infinity" infinity
.endif
.if defined(WITH_LANDSCAPES) && \
    (!defined(WITHOUT_DURANDAL) || !defined(WITHOUT_INFINITY))
. if !defined(WITHOUT_DURANDAL)
	@cd "${WRKSRC}/Landscape Enhancement Package/Marathon Infinity" && \
		${MV} "Landscapes (put content in 'Aleph One' folder)/Landscapes" ../../infinity && \
		${MV} "Script (put content in 'scripts' folder)/Infinity landscapes" ../../infinity/Scripts
. endif
. if !defined(WITHOUT_INFINITY)
	@cd "${WRKSRC}/Landscape Enhancement Package/Marathon 2 Durandal" && \
		${MV} "Landscapes (put content in 'Aleph One' folder) /Landscapes" ../../durandal && \
		${MV} "Script (put content in 'scripts' folder)/M2 landscapes" ../../durandal/Scripts
. endif
.endif
.if defined(WITH_TEXTURES)
. if !defined(WITHOUT_MARATHON)
	@cd "${WRKSRC}/Texture Enhancement Package 6.1" && \
		${MV} "Texture Folders/Textures/Revival DDS" ../marathon && \
		${MV} "Texture Scripts/Textures M1" ../marathon/Scripts
. endif
. if !defined(WITHOUT_DURANDAL)
	@${MKDIR} ${WRKSRC}/durandal/Textures
	@cd "${WRKSRC}/Texture Enhancement Package 6.1" && \
		${MV} "Texture Folders/Textures/Marathon 2 Textures" ../durandal && \
		${MV} "Texture Scripts/Textures M2" ../durandal/Scripts
. endif
. if !defined(WITHOUT_INFINITY)
	@${MKDIR} ${WRKSRC}/infinity/Textures
	@cd "${WRKSRC}/Texture Enhancement Package 6.1" && \
		${MV} "Texture Folders/Textures/Marathon Infinity Textures" ../infinity && \
		${MV} "Texture Scripts/Textures Moo" ../infinity/Scripts
. endif
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
.if defined(WITH_SHOTS_FIRED)
	cd ${WRKSRC} && ${CP} -R Scripts tex ${DATADIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
