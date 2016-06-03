# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	themes
PORTVERSION=	2.0
PORTREVISION=	7
CATEGORIES=	games python
MASTER_SITES=	http://themes.pysycache.free.fr/
PKGNAMEPREFIX=	pysycache-
DISTFILES=	#
DIST_SUBDIR=	pysycache

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pysycache themes support

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

RUN_DEPENDS=	pysycache.py:games/pysycache

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=	${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}
DATADIR=	${PREFIX}/share/${DIST_SUBDIR}

OPTIONS_MULTI=	THEME
OPTIONS_MULTI_THEME=	ANIMALS EARTH FOOD PLANTS SKY SPORTS VEHICLE WORLD AFRICA
OPTIONS_DEFAULT=	ANIMALS EARTH FOOD PLANTS SKY SPORTS VEHICLE WORLD AFRICA

ANIMALS_DESC=	Animals move mouse theme
EARTH_DESC=	Earth move mouse theme
FOOD_DESC=	Food move mouse theme
PLANTS_DESC=	Plants move mouse theme
SKY_DESC=	Sky move mouse theme
SPORTS_DESC=	Sports move mouse theme
VEHICLE_DESC=	Vehicle move mouse theme
WORLD_DESC=	World move mouse theme
AFRICA_DESC=	Africa activity theme

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANIMALS}
DISTFILES+=	animals-${PORTVERSION}.zip
PLIST_SUB+=	ANIMALS=""
HAVE_THEME+=	animals
.else
PLIST_SUB+=	ANIMALS="@comment "
.endif

.if ${PORT_OPTIONS:MEARTH}
DISTFILES+=	earth-${PORTVERSION}.zip
PLIST_SUB+=	EARTH=""
HAVE_THEME+=	earth
.else
PLIST_SUB+=	EARTH="@comment "
.endif

.if ${PORT_OPTIONS:MFOOD}
DISTFILES+=	food-${PORTVERSION}.zip
PLIST_SUB+=	FOOD=""
HAVE_THEME+=	food
.else
PLIST_SUB+=	FOOD="@comment "
.endif

.if ${PORT_OPTIONS:MPLANTS}
DISTFILES+=	plants-${PORTVERSION}.zip
PLIST_SUB+=	PLANTS=""
HAVE_THEME+=	plants
.else
PLIST_SUB+=	PLANTS="@comment "
.endif

.if ${PORT_OPTIONS:MSKY}
DISTFILES+=	sky-${PORTVERSION}.zip
PLIST_SUB+=	SKY=""
HAVE_THEME+=	sky
.else
PLIST_SUB+=	SKY="@comment "
.endif

.if ${PORT_OPTIONS:MSPORTS}
DISTFILES+=	sports-${PORTVERSION}.zip
PLIST_SUB+=	SPORTS=""
HAVE_THEME+=	sports
.else
PLIST_SUB+=	SPORTS="@comment "
.endif

.if ${PORT_OPTIONS:MVEHICLE}
DISTFILES+=	vehicle-${PORTVERSION}.zip
PLIST_SUB+=	VEHICLE=""
HAVE_THEME+=	vehicle
.else
PLIST_SUB+=	VEHICLE="@comment "
.endif

.if ${PORT_OPTIONS:MWORLD}
DISTFILES+=	world-${PORTVERSION}.zip
PLIST_SUB+=	WORLD=""
HAVE_THEME+=	world
.else
PLIST_SUB+=	WORLD="@comment "
.endif

.if ${PORT_OPTIONS:MAFRICA}
DISTFILES+=	africa-${PORTVERSION}.zip
PLIST_SUB+=	AFRICA=""
HAVE_THEME+=	africa
.else
PLIST_SUB+=	AFRICA="@comment "
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
.for OPT in ${HAVE_THEME}
	@${UNZIP_CMD} -q ${_DISTDIR}/${OPT}-${PORTVERSION}.zip -d ${WRKSRC}
.endfor

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
