# Created by: Sergey Skvortsov <skv@protey.ru>

PORTNAME=	redis
DISTVERSION=	7.0.4
CATEGORIES=	databases
MASTER_SITES=	https://download.redis.io/releases/

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Persistent key-value database with built-in net interface

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES+=		compiler:c11 cpe gmake
CPE_VENDOR=	redislabs

MAKE_ENV=	OPTIMIZATION= \
		V=yo
CONFLICTS_INSTALL=	redis-devel redis6 # etc/rc.d/redis

OPTIONS_DEFINE=		JEMALLOC TESTS TLS TRIB
OPTIONS_RADIO=		EXTLUA
OPTIONS_RADIO_EXTLUA=	LUA LUAJIT LUAJITOR
OPTIONS_SUB=		yes
OPTIONS_DEFAULT+=	TLS

JEMALLOC_DESC=	Use jemalloc
LUAJITOR_DESC=	Use lang/luajit-openresty instead of builtin lua
LUAJIT_DESC=	Use lang/luajit instead of builtin lua
LUA_DESC=	Use lang/lua instead of builtin lua
TESTS_DESC=	Install lang/tcl for redis unit tests
TLS_DESC=	Use TLS (openssl req.)
TRIB_DESC=	Install redis-trib.rb (lang/ruby req.)

JEMALLOC_MAKE_ENV=	USE_JEMALLOC=yes
LUAJITOR_BROKEN=	Fails to link
LUAJITOR_BUILD_DEPENDS=	${LOCALBASE}/include/luajit-2.1/lua.h:lang/luajit-openresty
LUAJITOR_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit-openresty
LUAJITOR_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src-Makefile.luajit-or \
			${PATCHDIR}/extra-patch-src-function_lua.c \
			${PATCHDIR}/extra-patch-deps_lua_src_lua__cjson.c
LUAJITOR_VARS=		_ADDFLAGS=true
LUAJIT_BROKEN=		Fails to link
LUAJIT_BUILD_DEPENDS=	${LOCALBASE}/include/luajit-2.0/lua.h:lang/luajit
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src-Makefile.luajit
LUAJIT_VARS=		_ADDFLAGS=true
LUA_BROKEN=		Fails to link
LUA_USES=		lua:51
LUA_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src-Makefile.lua
LUA_VARS=		_ADDFLAGS=true
TESTS_USES=		tcl:build
TLS_USES=		ssl
TLS_MAKE_ENV=		BUILD_TLS=yes
TRIB_CATEGORIES=	ruby
TRIB_RUN_DEPENDS=	rubygem-redis>=2.2:databases/rubygem-redis
TRIB_USE=		RUBY=yes

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 && !${CFLAGS:M-march=*}
# Needed for __atomic_fetch_add_8
USE_GCC=	yes
CFLAGS+=	-march=i586
.endif

.if defined(_ADDFLAGS)
CFLAGS+=	-fPIC
LDFLAGS+=	-Wl,-E
.endif

LDFLAGS+=	-lpthread -lm -lexecinfo

CONFLICTS?=	redis-devel-* redis6-* redis62-*

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
	@${REINPLACE_CMD} '35s!Linux!FreeBSD!g' ${WRKSRC}/src/Makefile

post-patch-LUA-on:
	@cd ${WRKSRC}/deps/lua/src && ${CP} fpconv.* lua_* strbuf.* ${WRKSRC}/src/
post-patch-LUAJIT-on: post-patch-LUA-on
post-patch-LUAJITOR-on: post-patch-LUA-on

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

do-install-TRIB-on:
	${INSTALL_SCRIPT} ${WRKSRC}/src/redis-trib.rb ${STAGEDIR}${PREFIX}/bin/

do-test:
	@cd ${WRKSRC} && ${TCLSH} tests/test_helper.tcl

.include <bsd.port.post.mk>
