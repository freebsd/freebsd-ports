# New ports collection makefile for:    opendbx
# Date Created:                         17 March 2006
# Whom:                                 tremere@cainites.net
#
# $FreeBSD$
#

PORTNAME=	opendbx
PORTVERSION=	1.4.2
CATEGORIES=	databases
MASTER_SITES=	http://www.linuxnetworks.de/opendbx/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	A C library for accessing databases with a single API

USE_GMAKE=	YES
USE_AUTOTOOLS=	libtool:22

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS} -L${WRKSRC}/lib -L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-backends="${CONFIGURE_MODULES}"
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

USE_LDCONFIG=	${PREFIX}/lib/opendbx

OPTIONS=	MYSQL	"Support for the MySQL database" on \
		PGSQL	"Support for the PostgreSQL database" off \
		SQLITE	"Support for the SQLite 2 database" off \
		SQLITE3	"Support for the SQLite 3 database" off \
		MSSQL	"Support for the MSSQL database" off \
		SYBASE	"Support for the Sybase database" off

.include <bsd.port.pre.mk>

.if !defined(WITH_MYSQL) && !defined(WITH_PGSQL) && !defined(WITH_SQLITE) && !defined(WITH_SQLITE3) && !defined(WITH_MSSQL) && !defined(WITH_SYBASE)
IGNORE=		needs at least one database backend
.endif

.if defined(WITH_MYSQL)
USE_MYSQL?=		YES
CONFIGURE_MODULES+=	"mysql"
CPPFLAGS+=		-I${LOCALBASE}/include/mysql
LDFLAGS+=		-L${LOCALBASE}/lib/mysql
PLIST_SUB+=		WITHMYSQL=""
.else
PLIST_SUB+=		WITHMYSQL="@comment "
.endif

.if !defined(WITHOUT_PGSQL)
USE_PGSQL?=		YES
CONFIGURE_MODULES+=	"pgsql"
PLIST_SUB+=		WITHPGSQL=""
.else
PLIST_SUB+=		WITHPGSQL="@comment "
.endif

.if defined(WITH_SQLITE)
LIB_DEPENDS+=		sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_MODULES+=	"sqlite"
PLIST_SUB+=		WITHSQLITE=""
.else
PLIST_SUB+=		WITHSQLITE="@comment "
.endif

.if defined(WITH_SQLITE3)
LIB_DEPENDS+=		sqlite3:${PORTSDIR}/databases/sqlite3
CONFIGURE_MODULES+=	"sqlite3"
PLIST_SUB+=		WITHSQLITE3=""
.else
PLIST_SUB+=		WITHSQLITE3="@comment "
.endif

.if defined(WITH_MSSQL)
LIB_DEPENDS+=		sybdb.5:${PORTSDIR}/databases/freetds
CONFIGURE_MODULES+=	"mssql"
PLIST_SUB+=		WITHMSSQL=""
.else
PLIST_SUB+=		WITHMSSQL="@comment "
.endif

.if defined(WITH_SYBASE)
LIB_DEPENDS+=		ct.4:${PORTSDIR}/databases/freetds
CONFIGURE_MODULES+=	"sybase"
PLIST_SUB+=		WITHSYBASE=""
.else
PLIST_SUB+=		WITHSYBASE="@comment "
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

.include <bsd.port.post.mk>
