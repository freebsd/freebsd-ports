# Created by: Michael Alyn Miller <malyn@strangeGizmo.com>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	1.0
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://files3.bungie.org/trilogy/
PKGNAMEPREFIX=	alephone-
DISTFILES=	# empty by default
DIST_SUBDIR=	alephone

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Released Marathon data files for the Aleph One port

RUN_DEPENDS=	alephone:games/alephone

NO_ARCH=	yes
NO_BUILD=	yes

NO_CDROM=	Bungie/Microsoft do not allow charging for Marathon data files
NO_WRKSUBDIR=	yes

USES=		zip

SUB_FILES=	wrapper

DATADIR=	${PREFIX}/share/AlephOne

OPTIONS_MULTI=	AO
OPTIONS_MULTI_AO=	MARATHON DURANDAL INFINITY
OPTIONS_DEFAULT=	MARATHON DURANDAL INFINITY
OPTIONS_SUB=	yes

AO_DESC=		Data package selection

MARATHON_DESC=		Install Marathon data
MARATHON_DISTFILES=	M1A1${EXTRACT_SUFX}
MARATHON_DESKTOP_ENTRIES= \
			"Marathon" \
			"" \
			"" \
			"alephone-marathon" \
			"Game;ActionGame;" \
			false

DURANDAL_DESC=		Install Marathon 2: Durandal data
DURANDAL_DISTFILES=	Marathon2${EXTRACT_SUFX}
DURANDAL_DESKTOP_ENTRIES= \
			"Marathon 2: Durandal" \
			"" \
			"" \
			"alephone-durandal" \
			"Game;ActionGame;" \
			false

INFINITY_DESC=		Install Marathon Infinity data
INFINITY_DISTFILES=	MarathonInfinity${EXTRACT_SUFX}
INFINITY_DESKTOP_ENTRIES= \
			"Marathon Infinity" \
			"" \
			"" \
			"alephone-infinity" \
			"Game;ActionGame;" \
			false

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}

do-install-MARATHON-on:
	@cd ${WRKSRC}/M1A1 && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/marathon
	@${SED} -e 's|%%GAMEDIR%%|marathon|' ${WRKDIR}/wrapper > ${STAGEDIR}${PREFIX}/bin/alephone-marathon

do-install-DURANDAL-on:
	@cd "${WRKSRC}/Marathon 2" && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/durandal
	@${SED} -e 's|%%GAMEDIR%%|durandal|' ${WRKDIR}/wrapper > ${STAGEDIR}${PREFIX}/bin/alephone-durandal

do-install-INFINITY-on:
	@cd "${WRKSRC}/Marathon Infinity" && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/infinity
	@${SED} -e 's|%%GAMEDIR%%|infinity|' ${WRKDIR}/wrapper > ${STAGEDIR}${PREFIX}/bin/alephone-infinity

post-install:
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
