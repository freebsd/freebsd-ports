# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	dnsdist
DISTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	dns net
MASTER_SITES=	https://downloads.powerdns.com/releases/ \
		LOCAL/cpm

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Highly DNS-, DoS- and abuse-aware loadbalancer

LICENSE=	GPLv2 UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_UNLICENSE=	${WRKSRC}/ext/incbin/UNLICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:devel/libatomic_ops
LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libprotobuf.so:devel/protobuf \
		libre2.so:devel/re2 \
		libsodium.so:security/libsodium

GNU_CONFIGURE=	yes
USES=		bison compiler:c++14-lang cpe gmake libedit libtool localbase \
		pkgconfig tar:bz2
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin \
		--enable-dns-over-tls \
		--enable-dnscrypt \
		--enable-libsodium \
		--enable-re2

INSTALL_TARGET=	install-strip

USERS=		_dnsdist
GROUPS=		_dnsdist

USE_RC_SUBR=	dnsdist

OPTIONS_DEFINE=		FSTRM LUAJIT SNMP
OPTIONS_DEFAULT=	GNUTLS OPENSSL
OPTIONS_MULTI=		TLS
OPTIONS_MULTI_TLS=	GNUTLS OPENSSL

FSTRM_DESC=		dnstap support (see dnstap.info)
LUAJIT_DESC=		Use LuaJIT instead of Lua

FSTRM_LIB_DEPENDS=	libfstrm.so:devel/fstrm
FSTRM_CONFIGURE_ENABLE=	fstrm

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ENABLE=gnutls

LUAJIT_LIB_DEPENDS=	libluajit-5.1.so.2:lang/luajit
LUAJIT_USES_OFF=	lua
LUAJIT_CONFIGURE_WITH=	luajit

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ENABLE=libssl
OPENSSL_CONFIGURE_ON=	LIBSSL_CFLAGS=-I${OPENSSLINC} LIBSSL_LIBS="-L${OPENSSLLIB} -lssl"

SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_WITH=	net-snmp

post-install:
	${INSTALL_DATA} ${FILESDIR}/dnsdist.conf.sample \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
