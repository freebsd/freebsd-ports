PORTNAME=	redis
DISTVERSION=	7.0.15
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	https://download.redis.io/releases/
PKGNAMESUFFIX=	70

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Persistent key-value database with built-in net interface
WWW=		https://redis.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES+=		compiler:c11 cpe gmake tcl:test
CPE_VENDOR=	redislabs

MAKE_ENV=	OPTIMIZATION= \
		V=yo

CONFLICTS_INSTALL=	redis redis-devel redis62 redis72 # etc/rc.d/redis

PORTSCOUT=	limit:^7\.0

OPTIONS_DEFINE=		JEMALLOC TLS
OPTIONS_DEFAULT=	TLS
OPTIONS_SUB=		yes

JEMALLOC_DESC=	Use jemalloc
TLS_DESC=	Use TLS (openssl req.)

JEMALLOC_MAKE_ENV=	USE_JEMALLOC=yes
TLS_USES=		ssl
TLS_MAKE_ENV=		BUILD_TLS=yes

LDFLAGS+=	-lpthread -lm -lexecinfo

USE_RC_SUBR=	redis sentinel
BIN_FILES=	redis-benchmark redis-check-aof redis-check-rdb redis-cli \
		redis-sentinel redis-server

USERS=		redis
GROUPS=		redis

REDIS_DBDIR?=	/var/db/redis
REDIS_RUNDIR?=	/var/run/redis
REDIS_LOGDIR?=	/var/log/redis

SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME} \
		REDIS_DBDIR=${REDIS_DBDIR} \
		REDIS_LOGDIR=${REDIS_LOGDIR} \
		REDIS_RUNDIR=${REDIS_RUNDIR} \
		REDIS_USER=${USERS}

PLIST_SUB+=	REDIS_DBDIR=${REDIS_DBDIR} \
		REDIS_GROUP=${GROUPS} \
		REDIS_LOGDIR=${REDIS_LOGDIR} \
		REDIS_RUNDIR=${REDIS_RUNDIR} \
		REDIS_USER=${USERS}

post-patch-JEMALLOC-on:
	@${REINPLACE_CMD} '62s!Linux!FreeBSD!g' ${WRKSRC}/src/Makefile

post-build:
	${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/redis.conf > ${WRKDIR}/redis.conf

do-install:
	${INSTALL_PROGRAM} ${BIN_FILES:C!^!${WRKSRC}/src/!} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/redis.conf ${STAGEDIR}${PREFIX}/etc/redis.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sentinel.conf ${STAGEDIR}${PREFIX}/etc/sentinel.conf.sample
	${MKDIR} ${STAGEDIR}${REDIS_LOGDIR} \
		${STAGEDIR}${REDIS_DBDIR} \
		${STAGEDIR}${REDIS_RUNDIR}

do-test:
	@cd ${WRKSRC} && ${TCLSH} tests/test_helper.tcl

.include <bsd.port.mk>
