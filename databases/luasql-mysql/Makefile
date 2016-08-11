# Created by: Martin Matuska <martin@matuska.org>
# $FreeBSD$

PORTNAME=	luasql
PORTVERSION=	2.3.3
DISTVERSIONPREFIX=	v
PORTREVISION?=	0
CATEGORIES=	databases
PKGNAMESUFFIX=	-${LUASQL_DRIVER}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	LuaSQL driver

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	keplerproject

USES=		lua gmake dos2unix
DOS2UNIX_FILES=	src/*.c
ALL_TARGET=	${LUASQL_DRIVER}

LUASQL_DRIVER?=	mysql

MAKE_ARGS=	LUA_DIR=${LUA_SUBDIR} \
		LUA_INC=${LUA_INCDIR} \
		LUA_LIBDIR=${LUA_LIBDIR} \
		LUA_VERSION_NUM="${LUA_VER_STR}0" \
		T=${LUASQL_DRIVER} \
		WARN="${CFLAGS}" \
		CC="${CC}"

CFLAGS+=	-Wno-return-type

PLIST_SUB=	LUA_MIDLIBDIR=${LUA_MODLIBDIR} \
		LUASQL_DRIVER=${LUASQL_DRIVER}

.if ${LUASQL_DRIVER} == "mysql"
COMMENT=	Lua interface to MySQL
USES+=		mysql
MAKE_ARGS+=	DRIVER_LIBS_mysql="-L ${LOCALBASE}/lib/mysql -lmysqlclient" \
		DRIVER_INCS_mysql="-I ${LOCALBASE}/include/mysql"
.elif ${LUASQL_DRIVER} == "postgres"
COMMENT=	Lua interface to PostgreSQL
USES+=		pgsql
MAKE_ARGS+=	DRIVER_LIBS_postgres="-L ${LOCALBASE}/lib -lpq" \
		DRIVER_INCS_postgres="-I ${LOCALBASE}/include"
.elif ${LUASQL_DRIVER} == "sqlite3"
COMMENT=	Lua interface to SQLite3
USES+=		sqlite
MAKE_ARGS+=	DRIVER_LIBS_sqlite3="-L ${LOCALBASE}/lib -lsqlite3" \
		DRIVER_INCS_sqlite3="-I ${LOCALBASE}/include"
.elif ${LUASQL_DRIVER} == "odbc"
COMMENT=	Lua interface to ODBC
LIB_DEPENDS+=	libodbc.so:databases/unixODBC
MAKE_ARGS+=	DRIVER_LIBS_odbc="-L ${LOCALBASE}/lib -lodbc" \
		DRIVER_INCS_odbc="-I ${LOCALBASE}/include -DUNIXODBC"
.elif ${LUASQL_DRIVER} == "firebird"
COMMENT=	Lua interface to Firebird
USES+=		firebird
MAKE_ARGS+=	DRIVER_LIBS_firebird="-L ${LOCALBASE}/lib -lfbclient" \
		DRIVER_INCS_firebird="-I ${LOCALBASE}/include"
.else
IGNORE=		unknown or unsupported luasql driver
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}/luasql
	${INSTALL_LIB} ${WRKSRC}/src/${LUASQL_DRIVER}.so ${STAGEDIR}${LUA_MODLIBDIR}/luasql

.include <bsd.port.mk>
