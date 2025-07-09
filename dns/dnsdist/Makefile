PORTNAME=	dnsdist
DISTVERSION=	1.9.10
PORTREVISION=	1
CATEGORIES=	dns net
MASTER_SITES=	https://downloads.powerdns.com/releases/

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
		boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libnghttp2.so:www/libnghttp2 \
		libquiche.so:net/quiche \
		libre2.so:devel/re2 \
		libsodium.so:security/libsodium

USES=		bison:alias compiler:c++14-lang cpe gmake libedit libtool \
		localbase pkgconfig tar:bz2
CPE_VENDOR=	powerdns
USE_RC_SUBR=	dnsdist

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin \
		--enable-dns-over-http3 \
		--enable-dns-over-https \
		--enable-dns-over-quic \
		--enable-dns-over-tls \
		--enable-dnscrypt \
		--sysconfdir=${ETCDIR} \
		--with-libsodium \
		--with-re2

INSTALL_TARGET=	install-strip
LDFLAGS+=	-Wl,--as-needed

USERS=		_dnsdist
GROUPS=		_dnsdist

OPTIONS_DEFINE=		DNSTAP SNMP
OPTIONS_DEFAULT=	CDB GNUTLS LMDB LUA OPENSSL
OPTIONS_GROUP=		KSVOPT
OPTIONS_GROUP_KSVOPT=	CDB LMDB
OPTIONS_MULTI=		TLS
OPTIONS_MULTI_TLS=	GNUTLS OPENSSL
OPTIONS_SINGLE=		EXTLUA
OPTIONS_SINGLE_EXTLUA=	LUA LUAJIT

CDB_DESC=	CDB backend
DNSTAP_DESC=	dnstap support (see dnstap.info)
EXTLUA_DESC=	Lua library
KSVOPT_DESC=	Key Value Stores
LMDB_DESC=	LMDB backend
LUAJIT_DESC=	Use luajit
LUA_DESC=	Use lang/lua

CDB_LIB_DEPENDS=	libcdb.so:databases/tinycdb
CDB_CONFIGURE_ON=	CDB_CFLAGS="-I${LOCALBASE}/include" \
			CDB_LIBS="-L${LOCALBASE}/lib -lcdb"

DNSTAP_LIB_DEPENDS=		libfstrm.so:devel/fstrm
DNSTAP_CONFIGURE_ENABLE=	dnstap

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb
LMDB_CONFIGURE_ON=	--with-lmdb=${LOCALBASE}
LMDB_CONFIGURE_OFF=	--without-lmdb

LUAJIT_USES=		luajit
LUAJIT_CONFIGURE_ON=	--with-lua=luajit

LUA_USES=		lua
LUA_CONFIGURE_ON=	--with-lua=lua-${LUA_VER}

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	LIBSSL_CFLAGS=-I${OPENSSLINC} \
			LIBSSL_LIBS="-L${OPENSSLLIB} -lssl"
OPENSSL_CONFIGURE_WITH=	libssl

SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_WITH=	net-snmp

post-install:
#	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${MV} ${STAGEDIR}${ETCDIR}/dnsdist.conf-dist ${STAGEDIR}${ETCDIR}/dnsdist.conf.sample

.include <bsd.port.mk>
