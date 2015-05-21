# Created by: Olexander Melnyk <olexander.v.melnyk@gmail.com>
# $FreeBSD$

PORTNAME=	luadbi
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	olexander.v.melnyk@gmail.com
COMMENT=	LuaDBI driver

LICENSE=	MIT

NO_WRKSUBDIR=	yes

USES=		lua:51 gmake

CFLAGS+=	-fpic -I${LOCALBASE}/include -I${LUA_INCDIR} -I. \
		-I${LOCALBASE}/include/postgresql/server
LDFLAGS+=	-shared -L${LOCALBASE}/lib -L${LUA_LIBDIR}
MAKE_ENV+=	COMMON_LDFLAGS="${LDFLAGS}"

OPTIONS_MULTI=	DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL SQLITE3 PGSQL
OPTIONS_DEFAULT=	MYSQL

PLIST_FILES=	%%LUA_MODSHAREDIR%%/DBI.lua

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
LDFLAGS+=	-L ${LOCALBASE}/lib/mysql
CFLAGS+=	-I ${LOCALBASE}/include/mysql
ALL_TARGET+=	mysql
PLIST_FILES+=	%%LUA_MODLIBDIR%%/dbdmysql.so
.endif

.if ${PORT_OPTIONS:MSQLITE3}
USE_SQLITE=	3
ALL_TARGET+=	sqlite3
PLIST_FILES+=	%%LUA_MODLIBDIR%%/dbdsqlite3.so
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
ALL_TARGET+=	psql
PLIST_FILES+=	%%LUA_MODLIBDIR%%/dbdpostgresql.so
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	${CP} ${WRKSRC}/DBI.lua ${STAGEDIR}${LUA_MODSHAREDIR}
.if ${PORT_OPTIONS:MMYSQL}
	${INSTALL_PROGRAM} ${WRKSRC}/dbdmysql.so ${STAGEDIR}${LUA_MODLIBDIR}
.endif
.if ${PORT_OPTIONS:MSQLITE3}
	${INSTALL_PROGRAM} ${WRKSRC}/dbdsqlite3.so ${STAGEDIR}${LUA_MODLIBDIR}
.endif
.if ${PORT_OPTIONS:MPGSQL}
	${INSTALL_PROGRAM} ${WRKSRC}/dbdpostgresql.so ${STAGEDIR}${LUA_MODLIBDIR}
.endif

.include <bsd.port.mk>
