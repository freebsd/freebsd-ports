# New ports collection makefile for:	powerdns
# Date Created:				14.Jan 2003
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	powerdns
PORTVERSION=	3.1
PORTREVISION?=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/ \
		http://mirrors.evolva.ro/powerdns.com/releases/
DISTNAME=	pdns-${PORTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	An advanced DNS server with multiple backends including SQL

LICENSE=	GPLv2

BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost-jam
LIB_DEPENDS=	boost_serialization.[4-9]:${PORTSDIR}/devel/boost-libs
#		botan.0:${PORTSDIR}/security/botan

USE_LUA=	5.1
LUA_COMPS=	lua

CONFLICTS=	powerdns-devel-[2-3].[0-9]*

USE_GMAKE=	YES
USE_SUBMAKE=	YES
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	YES
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-modules="" \
		--with-dynmodules="pipe ${CONFIGURE_MODULES}" \
		--sysconfdir="${PREFIX}/etc/pdns" \
		--with-boost="${LOCALBASE}"
#		--enable-botan1.8
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		CURDIR2="${.CURDIR}" \
		MKDIR="${MKDIR}" \
		DISTNAME="${DISTNAME}" \
		POWERDNS_OPTIONS="${POWERDNS_OPTIONS}"
MAN8=		pdns_control.8 pdns_server.8 zone2sql.8

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	PGSQL PGSQL_LOCAL MYSQL MYSQL_LOCAL SQLITE SQLITE3 OPENDBX OPENLDAP OPENLDAP_LOCAL GEO DNSSEC

PGSQL_DESC=		PostgreSQL backend
PGSQL_LOCAL_DESC=	RUN_DEPEND on PostgreSQL server
MYSQL_DESC=		MySQL backend
MYSQL_LOCAL_DESC=	RUN_DEPEND on MySQL server
SQLITE_DESC=		SQLite 2 backend
SQLITE3_DESC=		SQLite 3 backend
OPENDBX_DESC=		OpenDBX backend
OPENLDAP_DESC=		OpenLDAP backend
OPENLDAP_LOCAL_DESC=	RUN_DEPEND on OpenLDAP server
GEO_DESC=		Geo backend
DNSSEC_DESC=		Enable extra DNSSEC algorithms (13 & 14)

OPTIONS_DEFAULT=	PGSQL

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

USE_RC_SUBR+=	pdns

.if ${PORT_OPTIONS:MGEO}
CONFIGURE_MODULES+=	"geo"
PLIST_SUB+=		WITHGEO=""
.else
PLIST_SUB+=		WITHGEO="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE} && ${PORT_OPTIONS:MSQLITE3}
BROKEN=	choose only one SQLite backend version
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL?=		YES
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}
CONFIGURE_MODULES+=	"gpgsql"
PLIST_SUB+=		WITHPGSQL=""
.else
CONFIGURE_ARGS+=	--without-pgsql
PLIST_SUB+=		WITHPGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL?=		YES
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
CONFIGURE_MODULES+=	"gmysql"
#CXXFLAGS+=		-I${LOCALBASE}/include/mysql
#LDFLAGS+=		-L${LOCALBASE}/lib/mysql
PLIST_SUB+=		WITHMYSQL=""
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=		WITHMYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MOPENDBX} || ${PORT_OPTIONS:MPGSQL}
.	if ${PORT_OPTIONS:MPGSQL_LOCAL}
USE_PGSQL?=		YES
RUN_DEPENDS+=	postgresql-server>=0:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
SUB_LIST+=	PGSQL=postgresql
.	endif
.else
SUB_LIST+=	PGSQL=
.endif
.if ${PORT_OPTIONS:MOPENDBX} || ${PORT_OPTIONS:MMYSQL}
.	if ${PORT_OPTIONS:MMYSQL_LOCAL}
USE_MYSQL?=		YES
RUN_DEPENDS+=	mysql-server>=0:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
SUB_LIST+=	MYSQL=mysql
.	endif
.else
SUB_LIST+=	MYSQL=
.endif

.if ${PORT_OPTIONS:MOPENLDAP}
USE_OPENLDAP?=		YES
CONFIGURE_MODULES+=	"ldap"
CXXFLAGS+=		-L${LOCALBASE}/lib -DLDAP_DEPRECATED=1
PLIST_SUB+=		WITHOPENLDAP=""
.	if ${PORT_OPTIONS:MOPENLDAP_LOCAL}
RUN_DEPENDS+=	openldap-server>=0:${PORTSDIR}/net/openldap${WANT_OPENLDAP_VER}-server
SUB_LIST+=	SLAPD=slapd
.	else
SUB_LIST+=	SLAPD=
.	endif
.else
PLIST_SUB+=		WITHOPENLDAP="@comment "
SUB_LIST+=		SLAPD=
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE?=		2
CONFIGURE_MODULES+=	"gsqlite"
PLIST_SUB+=		WITHSQLITE=""
.else
PLIST_SUB+=		WITHSQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE3}
USE_SQLITE?=		3
CONFIGURE_MODULES+=	"gsqlite3"
PLIST_SUB+=		WITHSQLITE3=""
.else
PLIST_SUB+=		WITHSQLITE3="@comment "
.endif

.if ${PORT_OPTIONS:MOPENDBX}
LIB_DEPENDS+=		opendbx:${PORTSDIR}/databases/opendbx
CONFIGURE_MODULES+=	"opendbx"
PLIST_SUB+=		WITHOPENDBX=""
CXXFLAGS+=		-L${LOCALBASE}/lib
.else
PLIST_SUB+=		WITHOPENDBX="@comment "
.endif

.if ${PORT_OPTIONS:MDNSSEC}
BUILD_DEPENDS+=		${LOCALBASE}/lib/libcryptopp.a:${PORTSDIR}/security/cryptopp
CONFIGURE_ARGS+=	--enable-cryptopp
.endif

post-patch:
.if ${PORT_OPTIONS:MOPENLDAP}
	${REINPLACE_CMD} -e 's;-I. ;-I. -I${LOCALBASE}/include ;' \
		-e 's;la_LDFLAGS =;la_LDFLAGS = -L${LOCALBASE}/lib;' \
		${WRKSRC}/modules/ldapbackend/Makefile.in
	${REINPLACE_CMD} -e 's;@LIBDL@;@LIBDL@ -L${LOCALBASE}/lib;' \
		-e 's;@modulelibs@;@modulelibs@ -llber;' \
		${WRKSRC}/pdns/Makefile.in
.endif
.if ${PORT_OPTIONS:MPGSQL}
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
