PORTNAME=	maps
DISTVERSION=	1.0.0
CATEGORIES=	games
MASTER_SITES=	https://maps.quakeworld.nu/all/
.include "${.CURDIR}/Makefile.maps"
PKGNAMEPREFIX=	${Q1PKGNAMEPREFIX}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Popular maps for different modes of Quake 1 and QuakeWorld
WWW=		https://maps.quakeworld.nu/

LICENSE=	GPLv2

DATADIR=	${Q1DIR}/id1/maps
NO_ARCH=	yes
NO_BUILD=	yes
PLIST_SUB=	Q1MAPSDIR="${DATADIR:N${LOCALBASE}}"

.include "${.CURDIR}/../quake-data/Makefile.include"

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${COPYTREE_SHARE} '*.bsp' \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
