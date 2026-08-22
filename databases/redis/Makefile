PORTNAME=	redis
DISTVERSION=	8.10.1
CATEGORIES=	databases
MASTER_SITES=	https://download.redis.io/releases/

MAINTAINER=	bofh@freebsd.org
COMMENT=	Persistent key-value database with built-in net interface
WWW=		https://redis.io/

LICENSE=	AGPLv3 RSALv2 SSPLv1
LICENSE_COMB=	dual
LICENSE_NAME_RSALv2=	Redis Source Available License v2
LICENSE_NAME_SSPLv1=	Server Side Public License v1
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS_RSALv2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		compiler:c11 cpe gmake localbase:ldflags pkgconfig tcl:test
CPE_VENDOR=	redis
USE_RC_SUBR=	redis sentinel

MAKE_ENV=	OPTIMIZATION= \
		V=yo

#PIE_UNSAFE=	ld: error: relocation R_X86_64_32 cannot be used against local \
#		symbol; recompile with -fPIC

CONFLICTS_INSTALL=	redis-devel redis[0-9]*

BINARY_ALIAS=	gmd5sum=md5sum
PORTSCOUT=	limit:^[0-9\.]*$$
SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} \
		REDIS_DBDIR=${REDIS_DBDIR} \
		REDIS_GROUP=${GROUPS} \
		REDIS_LOGDIR=${REDIS_LOGDIR} \
		REDIS_RUNDIR=${REDIS_RUNDIR} \
		REDIS_USER=${USERS}

USERS=		redis
GROUPS=		redis

PLIST_SUB=	REDIS_DBDIR=${REDIS_DBDIR} \
		REDIS_GROUP=${GROUPS} \
		REDIS_LOGDIR=${REDIS_LOGDIR} \
		REDIS_RUNDIR=${REDIS_RUNDIR} \
		REDIS_USER=${USERS}

OPTIONS_DEFINE=		JEMALLOC TLS
OPTIONS_DEFAULT=	TLS
OPTIONS_GROUP=		MODULES
OPTIONS_GROUP_MODULES=		REDISBLOOM REDISJSON REDISEARCH
OPTIONS_SUB=		yes

JEMALLOC_DESC=	Use jemalloc
REDISBLOOM_DESC=	RedisBLOOM module
REDISJSON_DESC=		RedisJSON module
REDISEARCH_DESC=	Redisearch module
TLS_DESC=	Use TLS (openssl req.)

JEMALLOC_MAKE_ENV=	USE_JEMALLOC=yes
REDISBLOOM_RUN_DEPENDS=		${LOCALBASE}/lib/redisbloom.so>=0:databases/redisbloom
REDISJSON_RUN_DEPENDS=		${LOCALBASE}/lib/librejson.so>=0:databases/redisjson
REDISEARCH_RUN_DEPENDS=		${LOCALBASE}/lib/redisearch.so>=0:textproc/redisearch
TLS_USES=		ssl
TLS_MAKE_ENV=		BUILD_TLS=yes

BIN_FILES=	redis-benchmark redis-check-aof redis-check-rdb redis-cli \
		redis-sentinel redis-server

REDIS_DBDIR?=	/var/db/redis
REDIS_RUNDIR?=	/var/run/redis
REDIS_LOGDIR?=	/var/log/redis

post-patch:
	${REINPLACE_CMD} -e 's|^cloned=.*|cloned=""|g' \
		${WRKSRC}/scripts/build.sh

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
