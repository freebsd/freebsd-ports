# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	themes
PORTVERSION=	2.0
PORTREVISION=	5
CATEGORIES=	games python
MASTER_SITES=	http://themes.pysycache.free.fr/
PKGNAMEPREFIX=	pysycache-
DISTFILES=	#
DIST_SUBDIR=	pysycache

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Pysycache themes support

RUN_DEPENDS=	pysycache.py:${PORTSDIR}/games/pysycache

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=	${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}
DATADIR=	${PREFIX}/share/${DIST_SUBDIR}

OPTIONS_DEFINE=	ANIMALS EARTH FOOD PLANTS SKY SPORTS VEHICLE WORLD AFRICA
ANIMALS_DESC=	Animals move mouse theme
EARTH_DESC=	Earth move mouse theme
FOOD_DESC=	Food move mouse theme
PLANTS_DESC=	Plants move mouse theme
SKY_DESC=	Sky move mouse theme
SPORTS_DESC=	Sports move mouse theme
VEHICLE_DESC=	Vehicle move mouse theme
WORLD_DESC=	World move mouse theme
AFRICA_DESC=		Africa activity theme

OPTIONS_DEFAULT=	ANIMALS EARTH FOOD PLANTS SKY SPORTS VEHICLE WORLD AFRICA

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANIMALS}
DISTFILES+=	animals-${PORTVERSION}.zip
PLIST_SUB+=	ANIMALS=""
FLAG_THEME=	true
HAVE_THEME+=	animals
.else
PLIST_SUB+=	ANIMALS="@comment "
.endif

.if ${PORT_OPTIONS:MEARTH}
DISTFILES+=	earth-${PORTVERSION}.zip
PLIST_SUB+=	EARTH=""
FLAG_THEME=	true
HAVE_THEME+=	earth
.else
PLIST_SUB+=	EARTH="@comment "
.endif

.if ${PORT_OPTIONS:MFOOD}
DISTFILES+=	food-${PORTVERSION}.zip
PLIST_SUB+=	FOOD=""
FLAG_THEME=	true
HAVE_THEME+=	food
.else
PLIST_SUB+=	FOOD="@comment "
.endif

.if ${PORT_OPTIONS:MPLANTS}
DISTFILES+=	plants-${PORTVERSION}.zip
PLIST_SUB+=	PLANTS=""
FLAG_THEME=	true
HAVE_THEME+=	plants
.else
PLIST_SUB+=	PLANTS="@comment "
.endif

.if ${PORT_OPTIONS:MSKY}
DISTFILES+=	sky-${PORTVERSION}.zip
PLIST_SUB+=	SKY=""
FLAG_THEME=	true
HAVE_THEME+=	sky
.else
PLIST_SUB+=	SKY="@comment "
.endif

.if ${PORT_OPTIONS:MSPORTS}
DISTFILES+=	sports-${PORTVERSION}.zip
PLIST_SUB+=	SPORTS=""
FLAG_THEME=	true
HAVE_THEME+=	sports
.else
PLIST_SUB+=	SPORTS="@comment "
.endif

.if ${PORT_OPTIONS:MVEHICLE}
DISTFILES+=	vehicle-${PORTVERSION}.zip
PLIST_SUB+=	VEHICLE=""
FLAG_THEME=	true
HAVE_THEME+=	vehicle
.else
PLIST_SUB+=	VEHICLE="@comment "
.endif

.if ${PORT_OPTIONS:MWORLD}
DISTFILES+=	world-${PORTVERSION}.zip
PLIST_SUB+=	WORLD=""
FLAG_THEME=	true
HAVE_THEME+=	world
.else
PLIST_SUB+=	WORLD="@comment "
.endif

.if ${PORT_OPTIONS:MAFRICA}
DISTFILES+=	africa-${PORTVERSION}.zip
PLIST_SUB+=	AFRICA=""
FLAG_THEME=	true
HAVE_THEME+=	africa
.else
PLIST_SUB+=	AFRICA="@comment "
.endif

pre-fetch:
.if defined(FLAG_THEME)
	@${TRUE}
.else
	@${ECHO} "######################"
	@${ECHO} "#                    #"
	@${ECHO} "# No themes selected #"
	@${ECHO} "#                    #"
	@${ECHO} "######################"
	@${FALSE}
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
.for OPT in ${HAVE_THEME}
	@${UNZIP_CMD} -q ${_DISTDIR}/${OPT}-${PORTVERSION}.zip -d ${WRKSRC}
.endfor

do-install:
	@cd ${WRKSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

.include <bsd.port.mk>
