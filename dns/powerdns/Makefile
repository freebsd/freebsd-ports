# $FreeBSD$

PORTNAME=	powerdns
PORTVERSION=	3.4.0
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/
DISTNAME=	pdns-${PORTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS server with multiple backends including SQL

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_serialization.so:${PORTSDIR}/devel/boost-libs

CONFLICTS=	powerdns-devel-[2-3].[0-9]*

USES=		gmake libtool lua:51 pkgconfig tar:bzip2
USE_LDCONFIG=	YES
USE_SUBMAKE=	YES
GNU_CONFIGURE=	YES
INSTALL_TARGET=	install-strip
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-static \
		--with-modules="" \
		--with-dynmodules="pipe bind ${MODULES}" \
		--docdir="${PREFIX}/share/doc/powerdns" \
		--sysconfdir="${PREFIX}/etc/pdns" \
		--with-boost="${LOCALBASE}"
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		CURDIR2="${.CURDIR}" \
		MKDIR="${MKDIR}" \
		DISTNAME="${DISTNAME}" \
		POWERDNS_OPTIONS="${POWERDNS_OPTIONS}"

SUB_FILES=	pkg-message

USE_RC_SUBR=	pdns

OPTIONS_DEFINE=	GEO MYSQL OPENDBX OPENLDAP PGSQL POLARSSL REMOTE SQLITE3 TOOLS
OPTIONS_GROUP=	DNSSEC EXPERIMENTAL
OPTIONS_GROUP_DNSSEC=	BOTAN110
OPTIONS_GROUP_EXPERIMENTAL=	GEOIP LMDB LUA MYDNS TINYDNS

PGSQL_DESC=		PostgreSQL backend
MYSQL_DESC=		MySQL backend
OPENDBX_DESC=		OpenDBX backend
OPENLDAP_DESC=		OpenLDAP backend
SQLITE3_DESC=		SQLite 3 backend
GEO_DESC=		Geo backend
GEOIP_DESC=		GeoIP backend
DNSSEC_DESC=		Extra DNSSEC options
BOTAN110_DESC=		Faster signing + ECDSA & GOST algorithms
POLARSSL_DESC=		Use embedded PolarSSL
LMDB_DESC=		LMDB backend
LUA_DESC=		Lua backend
MYDNS_DESC=		MyDNS backend
REMOTE_DESC=		Remote backend
TINYDNS_DESC=		TinyDNS backend
TOOLS_DESC=		Build extra tools

OPTIONS_DEFAULT=	PGSQL DNSSEC BOTAN110 POLARSSL

OPTIONS_SUB=	yes

# Don't use CONFIGURE_ENABLE, the configure script
# has a bug. The options are being enabled even using --disable-

TOOLS_CONFIGURE_ON=	--enable-tools

PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
PGSQL_CONFIGURE_OFF=	--without-pgsql
PGSQL_USES=		pgsql

MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYSQL_CONFIGURE_OFF=	--without-mysql
MYSQL_USE=		MYSQL=YES

MYDNS_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYDNS_USE=		MYSQL=YES

OPENLDAP_CXXFLAGS=	-DLDAP_DEPRECATED=1
OPENLDAP_USE=		OPENLDAP=YES

SQLITE3_USE=		SQLITE=3

OPENDBX_LIB_DEPENDS=	libopendbx.so:${PORTSDIR}/databases/opendbx

BOTAN110_CONFIGURE_ON=	--enable-botan1.10
BOTAN110_LIB_DEPENDS=	libbotan-1.10.so:${PORTSDIR}/security/botan110

TINYDNS_LIB_DEPENDS=	libcdb.so:${PORTSDIR}/databases/tinycdb
TINYDNS_CONFIGURE_ON=	CDB_LIBS="-L${LOCALBASE}/lib -lcdb" CDB_CFLAGS="-I${LOCALBASE}/include"

LMDB_LIB_DEPENDS=	liblmdb.so:${PORTSDIR}/databases/lmdb

GEOIP_LIB_DEPENDS=	libyaml-cpp.so:${PORTSDIR}/devel/yaml-cpp \
			libGeoIP.so:${PORTSDIR}/net/GeoIP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGEO}
MODULES+=	geo
.endif

.if ${PORT_OPTIONS:MGEOIP}
MODULES+=	geoip
.endif

.if ${PORT_OPTIONS:MPGSQL}
MODULES+=	gpgsql
.endif

.if ${PORT_OPTIONS:MMYSQL}
MODULES+=	gmysql
.endif

.if ${PORT_OPTIONS:MOPENLDAP}
MODULES+=	ldap
.endif

.if ${PORT_OPTIONS:MSQLITE3}
MODULES+=	gsqlite3
.endif

.if ${PORT_OPTIONS:MLMDB}
MODULES+=	lmdb
.endif

.if ${PORT_OPTIONS:MLUA}
MODULES+=	lua
.endif

.if ${PORT_OPTIONS:MMYDNS}
MODULES+=	mydns
.endif

.if ${PORT_OPTIONS:MREMOTE}
MODULES+=	remote
.endif

.if ${PORT_OPTIONS:MTINYDNS}
MODULES+=	tinydns
.endif

.if ${PORT_OPTIONS:MOPENDBX}
MODULES+=	opendbx
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

.include <bsd.port.mk>
