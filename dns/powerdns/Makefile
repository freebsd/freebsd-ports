# $FreeBSD$

PORTNAME=	powerdns
PORTVERSION=	3.4.8
PORTREVISION=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/
DISTNAME=	pdns-${PORTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS server with multiple backends including SQL

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs

BROKEN_powerpc64=	Does not build

USES=		cpe gmake libtool lua pkgconfig tar:bzip2
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
ZEROMQ_IMPLIES=			REMOTE

OPTIONS_DEFAULT=	PGSQL DNSSEC BOTAN110 POLARSSL
OPTIONS_SUB=		yes

BOTAN110_CONFIGURE_ON=	--enable-botan1.10
BOTAN110_LIB_DEPENDS=	libbotan-1.10.so:security/botan110

GEO_VARS=		MODULES+=geo

GEOIP_LIB_DEPENDS=	libyaml-cpp.so:devel/yaml-cpp \
			libGeoIP.so:net/GeoIP
GEOIP_VARS=		MODULES+=geoip

LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb
LMDB_VARS=		MODULES+=lmdb

LUA_VARS=		MODULES+=lua

MYDNS_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYDNS_USE=		MYSQL=YES
MYDNS_VARS=		MODULES+=mydns

MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYSQL_CONFIGURE_OFF=	--without-mysql
MYSQL_USE=		MYSQL=YES
MYSQL_VARS=		MODULES+=gmysql

OPENDBX_LIB_DEPENDS=	libopendbx.so:databases/opendbx
OPENDBX_VARS=		MODULES+=opendbx

OPENLDAP_CXXFLAGS=	-DLDAP_DEPRECATED=1
OPENLDAP_USE=		OPENLDAP=YES
OPENLDAP_VARS=		MODULES+=ldap

PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
PGSQL_CONFIGURE_OFF=	--without-pgsql
PGSQL_USES=		pgsql
PGSQL_VARS=		MODULES+=gpgsql

POLARSSL_CONFIGURE_ARGS=	--without-system-polarssl
POLARSSL_LIB_DEPENDS_OFF=	libmbedtls.so:security/polarssl13

REMOTE_VARS=		MODULES+=remote

SQLITE3_USES=		sqlite:3
SQLITE3_VARS=		MODULES+=gsqlite3

TINYDNS_CONFIGURE_ON=	CDB_LIBS="-L${LOCALBASE}/lib -lcdb" CDB_CFLAGS="-I${LOCALBASE}/include"
TINYDNS_LIB_DEPENDS=	libcdb.so:databases/tinycdb
TINYDNS_VARS=		MODULES+=tinydns

ZEROMQ_CONFIGURE_ARGS=	--enable-remotebackend-zeromq
ZEROMQ_LIB_DEPENDS=	libzmq.so:net/libzmq4

TOOLS_CONFIGURE_ENABLE=	tools

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
ZEROMQ_DESC=		Enable ZeroMQ connector (Implies REMOTE enabled)

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in pdns.conf
	${INSTALL_DATA} ${FILESDIR}/$i ${STAGEDIR}${EXAMPLESDIR}/
.endfor

.include <bsd.port.mk>
