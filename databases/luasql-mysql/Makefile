# Created by: Martin Matuska <martin@matuska.org>
# $FreeBSD$

PORTNAME=	luasql
PORTVERSION=	2.3.0
CATEGORIES=	databases
PKGNAMESUFFIX=	-${LUASQL_DRIVER}

MAINTAINER=	lua@FreeBSD.org
COMMENT?=	LuaSQL driver

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	keplerproject
GH_COMMIT=	c527024
GH_TAGNAME=	v${PORTVERSION}

USES=		lua gmake
ALL_TARGET=	lib

LUASQL_DRIVER?=	mysql

MAKE_ARGS+=	LUA_DIR=${LUA_SUBDIR} \
		LUA_INC=${LUA_INCDIR} \
		LUA_LIBDIR=${LUA_LIBDIR} \
		LUA_VERSION_NUM="${LUA_VER_STR}0" \
		T=${LUASQL_DRIVER} \
		WARN="${CFLAGS}" \
		CC="${CC}"

USE_CSTD=	gnu89
CFLAGS+=	-Wno-return-type

PLIST_SUB+=	LUA_MIDLIBDIR=${LUA_MODLIBDIR}

.if ${LUASQL_DRIVER} == "mysql"
COMMENT=	Lua interface to MySQL
USE_MYSQL=	yes
MAKE_ARGS+=	DRIVER_LIBS="-L ${LOCALBASE}/lib/mysql -lmysqlclient" \
		DRIVER_INCS="-I ${LOCALBASE}/include/mysql"
.elif ${LUASQL_DRIVER} == "postgres"
COMMENT=	Lua interface to PostgreSQL
USE_PGSQL=	yes
MAKE_ARGS+=	DRIVER_LIBS="-L ${LOCALBASE}/lib -lpq" \
		DRIVER_INCS="-I ${LOCALBASE}/include"
.elif ${LUASQL_DRIVER} == "sqlite3"
COMMENT=	Lua interface to SQLite3
USE_SQLITE=	3
MAKE_ARGS+=	DRIVER_LIBS="-L ${LOCALBASE}/lib -lsqlite3" \
		DRIVER_INCS="-I ${LOCALBASE}/include"
.else
IGNORE=		unknown or unsupported luasql driver
.endif

LATEST_LINK=	${PORTNAME}-${LUASQL_DRIVER}
PLIST_SUB+=	LUASQL_DRIVER=${LUASQL_DRIVER}

NO_STAGE=	yes
do-install:
	@${MKDIR} ${LUA_MODLIBDIR}/luasql
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${LUASQL_DRIVER}.so ${LUA_MODLIBDIR}/luasql

.include <bsd.port.mk>
