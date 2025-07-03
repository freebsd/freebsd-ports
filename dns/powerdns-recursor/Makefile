PORTNAME=	recursor
DISTVERSION=	5.2.2
PORTREVISION=	3
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

USES=		autoreconf cargo compiler:c++11-lib cpe gmake libtool \
		localbase:ldflags pkgconfig python:build ssl tar:bzip2

CPE_VENDOR=	powerdns
USE_RC_SUBR=	pdns_recursor

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/pdns \
		--with-libsodium=no \
		--with-service-group=pdns_recursor \
		--with-service-user=pdns \
		--without-net-snmp \
		--without-systemd

CARGO_CARGOLOCK=	${WRKSRC}/settings/rust/Cargo.lock
CARGO_CARGOTOML=	${WRKSRC}/settings/rust/Cargo.toml
CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TEST=		no

SUB_FILES=	pkg-message
TARGET_ORDER_OVERRIDE=	750:cargo-configure

USERS=		pdns_recursor
GROUPS=		pdns

OPTIONS_DEFINE=		DNSTAP
OPTIONS_DEFAULT=	LUA
OPTIONS_SINGLE=		EXTLUA
OPTIONS_SINGLE_EXTLUA=	LUA LUAJIT

DNSTAP_DESC=	dnstap support (see dnstap.info)
LUAJIT_DESC=	Use luajit
LUA_DESC=	Use lang/lua

DNSTAP_LIB_DEPENDS=		libfstrm.so:devel/fstrm
DNSTAP_CONFIGURE_ENABLE=	dnstap

LUAJIT_USES=		luajit
LUAJIT_CONFIGURE_ON=	--with-lua=luajit

LUA_USES=	lua

#pre-configure:
#	@cd ${WRKSRC}/settings && ${PYTHON_CMD} generate.py

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/pdns-recursor

.include <bsd.port.mk>
