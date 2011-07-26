# New ports collection makefile for:	redis-scripting
# Date created:				29 Jun 2011
# Whom:					osa
#
# $FreeBSD$
#

PORTNAME=	redis-scripting
PORTVERSION=	2.2.111
CATEGORIES=	databases
MASTER_SITES=	http://redis.googlecode.com/files/
DISTNAME=	${PORTNAME:C/\-.*$//}-${PORTVERSION}-${PORTNAME:C/^.*\-//}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	A persistent key-value database with net interface and scripting

CONFLICTS?=	redis-2.*

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

CFLAGS+=	-I${LOCALBASE}/include

USE_GMAKE=	yes
USE_LUA=	5.1+
USE_RC_SUBR=	redis.sh
BIN_FILES=	redis-benchmark redis-check-aof redis-check-dump \
		redis-cli redis-server

PKGMESSAGE=	${WRKDIR}/pkg-message

USERS=	redis
GROUPS=	redis

REDIS_DBDIR?=	/var/db/redis
REDIS_RUNDIR?=	/var/run/redis
REDIS_LOGDIR?=	/var/log/redis

SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME} \
	REDIS_USER=${USERS} \
	REDIS_RUNDIR=${REDIS_RUNDIR}

PLIST_SUB+=	REDIS_USER=${USERS} \
	REDIS_GROUP=${GROUPS} \
	REDIS_LOGDIR=${REDIS_LOGDIR} \
	REDIS_DBDIR=${REDIS_DBDIR} \
	REDIS_RUNDIR=${REDIS_RUNDIR}

post-build:
	${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/redis.conf > ${WRKDIR}/redis.conf

do-install:
	${INSTALL_PROGRAM} ${BIN_FILES:C!^!${WRKSRC}/src/!} ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/redis.conf ${PREFIX}/etc/redis.conf.sample

post-install:
.for d in ${REDIS_LOGDIR} ${REDIS_RUNDIR} ${REDIS_DBDIR}
	[ -d ${d} ] || ${MKDIR} ${d} && ${CHOWN} ${USERS}:${GROUPS} ${d}
.endfor

.include <bsd.port.mk>
