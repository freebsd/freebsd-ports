PORTNAME=	powerdns
DISTVERSION=	4.9.5
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	https://downloads.powerdns.com/releases/
DISTNAME=	pdns-${DISTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS server with multiple backends including SQL
WWW=		https://www.powerdns.com/auth.html

LICENSE=	GPLv2

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	archs with 32-bits time_t are no longer supported by upstream

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libcurl.so:ftp/curl

USES=		autoreconf compiler:c++11-lib cpe gmake libtool \
		localbase:ldflags pathfix pkgconfig ssl tar:bzip2

USE_RC_SUBR=	pdns
USE_SUBMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--docdir="${PREFIX}/share/doc/powerdns" \
		--sysconfdir="${PREFIX}/etc/pdns" \
		--with-boost="${LOCALBASE}" \
		--with-dynmodules="pipe bind ${MODULES}" \
		--with-libsodium=no \
		--with-modules=""

SCRIPTS_ENV=	CURDIR2="${.CURDIR}" \
		DISTNAME="${DISTNAME}" \
		MKDIR="${MKDIR}" \
		POWERDNS_OPTIONS="${POWERDNS_OPTIONS}" \
		WRKDIRPREFIX="${WRKDIRPREFIX}"
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message

USERS=		pdns
GROUPS=		pdns

OPTIONS_DEFINE=		DOCS EXAMPLES GEOIP IXFRDIST LMDB LUABACKEND MYSQL \
			OPENLDAP PGSQL REMOTE SQLITE3 TINYDNS TOOLS UNIXODBC \
			ZEROMQ
OPTIONS_DEFAULT=	LMDB LUA MYSQL PGSQL SQLITE3
OPTIONS_SINGLE=		EXTLUA
OPTIONS_SINGLE_EXTLUA=	LUA LUAJIT

OPTIONS_SUB=		yes

EXTLUA_DESC=		Lua library
GEOIP_DESC=		GeoIP backend (GeoIP2 DB)
IXFRDIST_DESC=		Build ixfrdist
LMDB_DESC=		LMDB backend
LUABACKEND_DESC=	Lua2 backend
LUAJIT_DESC=		Use luajit
LUA_DESC=		Use lang/lua
MYSQL_DESC=		MySQL backend
OPENLDAP_DESC=		OpenLDAP backend
PGSQL_DESC=		PostgreSQL backend
REMOTE_DESC=		Remote backend
SQLITE3_DESC=		SQLite 3 backend
TINYDNS_DESC=		TinyDNS backend
TOOLS_DESC=		Build extra tools
ZEROMQ_DESC=		Enable ZeroMQ connector (Implies REMOTE enabled)

GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb \
			libyaml-cpp.so:devel/yaml-cpp
GEOIP_VARS=		MODULES+=geoip

IXFRDIST_LIB_DEPENDS=	libyaml-cpp.so:devel/yaml-cpp
IXFRDIST_CONFIGURE_ENABLE=	ixfrdist

LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb \
			libboost_serialization.so:devel/boost-libs
LMDB_CONFIGURE_ON=	--with-lmdb=${LOCALBASE}
LMDB_CONFIGURE_OFF=	--without-lmdb
LMDB_VARS=		MODULES+=lmdb

LUABACKEND_VARS=	MODULES+=lua2

LUAJIT_USES=		luajit
LUAJIT_CONFIGURE_ON=	--with-lua=luajit

LUA_USES=		lua

MYSQL_LIB_DEPENDS=	libunwind.so:devel/libunwind
MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYSQL_CONFIGURE_OFF=	--without-mysql
MYSQL_VARS=		MODULES+=gmysql

OPENLDAP_USES=		ldap
OPENLDAP_CXXFLAGS=	-DLDAP_DEPRECATED=1
OPENLDAP_VARS=		MODULES+=ldap

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-pg-config=${LOCALBASE}/bin/pg_config
PGSQL_VARS=		MODULES+=gpgsql

REMOTE_VARS=		MODULES+=remote

SQLITE3_USES=		sqlite:3
SQLITE3_VARS=		MODULES+=gsqlite3

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

post-install::
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}/var/run/pdns
	@${STAGEDIR}${PREFIX}/sbin/pdns_server --module-dir=${STAGEDIR}${PREFIX}/lib/pdns \
		--launch="pipe bind ${MODULES}" --config > ${STAGEDIR}${EXAMPLESDIR}/pdns.conf
	@${REINPLACE_CMD} -e 's;${STAGEDIR};;' -i '' ${STAGEDIR}${EXAMPLESDIR}/pdns.conf

.include <bsd.port.mk>
