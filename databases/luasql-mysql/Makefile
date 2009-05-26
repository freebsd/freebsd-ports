# New ports collection makefile for:   luasql
# Date created:        25 May 2009
# Whom:                Martin Matuska <martin@matuska.org>
#
# $FreeBSD$
#

PORTNAME=	luasql
PORTVERSION=	2.1.1
CATEGORIES=	databases
MASTER_SITES=	http://luaforge.net/frs/download.php/${DISTFILE_REV}/
PKGNAMESUFFIX=	-${LUASQL_DRIVER}

MAINTAINER=	mm@FreeBSD.org
COMMENT?=	LuaSQL driver

DISTFILE_REV=	2686

USE_LUA=	5.1
USE_GMAKE=	yes
ALL_TARGET=	lib

LUASQL_DRIVER?=	mysql

MAKE_ENV+=	LUA_DIR=${LUA_SUBDIR} \
		LUA_INC=${LUA_INCDIR} \
		LUA_LIBDIR=${LUA_LIBDIR} \
		LDFLAGS="-shared" \
		LUA_VERSION_NUM="${LUA_VER_STR}0" \
		T=${LUASQL_DRIVER}

CFLAGS+=	-fPIC

PLIST_SUB+=	LUA_MIDLIBDIR=${LUA_MODLIBDIR}

.if ${LUASQL_DRIVER} == "mysql"
COMMENT=	Lua interface to MySQL
USE_MYSQL=	yes
MAKE_ENV+=	DRIVER_LIBS="-L ${LOCALBASE}/lib/mysql -lmysqlclient" \
		DRIVER_INCS="-I ${LOCALBASE}/include/mysql"
.elif ${LUASQL_DRIVER} == "postgres"
COMMENT=	Lua interface to PostgreSQL
USE_PGSQL=	yes
MAKE_ENV+=	DRIVER_LIBS="-L ${LOCALBASE}/lib -lpq" \
		DRIVER_INCS="-I ${LOCALBASE}/include"
.elif ${LUASQL_DRIVER} == "sqlite3"
COMMENT=	Lua interface to SQLite3
USE_SQLITE=	3
MAKE_ENV+=	DRIVER_LIBS="-L ${LOCALBASE}/lib -lsqlite3" \
		DRIVER_INCS="-I ${LOCALBASE}/include"
.else
IGNORE=		unknown or unsupported luasql driver
.endif

LATEST_LINK=	${PORTNAME}-${LUASQL_DRIVER}
PLIST_SUB+=	LUASQL_DRIVER=${LUASQL_DRIVER}

do-install:
	@${MKDIR} ${LUA_MODLIBDIR}/luasql
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${LUASQL_DRIVER}.so ${LUA_MODLIBDIR}/luasql

.include <bsd.port.mk>
