# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/libgda2/Makefile,v 1.44 2008/03/11 04:21:46 mezz Exp $

PORTNAME=	libgda2
PORTVERSION=	1.2.4
PORTREVISION?=	6
PORTEPOCH?=	1
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/1.2
DISTNAME=	libgda-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides uniform access to different kinds of data sources

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		librarian.so:${PORTSDIR}/textproc/rarian

CONFLICTS=	libgda-0*

USE_GNOME=	gnomeprefix gnomehack glib20 libxslt referencehack intlhack
USES=		gettext gmake pkgconfig
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-bdb
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lintl"
CPPFLAGS+=	-I${LOCALBASE}/include -DGLIB_COMPILATION

MAN1=		gda-config-tool.1
MAN5=		gda-config.5

PLIST_SUB=	VERSION=${PORTVERSION:R}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/testing//" \
		${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so)
WITH_MYSQL=	yes
.endif

.if exists(${LOCALBASE}/lib/libldap.so)
WITH_LDAP=yes
.endif

.if exists(${LOCALBASE}/lib/libgds.so.1)
WITH_FIREBIRD=	yes
.elif exists(${LOCALBASE}/lib/libgds.so.2)
WITHOUT_FIREBIRD=yes
.endif

.if exists(${LOCALBASE}/lib/libtds.so)
WITH_FREETDS=	yes
.endif

# Sybase backend is linux only
#.if exists(${LOCALBASE}/lib/libsybdb.so)
#WITH_SYBASE=	yes
#.endif

.if exists(${LOCALBASE}/lib/libmdbsql.so)
WITH_MDB=	yes
.endif

.if exists(${LOCALBASE}/lib/libODBC.so)
WITH_ODBC=	yes
.endif

.if exists(${LOCALBASE}/lib/libsqlite3.so)
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

.if !defined(WITHOUT_PGSQL) && defined(WITH_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
PLIST_SUB+=		POSTGRES:=""
.else
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
LIB_DEPENDS+=		libgds.so:${PORTSDIR}/databases/firebird-client
CONFIGURE_ARGS+=	--with-firebird=${LOCALBASE}
PLIST_SUB+=		FIREBIRD:=""
.else
CONFIGURE_ARGS+=	--without-firebird
PLIST_SUB+=		FIREBIRD:="@comment "
.endif

.if !defined(WITHOUT_FREETDS) && defined(WITH_FREETDS)
LIB_DEPENDS+=		libtds.so:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=	--with-tds=${LOCALBASE}
PLIST_SUB+=		FREETDS:=""
.else
CONFIGURE_ARGS+=	--without-tds
PLIST_SUB+=		FREETDS:="@comment "
.endif

.if !defined(WITHOUT_SYBASE) && defined(WITH_SYBASE)
LIB_DEPENDS+=		libsybdb.so:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=	--with-sybase=${LOCALBASE}
PLIST_SUB+=		SYBASE:=""
BROKEN=	Sybase backend is linux only
.else
CONFIGURE_ARGS+=	--without-sybase
PLIST_SUB+=		SYBASE:="@comment "
.endif

.if !defined(WITHOUT_MDB) && defined(WITH_MDB)
LIB_DEPENDS+=		libmdbsql.so:${PORTSDIR}/databases/mdbtools
CONFIGURE_ARGS+=	--with-mdb=${LOCALBASE}
PLIST_SUB+=		MDB:=""
.else
CONFIGURE_ARGS+=	--without-mdb
PLIST_SUB+=		MDB:="@comment "
.endif

.if !defined(WITHOUT_ODBC) && defined(WITH_ODBC)
LIB_DEPENDS+=		libodbc.so:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=${LOCALBASE}
PLIST_SUB+=		ODBC:=""
.else
CONFIGURE_ARGS+=	--without-odbc
PLIST_SUB+=		ODBC:="@comment "
.endif

.if !defined(WITHOUT_SQLITE) && defined(WITH_SQLITE)
LIB_DEPENDS+=		libsqlite3.so:${PORTSDIR}/databases/sqlite3
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
.if !defined(WITH_LDAP)
	@${ECHO_MSG} "You can enable support for LDAP databases by defining WITH_LDAP."
.endif
.if !defined(WITH_FIREBIRD)
	@${ECHO_MSG} "You can enable support for FireBird databases by defining WITH_FIREBIRD."
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

.endif
