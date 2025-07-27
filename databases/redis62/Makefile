PORTNAME=	redis
DISTVERSION=	6.2.19
CATEGORIES=	databases
MASTER_SITES=	https://download.redis.io/releases/
PKGNAMESUFFIX=	62

MAINTAINER=	bofh@freebsd.org
COMMENT=	Persistent key-value database with built-in net interface
WWW=		https://redis.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES+=		compiler:c11 cpe gmake tcl:test
CPE_VENDOR=	redislabs
CPE_PRODUCT=	redis
USE_RC_SUBR=	redis sentinel

MAKE_ENV=	OPTIMIZATION= \
		V=yo

LDFLAGS+=	-lpthread -lm -lexecinfo

CONFLICTS_INSTALL=	redis redis-devel redis72 redis74

PORTSCOUT=	limit:^6\.2
SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME} \
		REDIS_DBDIR=${REDIS_DBDIR} \
		REDIS_LOGDIR=${REDIS_LOGDIR} \
		REDIS_RUNDIR=${REDIS_RUNDIR} \
		REDIS_USER=${USERS}

USERS=		redis
GROUPS=		redis

PLIST_SUB+=	REDIS_DBDIR=${REDIS_DBDIR} \
		REDIS_GROUP=${GROUPS} \
		REDIS_LOGDIR=${REDIS_LOGDIR} \
		REDIS_RUNDIR=${REDIS_RUNDIR} \
		REDIS_USER=${USERS}

OPTIONS_DEFINE=		JEMALLOC TLS
OPTIONS_DEFAULT=	TLS
OPTIONS_SUB=		yes

JEMALLOC_DESC=	Use jemalloc
TLS_DESC=	Use TLS (openssl req.)

JEMALLOC_MAKE_ENV=	USE_JEMALLOC=yes
TLS_USES=		ssl
TLS_MAKE_ENV=		BUILD_TLS=yes

BIN_FILES=	redis-benchmark redis-check-aof redis-check-rdb redis-cli \
		redis-sentinel redis-server

REDIS_DBDIR?=	/var/db/redis
REDIS_RUNDIR?=	/var/run/redis
REDIS_LOGDIR?=	/var/log/redis

post-patch-JEMALLOC-on:
	@${REINPLACE_CMD} '58s!Linux!FreeBSD!g' ${WRKSRC}/src/Makefile

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
