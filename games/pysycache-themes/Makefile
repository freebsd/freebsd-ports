# New ports collection makefile for:	pysycache-themes
# Date created:		2006-02-22
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	themes
PORTVERSION=	2.0
CATEGORIES=	games python
MASTER_SITES=	http://themes.pysycache.free.fr/
PKGNAMEPREFIX=	pysycache-
DISTFILES=	#
DIST_SUBDIR=	pysycache

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	The pysycache themes support

RUN_DEPENDS=	pysycache.py:${PORTSDIR}/games/pysycache

USE_ZIP=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
WRKSRC=	${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}
DATADIR=	${PREFIX}/share/${DIST_SUBDIR}

OPTIONS=	ANIMALS_MOVE	"Animals move mouse theme"	off \
		EARTH_MOVE	"Earth move mouse theme"	off \
		FOOD_MOVE	"Food move mouse theme"	off \
		PLANTS_MOVE	"Plants move mouse theme"	off \
		SKY_MOVE	"Sky move mouse theme"	off \
		SPORTS_MOVE	"Sports move mouse theme"	off \
		VEHICLE_MOVE	"Vehicle move mouse theme"	off \
		WORLD_MOVE	"World move mouse theme"	off \
		AFRICA_ACTIVITY	"Africa activity theme"	off

.include <bsd.port.pre.mk>

.if defined(WITH_ANIMALS_MOVE)
DISTFILES+=	animals-${PORTVERSION}.zip
PLIST_SUB+=	ANIMALS=""
FLAG_THEME=	true
HAVE_THEME+=	animals
.else
PLIST_SUB+=	ANIMALS="@comment "
.endif

.if defined(WITH_EARTH_MOVE)
DISTFILES+=	earth-${PORTVERSION}.zip
PLIST_SUB+=	EARTH=""
FLAG_THEME=	true
HAVE_THEME+=	earth
.else
PLIST_SUB+=	EARTH="@comment "
.endif

.if defined(WITH_FOOD_MOVE)
DISTFILES+=	food-${PORTVERSION}.zip
PLIST_SUB+=	FOOD=""
FLAG_THEME=	true
HAVE_THEME+=	food
.else
PLIST_SUB+=	FOOD="@comment "
.endif

.if defined(WITH_PLANTS_MOVE)
DISTFILES+=	plants-${PORTVERSION}.zip
PLIST_SUB+=	PLANTS=""
FLAG_THEME=	true
HAVE_THEME+=	plants
.else
PLIST_SUB+=	PLANTS="@comment "
.endif

.if defined(WITH_SKY_MOVE)
DISTFILES+=	sky-${PORTVERSION}.zip
PLIST_SUB+=	SKY=""
FLAG_THEME=	true
HAVE_THEME+=	sky
.else
PLIST_SUB+=	SKY="@comment "
.endif

.if defined(WITH_SPORTS_MOVE)
DISTFILES+=	sports-${PORTVERSION}.zip
PLIST_SUB+=	SPORTS=""
FLAG_THEME=	true
HAVE_THEME+=	sports
.else
PLIST_SUB+=	SPORTS="@comment "
.endif

.if defined(WITH_VEHICLE_MOVE)
DISTFILES+=	vehicle-${PORTVERSION}.zip
PLIST_SUB+=	VEHICLE=""
FLAG_THEME=	true
HAVE_THEME+=	vehicle
.else
PLIST_SUB+=	VEHICLE="@comment "
.endif

.if defined(WITH_WORLD_MOVE)
DISTFILES+=	world-${PORTVERSION}.zip
PLIST_SUB+=	WORLD=""
FLAG_THEME=	true
HAVE_THEME+=	world
.else
PLIST_SUB+=	WORLD="@comment "
.endif

.if defined(WITH_AFRICA_ACTIVITY)
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

.include <bsd.port.post.mk>
