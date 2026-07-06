PORTNAME=	powerdns
DISTVERSION=	5.1.3
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	https://downloads.powerdns.com/releases/
DISTNAME=	pdns-${DISTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS server with multiple backends including SQL
WWW=		https://www.powerdns.com/auth.html

LICENSE=	GPLv2

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	archs with 32-bits time_t are no longer supported by upstream

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR}
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libsodium.so:security/libsodium

USES=		compiler:c++17-lang cpe libtool localbase meson pkgconfig \
		python:build ssl tar:bzip2

USE_RC_SUBR=	pdns

MESON_ARGS=	--datadir=${PREFIX}/share/doc \
		--libdir=${PREFIX}/lib \
		--sysconfdir=${PREFIX}/etc/pdns \
		-Ddns-over-tls=enabled \
		-Dhardening=disabled \
		-Dipcipher=enabled \
		-Dlua-records=true \
		-Dmodule-bind=dynamic \
		-Dsigners-libcrypto-path=${OPENSSLBASE} \
		-Dsigners-libcrypto=enabled \
		-Dsigners-libsodium=enabled \
		-Dsystemd-service=disabled \
		-Dtls-libssl-dir=${OPENSSLBASE} \
		-Dtls-libssl=enabled

DOCSDIR=	${PREFIX}/share/doc/pdns
BINARY_ALIAS=	python3=${PYTHON_CMD}
SUB_FILES=	pkg-message

USERS=		pdns
GROUPS=		pdns

OPTIONS_DEFINE=		DOCS EXAMPLES GEOIP GNUTLS IXFRDIST LMDB LUABACKEND \
			MYSQL OPENLDAP PGSQL REMOTE SQLITE3 TINYDNS TOOLS \
			UNIXODBC ZEROMQ
OPTIONS_DEFAULT=	LMDB LUA MYSQL PGSQL SQLITE3
OPTIONS_SINGLE=		EXTLUA
OPTIONS_SINGLE_EXTLUA=	LUA LUAJIT

OPTIONS_SUB=	yes

EXTLUA_DESC=		Lua library implementation
GEOIP_DESC=		GeoIP backend (GeoIP2 DB)
GNUTLS_DESC=		DoT support via GnuTLS (sdig only)
IXFRDIST_DESC=		Build ixfrdist
LMDB_DESC=		LMDB backend
LUABACKEND_DESC=	Lua2 backend module (launch=lua2)
LUAJIT_DESC=		Use LuaJIT (enables Lua records)
LUA_DESC=		Use lang/lua (enables Lua records)
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
GEOIP_MESON_ON=		-Dmodule-geoip=dynamic
GEOIP_VARS=		MODULES+=geoip

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_MESON_ENABLED=	tls-gnutls

IXFRDIST_LIB_DEPENDS=	libyaml-cpp.so:devel/yaml-cpp
IXFRDIST_MESON_TRUE=	tools-ixfrdist

LMDB_LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
			liblmdb.so:databases/lmdb0
LMDB_MESON_ON=		-Dmodule-lmdb=dynamic
LMDB_VARS=		MODULES+=lmdb

LUABACKEND_MESON_ON=	-Dmodule-lua2=dynamic
LUABACKEND_VARS=	MODULES+=lua2

LUAJIT_USES=		luajit
LUAJIT_MESON_ON=	-Dlua=luajit

LUA_USES=		lua
LUA_MESON_ON=		-Dlua=lua

MYSQL_USES=		mysql
MYSQL_MESON_ON=		-Dmodule-gmysql=dynamic
MYSQL_VARS=		MODULES+=gmysql

OPENLDAP_BUILD_DEPENDS=	krb5>=0:security/krb5
OPENLDAP_LIB_DEPENDS=	libkrb5.so:security/krb5
OPENLDAP_USES=		ldap
OPENLDAP_MESON_ON=	-Dmodule-ldap=dynamic
OPENLDAP_CXXFLAGS=	-DLDAP_DEPRECATED=1
OPENLDAP_VARS=		MODULES+=ldap

PGSQL_USES=		pgsql
PGSQL_MESON_ON=		-Dmodule-gpgsql=dynamic
PGSQL_VARS=		MODULES+=gpgsql

REMOTE_MESON_ON=	-Dmodule-remote=dynamic
REMOTE_VARS=		MODULES+=remote

SQLITE3_USES=		sqlite:3
SQLITE3_MESON_ON=	-Dmodule-gsqlite3=dynamic
SQLITE3_VARS=		MODULES+=gsqlite3

TINYDNS_LIB_DEPENDS=	libcdb.so:databases/tinycdb
TINYDNS_MESON_ON=	-Dmodule-tinydns=dynamic
TINYDNS_VARS=		MODULES+=tinydns

TOOLS_MESON_TRUE=	tools

UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
UNIXODBC_MESON_ON=	-Dmodule-godbc=dynamic
UNIXODBC_VARS=		MODULES+=godbc

ZEROMQ_IMPLIES=		REMOTE
ZEROMQ_LIB_DEPENDS=	libzmq.so:net/libzmq4
ZEROMQ_MESON_TRUE=	module-remote-zeromq

post-install::
.for bin in dnsdemog kvresp
	@${RM} ${STAGEDIR}${PREFIX}/bin/${bin}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}/var/run/pdns
	@${STAGEDIR}${PREFIX}/sbin/pdns_server --module-dir=${STAGEDIR}${PREFIX}/lib/pdns \
		--launch="pipe bind ${MODULES}" --config > ${STAGEDIR}${EXAMPLESDIR}/pdns.conf
	@${REINPLACE_CMD} -e 's;${STAGEDIR};;' -i '' ${STAGEDIR}${EXAMPLESDIR}/pdns.conf

.include <bsd.port.mk>
