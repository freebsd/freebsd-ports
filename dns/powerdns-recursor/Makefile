PORTNAME=	recursor
DISTVERSION=	4.9.2
CATEGORIES=	dns
MASTER_SITES=	http://downloads.powerdns.com/releases/
PKGNAMEPREFIX=	powerdns-
DISTNAME=	pdns-${PORTNAME}-${DISTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS recursor
WWW=		https://www.PowerDNS.com/recursor.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=	fails to compile: use of overloaded operator << is ambiguous
BROKEN_armv7=	fails to compile: use of overloaded operator << is ambiguous
NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	archs with 32-bits time_t are no longer supported by upstream

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libboost_context.so:devel/boost-libs

USES=		autoreconf compiler:c++11-lib cpe gmake libtool \
		localbase:ldflags pkgconfig ssl tar:bzip2

CPE_VENDOR=	powerdns
USE_RC_SUBR=	pdns-recursor

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/pdns \
		--with-libsodium=no \
		--without-net-snmp \
		--without-systemd

SUB_FILES=	pkg-message

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

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/pdns-recursor

.include <bsd.port.mk>
