# $FreeBSD$

PORTNAME=	powerdns
DISTVERSION=	4.1.5
PORTREVISION=	3
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/
DISTNAME=	pdns-${DISTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS server with multiple backends including SQL

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build: undefined reference to std::__throw_out_of_range_fmt
BROKEN_sparc64=		Does not compile: error: to_string is not a member of std

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs

USES=		compiler:c++11-lib cpe gmake libtool localbase:ldflags pathfix pkgconfig ssl \
		tar:bzip2

USE_LDCONFIG=	YES
USE_SUBMAKE=	YES
GNU_CONFIGURE=	YES
INSTALL_TARGET=	install-strip
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

OPTIONS_DEFINE=	DOCS EXAMPLES GEOIP LUAJIT MYDNS MYSQL OPENDBX OPENLDAP OPTALGO PGSQL PROTOBUF REMOTE SQLITE3 TINYDNS TOOLS UNIXODBC
OPTIONS_GROUP=	EXPERIMENTAL REMOTEOPT
OPTIONS_GROUP_EXPERIMENTAL=	LUABACKEND
OPTIONS_GROUP_REMOTEOPT=	ZEROMQ
ZEROMQ_IMPLIES=			REMOTE

OPTIONS_DEFAULT=	MYSQL PGSQL SQLITE3
OPTIONS_SUB=		yes

GEOIP_LIB_DEPENDS=	libyaml-cpp.so:devel/yaml-cpp \
			libGeoIP.so:net/GeoIP
GEOIP_VARS=		MODULES+=geoip

LUABACKEND_VARS=	MODULES+=lua

LUAJIT_CONFIGURE_WITH=	luajit
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so.2:lang/luajit
LUAJIT_USES_OFF=	lua

MYDNS_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYDNS_USES=		mysql
MYDNS_VARS=		MODULES+=mydns

MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYSQL_CONFIGURE_OFF=	--without-mysql
MYSQL_USES=		mysql
MYSQL_VARS=		MODULES+=gmysql

OPENDBX_LIB_DEPENDS=	libopendbx.so:databases/opendbx
OPENDBX_VARS=		MODULES+=opendbx

OPENLDAP_CXXFLAGS=	-DLDAP_DEPRECATED=1
OPENLDAP_USE=		OPENLDAP=YES
OPENLDAP_VARS=		MODULES+=ldap

OPTALGO_CONFIGURE_ON=	--enable-botan \
			--enable-libdecaf \
			--enable-libsodium
OPTALGO_LIB_DEPENDS=	libbotan-2.so:security/botan2 \
			libdecaf.so:security/libdecaf \
			libsodium.so:security/libsodium

PGSQL_CONFIGURE_ON=	--with-pg-config=${LOCALBASE}/bin/pg_config
PGSQL_USES=		pgsql
PGSQL_VARS=		MODULES+=gpgsql

PROTOBUF_CONFIGURE_WITH=	protobuf
PROTOBUF_LIB_DEPENDS=	libprotobuf.so:devel/protobuf

REMOTE_VARS=		MODULES+=remote

SQLITE3_USES=		sqlite:3
SQLITE3_VARS=		MODULES+=gsqlite3

TINYDNS_CONFIGURE_ON=	CDB_LIBS="-L${LOCALBASE}/lib -lcdb" CDB_CFLAGS="-I${LOCALBASE}/include"
TINYDNS_LIB_DEPENDS=	libcdb.so:databases/tinycdb
TINYDNS_VARS=		MODULES+=tinydns

TOOLS_CONFIGURE_ENABLE=	tools

UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
UNIXODBC_VARS=		MODULES+=godbc

ZEROMQ_CONFIGURE_ARGS=	--enable-remotebackend-zeromq
ZEROMQ_LIB_DEPENDS=	libzmq.so:net/libzmq4

GEOIP_DESC=		GeoIP backend
LUABACKEND_DESC=	Lua backend
LUAJIT_DESC=		Use LuaJIT instead of Lua
MYDNS_DESC=		MyDNS backend
MYSQL_DESC=		MySQL backend
OPENDBX_DESC=		OpenDBX backend
OPENLDAP_DESC=		OpenLDAP backend
OPTALGO_DESC=		Enable optional algorithms (12, 15 & 16)
PGSQL_DESC=		PostgreSQL backend
PROTOBUF_DESC=		Protobuf support
REMOTE_DESC=		Remote backend
REMOTEOPT_DESC=		Remote backend connectors
SQLITE3_DESC=		SQLite 3 backend
TINYDNS_DESC=		TinyDNS backend
TOOLS_DESC=		Build extra tools
ZEROMQ_DESC=		Enable ZeroMQ connector (Implies REMOTE enabled)

post-install::
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${STAGEDIR}${LOCALBASE}/sbin/pdns_server --module-dir=${STAGEDIR}${LOCALBASE}/lib/pdns --launch="pipe bind ${MODULES}" --config > ${STAGEDIR}${EXAMPLESDIR}/pdns.conf
	@${REINPLACE_CMD} -e 's;${STAGEDIR};;' -i '' ${STAGEDIR}${EXAMPLESDIR}/pdns.conf

.include <bsd.port.mk>
