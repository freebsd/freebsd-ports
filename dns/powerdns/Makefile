# $FreeBSD$

PORTNAME=	powerdns
PORTVERSION=	3.3
PORTREVISION?=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/
DISTNAME=	pdns-${PORTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS server with multiple backends including SQL

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_serialization.so:${PORTSDIR}/devel/boost-libs

USE_LUA=	5.1
LUA_COMPS=	lua

CONFLICTS=	powerdns-devel-[2-3].[0-9]*

USES=		pkgconfig gmake
USE_SUBMAKE=	YES
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	YES
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-modules="" \
		--with-dynmodules="pipe ${MODULES}" \
		--sysconfdir="${PREFIX}/etc/pdns" \
		--with-boost="${LOCALBASE}"
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		CURDIR2="${.CURDIR}" \
		MKDIR="${MKDIR}" \
		DISTNAME="${DISTNAME}" \
		POWERDNS_OPTIONS="${POWERDNS_OPTIONS}"

SUB_FILES=	pkg-message

USE_RC_SUBR=	pdns

OPTIONS_DEFINE=	PGSQL PGSQL_LOCAL MYSQL MYSQL_LOCAL \
		OPENDBX OPENLDAP OPENLDAP_LOCAL GEO POLARSSL SQLITE3 TOOLS
OPTIONS_MULTI=	DNSSEC
OPTIONS_MULTI_DNSSEC=	BOTAN110 CRYPTOPP

PGSQL_DESC=		PostgreSQL backend
PGSQL_LOCAL_DESC=	RUN_DEPEND on PostgreSQL server
MYSQL_DESC=		MySQL backend
MYSQL_LOCAL_DESC=	RUN_DEPEND on MySQL server
OPENDBX_DESC=		OpenDBX backend
OPENLDAP_DESC=		OpenLDAP backend
OPENLDAP_LOCAL_DESC=	RUN_DEPEND on OpenLDAP server
SQLITE3_DESC=		SQLite 3 backend
GEO_DESC=		Geo backend
DNSSEC_DESC=		Extra DNSSEC options
BOTAN110_DESC=		Faster signing + ECDSA & GOST algorithms
CRYPTOPP_DESC=		ECDSA algorithms
POLARSSL_DESC=		Use embedded PolarSSL
TOOLS_DESC=		Build extra tools

OPTIONS_DEFAULT=	PGSQL DNSSEC BOTAN110 POLARSSL

OPTIONS_SUB=	yes

TOOLS_CONFIGURE_ENABLE=	tools

PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
PGSQL_CONFIGURE_OFF=	--without-pgsql
PGSQL_USE=		PGSQL=YES
PGSQL_LOCAL_USE=	PGSQL=server

MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYSQL_CONFIGURE_OFF=	--without-mysql
MYSQL_USE=		MYSQL=YES
MYSQL_LOCAL_USE=	MYSQL=server

OPENLDAP_CXXFLAGS=	-DLDAP_DEPRECATED=1
OPENLDAP_USE=		OPENLDAP=YES
OPENLDAP_LOCAL_RUN_DEPENDS=	openldap-server>=0:${PORTSDIR}/net/openldap24-server

SQLITE3_USE=	SQLITE=3

OPENDBX_LIB_DEPENDS=	libopendbx.so:${PORTSDIR}/databases/opendbx

BOTAN110_CONFIGURE_ENABLE=	botan1.10
BOTAN110_LIB_DEPENDS=		libbotan-1.10.so:${PORTSDIR}/security/botan110

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGEO}
MODULES+=	"geo"
.endif

.if ${PORT_OPTIONS:MPGSQL}
MODULES+=	"gpgsql"
.endif

.if ${PORT_OPTIONS:MMYSQL}
MODULES+=	"gmysql"
.endif

.if ${PORT_OPTIONS:MPGSQL_LOCAL}
SUB_LIST+=	PGSQL_REQ=postgresql
.else
SUB_LIST+=	PGSQL_REQ=
.endif

.if ${PORT_OPTIONS:MMYSQL_LOCAL}
SUB_LIST+=	MYSQL_REQ=mysql
.else
SUB_LIST+=	MYSQL_REQ=
.endif

.if ${PORT_OPTIONS:MOPENLDAP}
MODULES+=	"ldap"
.endif

.if ${PORT_OPTIONS:MOPENLDAP_LOCAL}
SUB_LIST+=	SLAPD_REQ=slapd
.else
SUB_LIST+=	SLAPD_REQ=
.endif

.if ${PORT_OPTIONS:MSQLITE3}
MODULES+=	"gsqlite3"
.endif

.if ${PORT_OPTIONS:MOPENDBX}
MODULES+=	"opendbx"
.endif

.if ${PORT_OPTIONS:MCRYPTOPP}
CONFIGURE_ARGS+=	--enable-cryptopp
.	if exists(${LOCALBASE}/lib/libcryptopp.so)
LIB_DEPENDS+=	libcryptopp.so:${PORTSDIR}/security/cryptopp
.	else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcryptopp.a:${PORTSDIR}/security/cryptopp
.	endif
.endif

.if ${PORT_OPTIONS:MPOLARSSL}
CONFIGURE_ARGS+=	--without-system-polarssl
.else
LIB_DEPENDS+=		libpolarssl.so:${PORTSDIR}/security/polarssl
.endif

post-patch:
.if ${PORT_OPTIONS:MOPENLDAP}
	@${REINPLACE_CMD} -e 's;-I. ;-I. -I${LOCALBASE}/include ;' \
		-e 's;la_LDFLAGS =;la_LDFLAGS = -L${LOCALBASE}/lib;' \
		${WRKSRC}/modules/ldapbackend/Makefile.in
	@${REINPLACE_CMD} -e 's;@LIBDL@;@LIBDL@ -L${LOCALBASE}/lib;' \
		-e 's;@modulelibs@;@modulelibs@ -llber;' \
		${WRKSRC}/pdns/Makefile.in
.endif
.if ${PORT_OPTIONS:MPGSQL}
	@${REINPLACE_CMD} -E -e 's;(PGSQL_inc_check="\$$withval/include/pgsql)";\1 \$$withval/include";' \
		${WRKSRC}/configure
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in pdns.conf
	${INSTALL_DATA} ${FILESDIR}/$i ${STAGEDIR}${EXAMPLESDIR}/
.endfor
.for j in libgpgsqlbackend.so libgmysqlbackend.so \
	libgsqlite3backend.so libldapbackend.so libopendbxbackend.so \
	libgeobackend.so libpipebackend.so
	@if ([ -f ${STAGEDIR}${PREFIX}/lib/$j ] && [ ! -f ${STAGEDIR}${PREFIX}/lib/$j.0 ]); then \
		${LN} -sf ${PREFIX}/lib/$j ${STAGEDIR}${PREFIX}/lib/$j.0; \
	fi
.endfor

.include <bsd.port.mk>
