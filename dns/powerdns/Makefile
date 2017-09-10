# $FreeBSD$

PORTNAME=	powerdns
PORTVERSION=	4.0.4
PORTREVISION=	2
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/
DISTNAME=	pdns-${PORTVERSION}

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

OPTIONS_DEFINE=	GEOIP MYDNS MYSQL OPENDBX OPENLDAP OPTALGO PGSQL PROTOBUF REMOTE SQLITE3 TINYDNS TOOLS UNIXODBC
OPTIONS_GROUP=	EXPERIMENTAL REMOTEOPT
OPTIONS_GROUP_EXPERIMENTAL=	LUABACKEND
OPTIONS_GROUP_REMOTEOPT=	ZEROMQ
OPTIONS_SINGLE=			LUASG
OPTIONS_SINGLE_LUASG=		LUA LUAJIT
ZEROMQ_IMPLIES=			REMOTE

OPTIONS_DEFAULT=	LUA PGSQL
OPTIONS_SUB=		yes

GEOIP_LIB_DEPENDS=	libyaml-cpp.so:devel/yaml-cpp \
			libGeoIP.so:net/GeoIP
GEOIP_VARS=		MODULES+=geoip

LUA_CONFIGURE_WITH=	lua
LUA_USES=		lua

LUABACKEND_VARS=	MODULES+=lua

LUAJIT_CONFIGURE_WITH=	luajit
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so.2:lang/luajit

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

OPTALGO_CONFIGURE_ON=	--enable-botan1.10 \
			--enable-libsodium
OPTALGO_LIB_DEPENDS=	libbotan-1.10.so:security/botan110 \
			libsodium.so:security/libsodium

PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
PGSQL_CONFIGURE_OFF=	--without-pgsql
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
LUASG_DESC=		Lua Engine
LUABACKEND_DESC=	Lua backend
LUAJIT_DESC=		Enable LuaJIT
MYDNS_DESC=		MyDNS backend
MYSQL_DESC=		MySQL backend
OPENDBX_DESC=		OpenDBX backend
OPENLDAP_DESC=		OpenLDAP backend
OPTALGO_DESC=		Enable optional algorithms (12 & 15)
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
