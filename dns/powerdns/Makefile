# $FreeBSD$

PORTNAME=	powerdns
PORTVERSION=	3.4.4
PORTREVISION=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/
DISTNAME=	pdns-${PORTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS server with multiple backends including SQL

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_serialization.so:${PORTSDIR}/devel/boost-libs

CONFLICTS=	powerdns-devel-[2-3].[0-9]*

USES=		gmake libtool lua pkgconfig tar:bzip2
USE_LDCONFIG=	YES
USE_SUBMAKE=	YES
GNU_CONFIGURE=	YES
INSTALL_TARGET=	install-strip
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LUA_CFLAGS="-I${LUA_INCDIR}" \
		LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}"
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

OPTIONS_DEFINE=	GEO GEOIP LMDB MYSQL OPENDBX OPENLDAP PGSQL POLARSSL REMOTE SQLITE3 TOOLS
OPTIONS_GROUP=	DNSSEC EXPERIMENTAL REMOTEOPT
OPTIONS_GROUP_DNSSEC=		BOTAN110
OPTIONS_GROUP_EXPERIMENTAL=	LUA MYDNS TINYDNS
OPTIONS_GROUP_REMOTEOPT=	ZEROMQ

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
REMOTEOPT_DESC=		Remote backend connectors
ZEROMQ_DESC=		Enable ZeroMQ connector

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
.	if ${PORT_OPTIONS:MZEROMQ}
CONFIGURE_ARGS+=	--enable-remotebackend-zeromq
LIB_DEPENDS+=		libzmq.so:${PORTSDIR}/net/libzmq4
.	endif
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
LIB_DEPENDS+=		libmbedtls.so.9:${PORTSDIR}/security/polarssl13
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in pdns.conf
	${INSTALL_DATA} ${FILESDIR}/$i ${STAGEDIR}${EXAMPLESDIR}/
.endfor

.include <bsd.port.mk>
