# New ports collection makefile for:	libgda2
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgda2
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/1.0
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
USE_GNOME=	gnomeprefix gnomehack gnomehier glib20 libxslt
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

MAN1=		gda-config-tool.1
MAN5=		gda-config.5

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/2$//}

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/testing//" \
		${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so)
WITH_MYSQL=	yes
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

.if !defined(WITH_MYSQL)
PLIST_SUB+=		MYSQL:="@comment "
CONFIGURE_ARGS+=	--without-mysql
.else
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
PLIST_SUB+=		MYSQL:=""
.endif

.if !defined(WITHOUT_POSTGRES7) && defined(WITH_POSTGRES7)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=		pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
PLIST_SUB+=		POSTGRES:=""
.endif

.if !defined(WITHOUT_POSTGRES72) && defined(WITH_POSTGRES72)
POSTGRESQL_PORT?=	databases/postgresql72
LIB_DEPENDS+=		pgeasy.2:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
PLIST_SUB+=		POSTGRES:=""
.endif

.if !defined(WITH_POSTGRES7) && !defined(WITH_POSTGRES72)
PLIST_SUB+=		POSTGRES:="@comment "
CONFIGURE_ARGS+=	--without-postgres
.endif

.if !defined(WITHOUT_LDAP) && defined(WITH_LDAP)
USE_OPENLDAP=		yes
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
.if !defined(WITH_MYSQL)
	@${ECHO_MSG} "You can enable support for MySQL databases by defining WITH_MYSQL."
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
