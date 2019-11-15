# Created by: tremere@cainites.net
# $FreeBSD$

PORTNAME=	opendbx
PORTVERSION=	1.4.6
PORTREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	http://www.linuxnetworks.de/opendbx/download/

MAINTAINER=	tremere@cainites.net
COMMENT=	C library for accessing databases with a single API

LICENSE=	LGPL21

USES=		gmake libtool pathfix readline

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${WRKSRC}/lib -L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-backends="${CONFIGURE_MODULES}"

USE_LDCONFIG=	${PREFIX}/lib/opendbx

OPTIONS_DEFINE=	NLS
OPTIONS_MULTI=	DRIVER
OPTIONS_MULTI_DRIVER=	MYSQL PGSQL SQLITE SQLITE3 MSSQL SYBASE
OPTIONS_DEFAULT=	MYSQL
SQLITE_DESC=	SQLite 2 database support
SYBASE_DESC=	Sybase database support
DRIVER_DESC=	Database drivers

OPTIONS_SUB=	YES
MYSQL_USES=	mysql
MYSQL_CPPFLAGS=	-I${LOCALBASE}/include/mysql
MYSQL_LDFLAGS=	-L${LOCALBASE}/lib/mysql

PGSQL_USES=	pgsql

SQLITE_LIB_DEPENDS=	libsqlite.so:databases/sqlite2

SQLITE3_USES=	sqlite:3

MSSQL_LIB_DEPENDS=	libsybdb.so:databases/freetds

SYBASE_LIB_DEPENDS=	libct.so:databases/freetds

NLS_USES=		gettext

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_MODULES+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_MODULES+=	pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_MODULES+=	sqlite
.endif

.if ${PORT_OPTIONS:MSQLITE3}
CONFIGURE_MODULES+=	sqlite3
.endif

.if ${PORT_OPTIONS:MMSSQL}
CONFIGURE_MODULES+=	mssql
.endif

.if ${PORT_OPTIONS:MSYBASE}
CONFIGURE_MODULES+=	sybase
.endif

.include <bsd.port.mk>
