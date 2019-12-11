# $FreeBSD$

PORTNAME=	powerdns
DISTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	https://downloads.powerdns.com/releases/
DISTNAME=	pdns-${DISTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS server with multiple backends including SQL

LICENSE=	GPLv2

BROKEN_sparc64=		Does not compile: error: to_string is not a member of std

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libcurl.so:ftp/curl

USES=		compiler:c++11-lib cpe gmake libtool localbase:ldflags pathfix \
		pkgconfig ssl tar:bzip2
USE_LDCONFIG=	YES
USE_RC_SUBR=	pdns
USE_SUBMAKE=	YES

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-static \
		--docdir="${PREFIX}/share/doc/powerdns" \
		--sysconfdir="${PREFIX}/etc/pdns" \
		--with-boost="${LOCALBASE}" \
		--with-dynmodules="pipe bind ${MODULES}" \
		--with-modules=""

INSTALL_TARGET=	install-strip
SCRIPTS_ENV=	CURDIR2="${.CURDIR}" DISTNAME="${DISTNAME}" MKDIR="${MKDIR}" \
		POWERDNS_OPTIONS="${POWERDNS_OPTIONS}" \
		WRKDIRPREFIX="${WRKDIRPREFIX}"
SUB_FILES=	pkg-message

OPTIONS_DEFINE=			DOCS EXAMPLES GEOIP LUABACKEND LUAJIT MYDNS \
				MYSQL OPENDBX OPENLDAP PGSQL PROTOBUF REMOTE \
				SQLITE3 TINYDNS TOOLS UNIXODBC
OPTIONS_DEFAULT=		MYSQL PGSQL SQLITE3
OPTIONS_GROUP=			GEOIPOPT REMOTEOPT
OPTIONS_GROUP_REMOTEOPT=	ZEROMQ

OPTIONS_SUB=	yes

GEOIPOPT_DESC=		GeoIP DB options
GEOIP_DESC=		GeoIP backend (GeoIP2 DB)
LUABACKEND_DESC=	Lua2 backend
LUAJIT_DESC=		Use LuaJIT instead of Lua
MYDNS_DESC=		MyDNS backend
MYSQL_DESC=		MySQL backend
OPENDBX_DESC=		OpenDBX backend
OPENLDAP_DESC=		OpenLDAP backend
PGSQL_DESC=		PostgreSQL backend
PROTOBUF_DESC=		Protobuf support
REMOTEOPT_DESC=		Remote backend connectors
REMOTE_DESC=		Remote backend
SQLITE3_DESC=		SQLite 3 backend
TINYDNS_DESC=		TinyDNS backend
TOOLS_DESC=		Build extra tools
ZEROMQ_DESC=		Enable ZeroMQ connector (Implies REMOTE enabled)

GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb \
			libyaml-cpp.so:devel/yaml-cpp
GEOIP_VARS=		MODULES+=geoip

LUABACKEND_VARS=	MODULES+=lua2

LUAJIT_LIB_DEPENDS=	libluajit-5.1.so.2:lang/luajit
LUAJIT_USES_OFF=	lua
LUAJIT_CONFIGURE_ON=	--with-lua=luajit

MYDNS_USES=		mysql
MYDNS_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYDNS_VARS=		MODULES+=mydns

MYSQL_USES=		mysql
MYSQL_CONFIGURE_OFF=	--without-mysql
MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYSQL_VARS=		MODULES+=gmysql

OPENDBX_LIB_DEPENDS=	libopendbx.so:databases/opendbx
OPENDBX_VARS=		MODULES+=opendbx

OPENLDAP_USE=		OPENLDAP=YES
OPENLDAP_CXXFLAGS=	-DLDAP_DEPRECATED=1
OPENLDAP_VARS=		MODULES+=ldap

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-pg-config=${LOCALBASE}/bin/pg_config
PGSQL_VARS=		MODULES+=gpgsql

PROTOBUF_LIB_DEPENDS=		libprotobuf.so:devel/protobuf
PROTOBUF_CONFIGURE_WITH=	protobuf

REMOTE_VARS=	MODULES+=remote

SQLITE3_USES=	sqlite:3
SQLITE3_VARS=	MODULES+=gsqlite3

TINYDNS_LIB_DEPENDS=	libcdb.so:databases/tinycdb
TINYDNS_CONFIGURE_ON=	CDB_CFLAGS="-I${LOCALBASE}/include" \
			CDB_LIBS="-L${LOCALBASE}/lib -lcdb"
TINYDNS_VARS=		MODULES+=tinydns

TOOLS_CONFIGURE_ENABLE=	tools

UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
UNIXODBC_VARS=		MODULES+=godbc

ZEROMQ_IMPLIES=		REMOTE
ZEROMQ_LIB_DEPENDS=	libzmq.so:net/libzmq4
ZEROMQ_CONFIGURE_ON=	--enable-remotebackend-zeromq

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200085 && ${SSL_DEFAULT} != openssl111
CONFIGURE_ARGS+=	--with-libdecaf \
			--with-libsodium
LIB_DEPENDS+=		libdecaf.so:security/libdecaf \
			libsodium.so:security/libsodium
.endif

post-install::
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${STAGEDIR}${LOCALBASE}/sbin/pdns_server --module-dir=${STAGEDIR}${LOCALBASE}/lib/pdns --launch="pipe bind ${MODULES}" --config > ${STAGEDIR}${EXAMPLESDIR}/pdns.conf
	@${REINPLACE_CMD} -e 's;${STAGEDIR};;' -i '' ${STAGEDIR}${EXAMPLESDIR}/pdns.conf

.include <bsd.port.post.mk>
