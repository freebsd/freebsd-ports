# New ports collection makefile for:	libgda2
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgda2
PORTVERSION=	0.91.0
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/0.91
DISTNAME=	libgda-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides uniform access to different kinds of data sources

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier glib20 libxslt
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

MAN1=		gda-config-tool.1
MAN5=		gda-config.5

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.10)
WITH_MYSQL3=	yes
.endif

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.12)
WITH_MYSQL40=	yes
.endif

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.14)
WITH_MYSQL41=	yes
.endif

.if exists(${LOCALBASE}/lib/libpq.so.3)
WITH_POSTGRES7=	yes
.endif

.if exists(${LOCALBASE}/lib/libpgeasy.so.2)
WITH_POSTGRES72=yes
.endif

.if exists(${LOCALBASE}/lib/libldap.so.2)
WITH_LDAP=yes
.endif

.if exists(${LOCALBASE}/firebird/lib/libgds.so.1)
WITH_FIREBIRD=	yes
.endif

.if exists(${LOCALBASE}/lib/libtds.so.2)
WITH_FREETDS=	yes
.endif

.if exists(${LOCALBASE}/lib/libsybdb.so.3)
WITH_SYBASE=	yes
.endif

.if exists(${LOCALBASE}/lib/libmdbsql.so.0)
WITH_MDB=	yes
.endif

.if exists(${LOCALBASE}/lib/libODBC.so.1)
WITH_ODBC=	yes
.endif

.if exists(${LOCALBASE}/lib/libsqlite.so.2)
WITH_SQLITE=	yes
.endif

.if !defined(WITHOUT_MYSQL3) && defined(WITH_MYSQL3)
LIB_DEPENDS+=		mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
PLIST_SUB=		MYSQL:=""
.endif

.if !defined(WITHOUT_MYSQL40) && defined(WITH_MYSQL40)
LIB_DEPENDS+=		mysqlclient.12:${PORTSDIR}/databases/mysql40-client
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
PLIST_SUB=		MYSQL:=""
.endif

.if !defined(WITHOUT_MYSQL41) && defined(WITH_MYSQL41)
LIB_DEPENDS+=		mysqlclient.14:${PORTSDIR}/databases/mysql41-client
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
PLIST_SUB=		MYSQL:=""
.endif

.if !defined(WITH_MYSQL3) && !defined(WITH_MYSQL40) && !defined(WITH_MYSQL41)
PLIST_SUB+=		MYSQL:="@comment "
CONFIGURE_ARGS+=	--without-mysql
.endif

.if !defined(WITHOUT_POSTGRES7) && defined(WITH_POSTGRES7)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=		pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
PLIST_SUB+=		POSTGRES:=""
.endif

.if !defined(WITHOUT_POSTGRES72) && defined(WITH_POSTGRES72)
POSTGRESQL_PORT?=	databases/postgresql72
LIB_DEPENDS+=		pqeasy.2:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
PLIST_SUB+=		POSTGRES:=""
.endif

.if !defined(WITH_POSTGRES7) && !defined(WITH_POSTGRES72)
PLIST_SUB+=		POSTGRES:="@comment "
CONFIGURE_ARGS+=	--without-postgres
.endif

.if !defined(WITHOUT_LDAP) && defined(WITH_LDAP)
LIB_DEPENDS+=		ldap.2:${PORTSDIR}/net/openldap20-client
CONFIGURE_ARGS+=	--with-ldap=${LOCALBASE}
PLIST_SUB+=		LDAP:=""
.else
CONFIGURE_ARGS+=	--without-ldap
PLIST_SUB+=		LDAP:="@comment "
.endif

.if !defined(WITHOUT_FIREBIRD) && defined(WITH_FIREBIRD)
LIB_DEPENDS+=		gds.1:${PORTSDIR}/databases/firebird
CONFIGURE_ARGS+=	--with-firebird=${LOCALBASE}/firebird
PLIST_SUB+=		FIREBIRD:=""
.else
CONFIGURE_ARGS+=	--without-interbase
PLIST_SUB+=		FIREBIRD:="@comment "
.endif

.if !defined(WITHOUT_FREETDS) && defined(WITH_FREETDS)
LIB_DEPENDS+=		tds.2:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=	--with-tds=${LOCALBASE}
PLIST_SUB+=		FREETDS:=""
.else
CONFIGURE_ARGS+=	--without-tds
PLIST_SUB+=		FREETDS:="@comment "
.endif

.if !defined(WITHOUT_SYBASE) && defined(WITH_SYBASE)
LIB_DEPENDS+=		sybdb.3:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=	--with-sybase=${LOCALBASE}
PLIST_SUB+=		SYBASE:=""
.else
CONFIGURE_ARGS+=	--without-sybase
PLIST_SUB+=		SYBASE:="@comment "
.endif

.if !defined(WITHOUT_MDB) && defined(WITH_MDB)
LIB_DEPENDS+=		mdbsql.0:${PORTSDIR}/databases/mdbtools
CONFIGURE_ARGS+=	--with-mdb=${LOCALBASE}
PLIST_SUB+=		MDB:=""
.else
CONFIGURE_ARGS+=	--without-mdb
PLIST_SUB+=		MDB:="@comment "
.endif

.if !defined(WITHOUT_ODBC) && defined(WITH_ODBC)
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=${LOCALBASE}
PLIST_SUB+=		ODBC:=""
.else
CONFIGURE_ARGS+=	--without-odbc
PLIST_SUB+=		ODBC:="@comment "
.endif

.if !defined(WITHOUT_SQLITE) && defined(WITH_SQLITE)
LIB_DEPENDS+=		sqlite.2:${PORTSDIR}/databases/sqlite
CONFIGURE_ARGS+=	--with-sqlite=${LOCALBASE}
PLIST_SUB+=		SQLITE:=""
.else
CONFIGURE_ARGS+=	--without-sqlite
PLIST_SUB+=		SQLITE:="@comment "
.endif

pre-everything::
.if !defined(WITH_MYSQL3)
	@${ECHO_MSG} "You can enable support for MySQL 3 databases by defining WITH_MYSQL3."
.endif
.if !defined(WITH_MYSQL40)
	@${ECHO_MSG} "You can enable support for MySQL 4.0 databases by defining WITH_MYSQL40."
.endif
.if !defined(WITH_MYSQL41)
	@${ECHO_MSG} "You can enable support for MySQL 4.1 databases by defining WITH_MYSQL41."
.endif 
.if !defined(WITH_POSTGRES7)
	@${ECHO_MSG} "You can enable support for Postgres 7.0 databases by defining WITH_POSTGRES7."
.endif
.if !defined(WITH_POSTGRES72)
	@${ECHO_MSG} "You can enable support for Postgres 7.2 databases by defining WITH_POSTGRES72."
.endif
.if !defined(WITH_LDAP)
	@${ECHO_MSG} "You can enable support for LDAP databases by defining WITH_LDAP."
.endif
.if !defined(WITH_FREETDS)
	@${ECHO_MSG} "You can enable support for TDS databases by defining WITH_FREETDS."
.endif
.if !defined(WITH_SYBASE)
	@${ECHO_MSG} "You can enable support for Sybase databases by defining WITH_SYBASE."
.endif
.if !defined(WITH_MDB)
	@${ECHO_MSG} "You can enable support for MDB databases by defining WITH_MDB."
.endif
.if !defined(WITH_ODBC)
	@${ECHO_MSG} "You can enable support for ODBC databases by defining WITH_ODBC."
.endif
.if !defined(WITH_SQLITE)
	@${ECHO_MSG} "You can enable support for SQLITE databases by defining WITH_SQLITE."
.endif

.include <bsd.port.post.mk>
