PORTNAME=	valkey
DISTVERSION=	g20240402
CATEGORIES=	databases

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	High-performance data structure server that primarily serves key/value workloads
WWW=		https://valkey.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES+=		gmake tcl:test
USE_GITHUB=	yes
GH_ACCOUNT=	valkey-io
GH_TAGNAME=	0ba2f1b14
USE_RC_SUBR=	valkey valkeysentinel

MAKE_ENV=	OPTIMIZATION= \
		V=1

LDFLAGS+=	-lpthread -lm -lexecinfo

PORTSCOUT=	ignore:1
SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME} \
		VALKEY_DBDIR=${VALKEY_DBDIR} \
		VALKEY_LOGDIR=${VALKEY_LOGDIR} \
		VALKEY_RUNDIR=${VALKEY_RUNDIR} \
		VALKEY_USER=${USERS}

USERS=		valkey
GROUPS=		valkey

PLIST_SUB+=	VALKEY_DBDIR=${VALKEY_DBDIR} \
		VALKEY_GROUP=${GROUPS} \
		VALKEY_LOGDIR=${VALKEY_LOGDIR} \
		VALKEY_RUNDIR=${VALKEY_RUNDIR} \
		VALKEY_USER=${USERS}

OPTIONS_DEFINE=		JEMALLOC TLS
OPTIONS_DEFAULT=	TLS
OPTIONS_SUB=		yes

JEMALLOC_DESC=	Use jemalloc
TLS_DESC=	Use TLS

JEMALLOC_MAKE_ENV=	MALLOC=jemalloc
TLS_USES=		ssl
TLS_MAKE_ENV=		BUILD_TLS=yes

BIN_FILES=	valkey-benchmark valkey-check-aof valkey-check-rdb valkey-cli \
		valkey-sentinel valkey-server

VALKEY_DBDIR?=	/var/db/valkey
VALKEY_RUNDIR?=	/var/run/valkey
VALKEY_LOGDIR?=	/var/log/valkey

post-build:
	${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/redis.conf > ${WRKDIR}/valkey.conf
	${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/sentinel.conf > ${WRKDIR}/valkey-sentinel.conf

do-install:
	${INSTALL_PROGRAM} ${BIN_FILES:C!^!${WRKSRC}/src/!} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/valkey.conf ${STAGEDIR}${PREFIX}/etc/valkey.conf.sample
	${INSTALL_DATA} ${WRKDIR}/valkey-sentinel.conf ${STAGEDIR}${PREFIX}/etc/valkey-sentinel.conf.sample
	${MKDIR} ${STAGEDIR}${VALKEY_LOGDIR} \
		${STAGEDIR}${VALKEY_DBDIR} \
		${STAGEDIR}${VALKEY_RUNDIR}

do-test:
	@cd ${WRKSRC} && ${TCLSH} tests/test_helper.tcl

.include <bsd.port.mk>
