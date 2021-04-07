PORTNAME=	powerdns
DISTVERSION=	4.4.1
CATEGORIES=	dns
MASTER_SITES=	https://downloads.powerdns.com/releases/
DISTNAME=	pdns-${DISTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS server with multiple backends including SQL

LICENSE=	GPLv2

BROKEN_sparc64=	Does not compile: error: to_string is not a member of std

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libprotobuf.so:devel/protobuf

USES=		autoreconf compiler:c++11-lib cpe gmake libtool \
		localbase:ldflags pathfix pkgconfig ssl tar:bzip2

USE_RC_SUBR=	pdns
USE_SUBMAKE=	YES

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-static \
		--docdir="${PREFIX}/share/doc/powerdns" \
		--sysconfdir="${PREFIX}/etc/pdns" \
		--with-boost="${LOCALBASE}" \
		--with-dynmodules="pipe bind ${MODULES}" \
		--with-modules="" \
		--with-protobuf

SCRIPTS_ENV=	CURDIR2="${.CURDIR}" \
		DISTNAME="${DISTNAME}" \
		MKDIR="${MKDIR}" \
		POWERDNS_OPTIONS="${POWERDNS_OPTIONS}" \
		WRKDIRPREFIX="${WRKDIRPREFIX}"
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message

USERS=		pdns
GROUPS=		pdns

OPTIONS_DEFINE=			DOCS EXAMPLES GEOIP IXFRDIST LMDB LUABACKEND \
				MYSQL OPENLDAP PGSQL REMOTE SQLITE3 TINYDNS \
				TOOLS UNIXODBC
OPTIONS_DEFAULT=		LMDB LUA MYSQL PGSQL SQLITE3
OPTIONS_GROUP=			GEOIPOPT REMOTEOPT
OPTIONS_GROUP_REMOTEOPT=	ZEROMQ
OPTIONS_SINGLE=			EXTLUA
OPTIONS_SINGLE_EXTLUA=		LUA LUAJIT LUAJITOR

OPTIONS_SUB=	yes

GEOIPOPT_DESC=		GeoIP DB options
GEOIP_DESC=		GeoIP backend (GeoIP2 DB)
IXFRDIST_DESC=		Build ixfrdist
LMDB_DESC=		LMDB backend
LUABACKEND_DESC=	Lua2 backend
LUAJITOR_DESC=		Use lang/luajit-openresty
LUAJIT_DESC=		Use lang/luajit
LUA_DESC=		Use lang/lua
MYSQL_DESC=		MySQL backend
OPENLDAP_DESC=		OpenLDAP backend
PGSQL_DESC=		PostgreSQL backend
REMOTEOPT_DESC=		Remote backend connectors
REMOTE_DESC=		Remote backend
SQLITE3_DESC=		SQLite 3 backend
TINYDNS_DESC=		TinyDNS backend
TOOLS_DESC=		Build extra tools
ZEROMQ_DESC=		Enable ZeroMQ connector (Implies REMOTE enabled)

GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb \
			libyaml-cpp.so:devel/yaml-cpp
GEOIP_VARS=		MODULES+=geoip

IXFRDIST_LIB_DEPENDS=		libyaml-cpp.so:devel/yaml-cpp
IXFRDIST_CONFIGURE_ENABLE=	ixfrdist

LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb
LMDB_CONFIGURE_ON=	--with-lmdb=${LOCALBASE}
LMDB_CONFIGURE_OFF=	--without-lmdb
LMDB_VARS=		MODULES+=lmdb

LUABACKEND_VARS=	MODULES+=lua2

LUAJITOR_LIB_DEPENDS=	libluajit-5.1.so.2:lang/luajit-openresty
LUAJITOR_CONFIGURE_ON=	--with-lua=luajit

LUAJIT_LIB_DEPENDS=	libluajit-5.1.so.2:lang/luajit
LUAJIT_CONFIGURE_ON=	--with-lua=luajit

LUA_USES=	lua

MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYSQL_CONFIGURE_OFF=	--without-mysql
MYSQL_VARS=		MODULES+=gmysql

OPENLDAP_USE=		OPENLDAP=YES
OPENLDAP_CXXFLAGS=	-DLDAP_DEPRECATED=1
OPENLDAP_VARS=		MODULES+=ldap

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-pg-config=${LOCALBASE}/bin/pg_config
PGSQL_VARS=		MODULES+=gpgsql

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

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200085 && ${SSL_DEFAULT} != openssl
CONFIGURE_ARGS+=	--with-libdecaf \
			--with-libsodium
LIB_DEPENDS+=		libdecaf.so:security/libdecaf \
			libsodium.so:security/libsodium
.else
CONFIGURE_ARGS+=	--with-libsodium=no
.endif

post-install::
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}/var/run/pdns
	@${STAGEDIR}${PREFIX}/sbin/pdns_server --module-dir=${STAGEDIR}${PREFIX}/lib/pdns --launch="pipe bind ${MODULES}" --config > ${STAGEDIR}${EXAMPLESDIR}/pdns.conf
	@${REINPLACE_CMD} -e 's;${STAGEDIR};;' -i '' ${STAGEDIR}${EXAMPLESDIR}/pdns.conf

.include <bsd.port.post.mk>
