# Created by: tremere@cainites.net
# $FreeBSD$

PORTNAME=	opendbx
PORTVERSION=	1.4.5
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.linuxnetworks.de/opendbx/download/

MAINTAINER=	tremere@cainites.net
COMMENT=	A C library for accessing databases with a single API

USE_GMAKE=	YES
USE_AUTOTOOLS=	libtool

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS} -L${WRKSRC}/lib -L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-backends="${CONFIGURE_MODULES}"

USE_LDCONFIG=	${PREFIX}/lib/opendbx

OPTIONS_DEFINE=	NLS
OPTIONS_MULTI=	DRIVER
OPTIONS_MULTI_DRIVER=	MYSQL PGSQL SQLITE2 MSSQL SYBASE
OPTIONS_DEFAULT=	MYSQL
SQLITE2_DESC=	SQLite 2 database
SYBASE_DESC=	Sybase database
DRIVER_DESC=	Database drivers

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL?=		YES
CONFIGURE_MODULES+=	"mysql"
CPPFLAGS+=		-I${LOCALBASE}/include/mysql
LDFLAGS+=		-L${LOCALBASE}/lib/mysql
PLIST_SUB+=		WITHMYSQL=""
.else
PLIST_SUB+=		WITHMYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL?=		YES
CONFIGURE_MODULES+=	"pgsql"
PLIST_SUB+=		WITHPGSQL=""
.else
PLIST_SUB+=		WITHPGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
LIB_DEPENDS+=		libsqlite.so:${PORTSDIR}/databases/sqlite2
CONFIGURE_MODULES+=	"sqlite"
PLIST_SUB+=		WITHSQLITE=""
.else
PLIST_SUB+=		WITHSQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE3}
LIB_DEPENDS+=		libsqlite3.so:${PORTSDIR}/databases/sqlite3
CONFIGURE_MODULES+=	"sqlite3"
PLIST_SUB+=		WITHSQLITE3=""
.else
PLIST_SUB+=		WITHSQLITE3="@comment "
.endif

.if ${PORT_OPTIONS:MMSSQL}
LIB_DEPENDS+=		libsybdb.so:${PORTSDIR}/databases/freetds
CONFIGURE_MODULES+=	"mssql"
PLIST_SUB+=		WITHMSSQL=""
.else
PLIST_SUB+=		WITHMSSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSYBASE}
LIB_DEPENDS+=		libct.so:${PORTSDIR}/databases/freetds
CONFIGURE_MODULES+=	"sybase"
PLIST_SUB+=		WITHSYBASE=""
.else
PLIST_SUB+=		WITHSYBASE="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.include <bsd.port.mk>
