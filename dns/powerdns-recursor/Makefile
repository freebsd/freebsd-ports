PORTNAME=	recursor
DISTVERSION=	5.3.0
CATEGORIES=	dns
MASTER_SITES=	https://downloads.powerdns.com/releases/
PKGNAMEPREFIX=	powerdns-
DISTNAME=	pdns-${PORTNAME}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS recursor
WWW=		https://www.PowerDNS.com/recursor.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	archs with 32-bits time_t are no longer supported by upstream

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libboost_context.so:devel/boost-libs \
		libcurl.so:ftp/curl

USES=		cargo compiler:c++11-lib cpe localbase meson pkgconfig \
		python:build tar:xz

CPE_VENDOR=	powerdns
USE_RC_SUBR=	pdns_recursor

MESON_ARGS=	--sysconfdir=${PREFIX}/etc/pdns \
		-Dhardening=disabled \
		-Dlibcap=disabled \
		-Dsigners-libsodium=disabled \
		-Dsystemd-service=disabled

CARGO_CARGOLOCK=	${WRKSRC}/rec-rust-lib/rust/Cargo.lock
CARGO_CARGOTOML=	${WRKSRC}/rec-rust-lib/rust/Cargo.toml
CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TEST=		no

BINARY_ALIAS=	python3=${PYTHON_CMD}
SUB_FILES=	pkg-message
TARGET_ORDER_OVERRIDE=	750:cargo-configure

USERS=		pdns_recursor
GROUPS=		pdns

OPTIONS_DEFINE=		DNSTAP SNMP
OPTIONS_DEFAULT=	LUA
OPTIONS_SINGLE=		EXTLUA
OPTIONS_SINGLE_EXTLUA=	LUA LUAJIT

DNSTAP_DESC=	dnstap support (see dnstap.info)
LUAJIT_DESC=	Use luajit
LUA_DESC=	Use lang/lua

DNSTAP_LIB_DEPENDS=	libfstrm.so:devel/fstrm
DNSTAP_MESON_ENABLED=	dnstap

LUAJIT_USES=		luajit
LUAJIT_MESON_ON=	-Dlua=luajit

LUA_USES=	lua
LUA_MESON_ON=	-Dlua=lua

SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_MESON_ENABLED=	snmp

pre-configure:
	@${ECHO_MSG} "===> Generating stub lib.rs to satisfy cargo configure"
	@echo "// stub" > ${WRKSRC}/rec-rust-lib/rust/src/lib.rs

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/pdns-recursor

.include <bsd.port.mk>
