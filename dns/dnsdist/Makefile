PORTNAME=	dnsdist
DISTVERSION=	2.0.1
CATEGORIES=	dns net
MASTER_SITES=	https://downloads.powerdns.com/releases/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tremere@cainites.net
COMMENT=	Highly DNS-, DoS- and abuse-aware loadbalancer
WWW=		https://dnsdist.org/

LICENSE=	GPLv2 ISCL MIT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_ISCL=	${WRKSRC}/ext/ipcrypt/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/ext/yahttp/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	archs with 32-bits time_t are no longer supported by upstream

BUILD_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:devel/libatomic_ops \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libnghttp2.so:www/libnghttp2 \
		libquiche.so:net/quiche \
		libre2.so:devel/re2 \
		libsodium.so:security/libsodium

USES=		cargo compiler:c++14-lang cpe libedit localbase meson pkgconfig \
		python:build tar:xz
CPE_VENDOR=	powerdns
USE_RC_SUBR=	dnsdist

MESON_ARGS=	--bindir=${PREFIX}/sbin \
		--sysconfdir=${ETCDIR} \
		-Ddns-over-http3=enabled \
		-Ddns-over-https=enabled \
		-Ddns-over-quic=enabled \
		-Ddns-over-tls=enabled \
		-Ddnscrypt=enabled \
		-Dlibcap=disabled \
		-Dlibsodium=enabled \
		-Dquiche=enabled \
		-Dre2=enabled \
		-Dsystemd-service=disabled \
		-Dxsk=disabled \
		-Dyaml=enabled

CARGO_CARGOLOCK=	${WRKSRC}/dnsdist-rust-lib/rust/Cargo.lock
CARGO_CARGOTOML=	${WRKSRC}/dnsdist-rust-lib/rust/Cargo.toml
CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TEST=		no

BINARY_ALIAS=	python3=${PYTHON_CMD}
TARGET_ORDER_OVERRIDE=	750:cargo-configure

USERS=		_dnsdist
GROUPS=		_dnsdist

OPTIONS_DEFINE=		DNSTAP IPCIPHER SNMP
OPTIONS_DEFAULT=	CDB GNUTLS IPCIPHER LMDB LUA OPENSSL
OPTIONS_GROUP=		KVSOPT
OPTIONS_GROUP_KVSOPT=	CDB LMDB
OPTIONS_MULTI=		TLS
OPTIONS_MULTI_TLS=	GNUTLS OPENSSL
OPTIONS_SINGLE=		EXTLUA
OPTIONS_SINGLE_EXTLUA=	LUA LUAJIT

CDB_DESC=	CDB backend
DNSTAP_DESC=	dnstap support (see dnstap.info)
EXTLUA_DESC=	Lua library
IPCIPHER_DESC=	ipcipher support (requires OpenSSL)
KVSOPT_DESC=	Key Value Stores
LMDB_DESC=	LMDB backend
LUAJIT_DESC=	Use luajit
LUA_DESC=	Use lang/lua

CDB_LIB_DEPENDS=	libcdb.so:databases/tinycdb
CDB_MESON_ENABLED=	cdb

DNSTAP_LIB_DEPENDS=	libfstrm.so:devel/fstrm
DNSTAP_MESON_ENABLED=	dnstap

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_MESON_ENABLED=	tls-gnutls

IPCIPHER_IMPLIES=	OPENSSL
IPCIPHER_MESON_ENABLED=	ipcipher

LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb
LMDB_MESON_ENABLED=	lmdb

LUAJIT_USES=		luajit
LUAJIT_MESON_ON=	-Dlua=luajit

LUA_USES=	lua
LUA_MESON_ON=	-Dlua=lua

OPENSSL_USES=		ssl
OPENSSL_MESON_ENABLED=	libcrypto tls-libssl
OPENSSL_MESON_ON=	-Dlibcrypto-path=${OPENSSLBASE}

SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_MESON_ENABLED=	snmp

.include <bsd.port.pre.mk>

.if !(${OSVERSION} < 1400000 && ${SSL_DEFAULT} == "base")
OPENSSL_MESON_ON+=	-Dtls-libssl-providers=true
.else
OPENSSL_MESON_ON+=	-Dtls-libssl-engines=true
.endif

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/dnsdist.conf-dist ${STAGEDIR}${ETCDIR}/dnsdist.conf.sample

.include <bsd.port.post.mk>
