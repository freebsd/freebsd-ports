# New ports collection makefile for:	openarena-data
# Date created:				15 June 2010
# Whom:					Dominic Fandrey
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	0.8.5
CATEGORIES=	games
MASTER_SITES=	http://openarena.ws/request.php?2\\\#/:data \
		http://openarena.ws/request.php?3\\\#/:patch
DISTFILES=	${OA_DATA}:data \
		${OA_PATCH}:patch
EXTRACT_ONLY=

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	OpenArena game data files

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/baseoa
NO_BUILD=	yes
FETCH_ARGS=
USE_ZIP=	yes

OA_DATA=	oa081.zip
OA_DATA_VER=	0.8.1
OA_PATCH=	oa085p.zip
OA_PATCH_VER=	0.8.1

post-extract:
	${UNZIP_CMD} -j ${DISTDIR}/${OA_DATA} ${PKGNAMEPREFIX}${OA_DATA_VER}/${OABASE}/\* -d ${WRKSRC}
	${UNZIP_CMD} -j ${DISTDIR}/${OA_PATCH} ${PKGNAMEPREFIX}${OA_PATCH_VER}/${OABASE}/\* -d ${WRKSRC}

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR})

.include "../openarena/Makefile.include"
