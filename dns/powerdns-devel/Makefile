# New ports collection makefile for:	powerdns
# Date Created:				14.Jan 2003
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	powerdns
PORTVERSION=	2.9.22.${SNAPSHOT}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://svn.powerdns.com/snapshots/${REVISION}/
PKGNAMESUFFIX=	-devel
DISTNAME=	pdns-${PORTVERSION:S/.${SNAPSHOT}//}-rc1.${SNAPSHOT}.${REVISION}

MAINTAINER=	tremere@cainites.net
COMMENT=	An advanced DNS server with multiple backends including SQL

BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost-jam \
		${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

SNAPSHOT=	20081119
REVISION=	1305

CONFLICTS=	powerdns-[0-2]*

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
		PGSQL_LOCAL	"RUN_DEPEND on PostgreSQL" off \
		MYSQL           "MySQL backend" off \
		MYSQL_LOCAL	"RUN_DEPEND on MySQL server" off \
		SQLITE          "SQLite 2 backend" off \
		SQLITE3         "SQLite 3 backend" off \
		OPENDBX         "OpenDBX backend" off \
		OPENLDAP        "OpenLDAP backend" off \
		OPENLDAP_LOCAL	"RUN_DEPEND on OpenLDAP server" off \
		GEO             "Geo backend" off

.include <bsd.port.pre.mk>

USE_RC_SUBR+=	pdns-devel

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
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}
CONFIGURE_MODULES+=	"gpgsql"
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

.if defined(WITH_OPENDBX) || defined(WITH_PGSQL)
.	if defined(WITH_PGSQL_LOCAL)
USE_PGSQL?=		YES
RUN_DEPENDS+=	postgresql-server>=0:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
SUB_LIST+=	PGSQL=postgresql
.	else
SUB_LIST+=	PGSQL=
.	endif
.endif
.if defined(WITH_OPENDBX) || defined(WITH_MYSQL)
.	if defined(WITH_MYSQL_LOCAL)
USE_MYSQL?=		YES
RUN_DEPENDS+=	mysql-server>=0:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
SUB_LIST+=	MYSQL=mysql
.	else
SUB_LIST+=	MYSQL=
.	endif
.endif

.if defined(WITH_OPENLDAP)
USE_OPENLDAP?=		YES
CONFIGURE_MODULES+=	"ldap"
CXXFLAGS+=		-L${LOCALBASE}/lib -DLDAP_DEPRECATED=1
PLIST_SUB+=		WITHOPENLDAP=""
.	if defined(WITH_OPENLDAP_LOCAL)
RUN_DEPENDS+=	openldap-server>=0:${PORTSDIR}/net/openldap${WANT_OPENLDAP_VER}-server
SUB_LIST+=	SLAPD=slapd
.	else
SUB_LIST+=	SLAPD=
.	endif
.else
PLIST_SUB+=		WITHOPENLDAP="@comment "
SUB_LIST+=		SLAPD=
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
LIB_DEPENDS+=		opendbx.3:${PORTSDIR}/databases/opendbx
CONFIGURE_MODULES+=	"opendbx"
PLIST_SUB+=		WITHOPENDBX=""
CXXFLAGS+=		-L${LOCALBASE}/lib
.else
PLIST_SUB+=		WITHOPENDBX="@comment "
.endif

post-patch:
.if defined(WITH_OPENLDAP)
	${REINPLACE_CMD} -e 's;-I. ;-I. -I${LOCALBASE}/include ;' \
		-e 's;la_LDFLAGS =;la_LDFLAGS = -L${LOCALBASE}/lib;' \
		${WRKSRC}/modules/ldapbackend/Makefile.in
	${REINPLACE_CMD} -e 's;@LIBDL@;@LIBDL@ -L${LOCALBASE}/lib;' \
		-e 's;@modulelibs@;@modulelibs@ -llber;' \
		${WRKSRC}/pdns/Makefile.in
.endif
.if defined(WITH_PGSQL)
	@${REINPLACE_CMD} -E -e 's;(PGSQL_inc_check="\$$withval/include/pgsql)";\1 \$$withval/include";' \
		${WRKSRC}/configure
.endif

post-install:
.if !exists(${PREFIX}/etc/pdns/pdns.conf)
	${INSTALL_DATA} ${PREFIX}/etc/pdns/pdns.conf-dist ${PREFIX}/etc/pdns/pdns.conf
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for i in pdns.conf
	${INSTALL_DATA} ${FILESDIR}/$i ${EXAMPLESDIR}/
.endfor
.endif
.for j in libgpgsqlbackend.so libgmysqlbackend.so libgsqlitebackend.so \
	libgsqlite3backend.so libldapbackend.so libopendbxbackend.so \
	libgeobackend.so libpipebackend.so
	@if ([ -f ${PREFIX}/lib/$j ] && [ ! -f ${PREFIX}/lib/$j.0 ]); then \
		${LN} -sf ${PREFIX}/lib/$j ${PREFIX}/lib/$j.0; \
	fi
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
