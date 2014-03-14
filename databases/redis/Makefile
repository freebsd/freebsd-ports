# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	redis
DISTVERSION=	2.8.7
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://download.redis.io/releases/

MAINTAINER=	osa@FreeBSD.org
COMMENT=	A persistent key-value database with built-in net interface

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

OPTIONS_DEFINE=	TESTS
OPTIONS_RADIO=	EXTLUA
OPTIONS_RADIO_EXTLUA=	LUA LUAJIT
LUA_DESC=	Use lang/lua instead of builtin lua
LUAJIT_DESC=	Use lang/luajit instead of builtin lua
TESTS_DESC=	Install lang/tcl for redis unit tests

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLUA}
USE_LUA?=	5.1
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src-Makefile.lua
CFLAGS+=	-fPIC
LDFLAGS+=	-Wl,-E
.endif

.if ${PORT_OPTIONS:MLUAJIT}
LIB_DEPENDS+=	libluajit-5.1.so:${PORTSDIR}/lang/luajit
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src-Makefile.luajit
CFLAGS+=	-fPIC
LDFLAGS+=	-Wl,-E
.endif

.if ${PORT_OPTIONS:MTESTS}
USES+=		tcl:build
.endif

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lm -lexecinfo

CONFLICTS?=	redis-devel-2.*

USES+=		gmake
MAKE_ENV=	"V=yo"
USE_RC_SUBR=	redis
BIN_FILES=	redis-benchmark redis-check-aof redis-check-dump \
		redis-cli redis-sentinel redis-server

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

.if ${PORT_OPTIONS:MLUAJIT} || ${PORT_OPTIONS:MLUA}
post-patch:
	@cd ${WRKSRC}/deps/lua/src && ${CP} lua_* strbuf.* ${WRKSRC}/src/
.endif

post-build:
	${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/redis.conf > ${WRKDIR}/redis.conf

do-install:
	${INSTALL_PROGRAM} ${BIN_FILES:C!^!${WRKSRC}/src/!} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/redis.conf ${STAGEDIR}${PREFIX}/etc/redis.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sentinel.conf ${STAGEDIR}${PREFIX}/etc/sentinel.conf.sample

regression-test: build
	@cd ${WRKSRC} && ${TCLSH} tests/test_helper.tcl

.include <bsd.port.mk>
