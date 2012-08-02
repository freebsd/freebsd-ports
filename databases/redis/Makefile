# New ports collection makefile for:	redis
# Date created:	   03 Jul 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	redis
PORTVERSION=	2.4.16
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	osa@FreeBSD.org
COMMENT=	A persistent key-value database with built-in net interface

LICENSE=	BSD

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lm -lexecinfo

CONFLICTS?=	redis-devel-2.6.*

USE_GMAKE=	yes
MAKE_ENV=	"V=yo"
USE_RC_SUBR=	redis
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
	REDIS_DBDIR=${REDIS_DBDIR} \
	REDIS_LOGDIR=${REDIS_LOGDIR} \
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
