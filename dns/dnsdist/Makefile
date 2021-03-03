# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	dnsdist
DISTVERSION=	1.5.1
PORTREVISION=	4
CATEGORIES=	dns net
MASTER_SITES=	https://downloads.powerdns.com/releases/

MAINTAINER=	tremere@cainites.net
COMMENT=	Highly DNS-, DoS- and abuse-aware loadbalancer

LICENSE=	GPLv2 UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_UNLICENSE=	${WRKSRC}/ext/incbin/UNLICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:devel/libatomic_ops
LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libh2o-evloop.so:www/h2o \
		libprotobuf.so:devel/protobuf \
		libre2.so:devel/re2 \
		libsodium.so:security/libsodium

USES=		bison:alias compiler:c++14-lang cpe gmake libedit libtool \
		localbase pkgconfig tar:bz2
USE_RC_SUBR=	dnsdist

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin \
		--enable-dns-over-https \
		--enable-dns-over-tls \
		--enable-dnscrypt \
		--sysconfdir=${ETCDIR} \
		--with-libsodium \
		--with-re2

INSTALL_TARGET=	install-strip

USERS=		_dnsdist
GROUPS=		_dnsdist

OPTIONS_DEFINE=		DNSTAP SNMP
OPTIONS_DEFAULT=	CDB GNUTLS LMDB LUA OPENSSL
OPTIONS_GROUP=		KSVOPT
OPTIONS_GROUP_KSVOPT=	CDB LMDB
OPTIONS_MULTI=		TLS
OPTIONS_MULTI_TLS=	GNUTLS OPENSSL
OPTIONS_SINGLE=		EXTLUA
OPTIONS_SINGLE_EXTLUA=	LUA LUAJIT LUAJITOR

CDB_DESC=	CDB backend
DNSTAP_DESC=	dnstap support (see dnstap.info)
KSVOPT_DESC=	Key Value Stores
LMDB_DESC=	LMDB backend
LUAJITOR_DESC=	Use lang/luajit-openresty
LUAJIT_DESC=	Use lang/luajit
LUA_DESC=	Use lang/lua

CDB_LIB_DEPENDS=	libcdb.so:databases/tinycdb
CDB_CONFIGURE_ON=	CDB_CFLAGS="-I${LOCALBASE}/include" \
			CDB_LIBS="-L${LOCALBASE}/lib -lcdb"

DNSTAP_LIB_DEPENDS=		libfstrm.so:devel/fstrm
DNSTAP_CONFIGURE_ENABLE=	fstrm

GNUTLS_LIB_DEPENDS=		libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ENABLE=	gnutls

LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb
LMDB_CONFIGURE_ON=	--with-lmdb=${LOCALBASE}
LMDB_CONFIGURE_OFF=	--without-lmdb

LUAJITOR_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit-openresty
LUAJITOR_CONFIGURE_ON=	--with-lua=luajit

LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
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
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/dnsdist.conf.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
