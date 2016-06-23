# Created by: olevole@olevole.ru
# $FreeBSD$

PORTNAME=	tile38
PORTVERSION=	1.2.0
CATEGORIES=	databases

MAINTAINER=	olevole@olevole.ru
COMMENT=	In-memory geolocation data store, spatial index, and realtime geofence

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.4:lang/go \
		bash:shells/bash
RUN_DEPENDS=	go>=1.4:lang/go \
		bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	tidwall

USES=		shebangfix
SHEBANG_FILES=	build.sh

USE_RC_SUBR=	tile38

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

TILE38_DBDIR?=	/var/db/tile38
TILE38_RUNDIR?=	/var/run/tile38

SUB_LIST=	PORTNAME=${PORTNAME} \
		TILE38_USER=${USERS} \
		TILE38_DBDIR=${TILE38_DBDIR} \
		TILE38_RUNDIR=${TILE38_RUNDIR}

PLIST_SUB=	TILE38_USER=${USERS} \
		TILE38_GROUP=${GROUPS} \
		TILE38_DBDIR=${TILE38_DBDIR} \
		TILE38_RUNDIR=${TILE38_RUNDIR}

do-build:
	@cd ${WRKSRC} && ./build.sh

do-install:
	@${MKDIR} ${STAGEDIR}${TILE38_DBDIR} ${STAGEDIR}${TILE38_RUNDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/tile38-cli ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tile38-server ${STAGEDIR}${PREFIX}/bin/

do-test:
	@cd ${WRKSRC} && ./build.sh test

.include <bsd.port.mk>
