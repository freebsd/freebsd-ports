# New ports collection makefile for:	powerdns
# Date Created:				14.Jan 2003
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	powerdns
PORTVERSION=	2.9.22
PORTREVISION=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/ \
		http://mirrors.evolva.ro/powerdns.com/releases/
DISTNAME=	pdns-${PORTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	An advanced DNS server with multiple backends including SQL

BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost-jam \
		${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

CONFLICTS=	powerdns-devel-[0-9]*

USE_GMAKE=	YES
USE_SUBMAKE=	YES
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	YES
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-modules="pipe" \
			--with-dynmodules="${CONFIGURE_MODULES}" \
			--sysconfdir="${PREFIX}/etc/pdns" \
#			--enable-debug
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		CURDIR2="${.CURDIR}" \
		MKDIR="${MKDIR}" \
		DISTNAME="${DISTNAME}" \
		POWERDNS_OPTIONS="${POWERDNS_OPTIONS}"
MAN8=		pdns_control.8 pdns_server.8 zone2sql.8

SUB_FILES=	pkg-message

OPTIONS=	PGSQL           "PostgreSQL backend" on \
		MYSQL           "MySQL backend" off \
		SQLITE          "SQLite 2 backend" off \
		SQLITE3         "SQLite 3 backend" off \
		OPENDBX         "OpenDBX backend" off \
		OPENLDAP        "OpenLDAP backend" off \
		GEO             "Geo backend" off

.include <bsd.port.pre.mk>

USE_RC_SUBR+=	pdns

.if defined(WITH_GEO)
CONFIGURE_MODULES+=	"geo"
PLIST_SUB+=		WITHGEO=""
.else
PLIST_SUB+=		WITHGEO="@comment "
.endif

.if defined(WITH_SQLITE) && defined(WITH_SQLITE3)
BROKEN=	choose only one SQLite backend version
.endif

.if defined(WITH_PGSQL)
USE_PGSQL?=		YES
CONFIGURE_MODULES+=	"gpgsql"
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}
PLIST_SUB+=		WITHPGSQL=""
.else
CONFIGURE_ARGS+=	--disable-pgsql
PLIST_SUB+=		WITHPGSQL="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL?=		YES
CONFIGURE_MODULES+=	"gmysql"
CXXFLAGS+=		-I${LOCALBASE}/include/mysql
LDFLAGS+=		-L${LOCALBASE}/lib/mysql
PLIST_SUB+=		WITHMYSQL=""
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=		WITHMYSQL="@comment "
.endif

.if defined(WITH_OPENLDAP)
USE_OPENLDAP?=		YES
CONFIGURE_MODULES+=	"ldap"
CXXFLAGS+=		-L${LOCALBASE}/lib -DLDAP_DEPRECATED=1
PLIST_SUB+=		WITHOPENLDAP=""
.else
PLIST_SUB+=		WITHOPENLDAP="@comment "
.endif

.if defined(WITH_SQLITE)
USE_SQLITE?=		2
CONFIGURE_MODULES+=	"gsqlite"
PLIST_SUB+=		WITHSQLITE=""
.else
PLIST_SUB+=		WITHSQLITE="@comment "
.endif

.if defined(WITH_SQLITE3)
USE_SQLITE?=		3
CONFIGURE_MODULES+=	"gsqlite3"
PLIST_SUB+=		WITHSQLITE3=""
.else
PLIST_SUB+=		WITHSQLITE3="@comment "
.endif

.if defined(WITH_OPENDBX)
LIB_DEPENDS+=		opendbx.[1-2]:${PORTSDIR}/databases/opendbx
CONFIGURE_MODULES+=	"opendbx"
PLIST_SUB+=		WITHOPENDBX=""
CXXFLAGS+=		-L${LOCALBASE}/lib
.else
PLIST_SUB+=		WITHOPENDBX="@comment "
.endif

.if defined(WITH_OPENLDAP)
post-patch:
	${REINPLACE_CMD} -e 's;-I. ;-I. -I${LOCALBASE}/include ;' \
		-e 's;la_LDFLAGS =;la_LDFLAGS = -L${LOCALBASE}/lib;' \
		${WRKSRC}/modules/ldapbackend/Makefile.in
	${REINPLACE_CMD} -e 's;@LIBDL@;@LIBDL@ -L${LOCALBASE}/lib;' \
		-e 's;@modulelibs@;@modulelibs@ -llber;' \
		${WRKSRC}/pdns/Makefile.in
.endif
.if defined(WITH_PGSQL)
pre-configure:
	@${REINPLACE_CMD} -E -e 's;(PGSQL_inc_check="\$$withval/include/pgsql)";\1 \$$withval/include";' \
		${WRKSRC}/configure
.endif
post-install:
.if !exists(${PREFIX}/etc/pdns/pdns.conf)
	${INSTALL_DATA} ${PREFIX}/etc/pdns/pdns.conf-dist ${PREFIX}/etc/pdns/pdns.conf
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for i in pdns.conf tables-mssql_or_sybase.sql tables-mysql.sql tables-pgsql.sql tables-sqlite.sql
	${INSTALL_DATA} ${FILESDIR}/$i ${EXAMPLESDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
