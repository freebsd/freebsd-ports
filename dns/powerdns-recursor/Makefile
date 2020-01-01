# Created by: sten@blinkenlights.nl
# $FreeBSD$

PORTNAME=	recursor
DISTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://downloads.powerdns.com/releases/
PKGNAMEPREFIX=	powerdns-
DISTNAME=	pdns-${PORTNAME}-${DISTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS recursor

LICENSE=	GPLv2

BROKEN_armv6=	fails to compile: use of overloaded operator << is ambiguous
BROKEN_armv7=	fails to compile: use of overloaded operator << is ambiguous
BROKEN_sparc64=	fails to compile: json11.cpp: undefined reference to std::__throw_out_of_range_fmt

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libboost_context.so:devel/boost-libs \
		libprotobuf.so:devel/protobuf

USES=		compiler:c++11-lib cpe gmake localbase:ldflags pkgconfig ssl \
		tar:bzip2

CPE_VENDOR=	powerdns
USE_RC_SUBR=	pdns-recursor

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/pdns \
		--with-protobuf \
		--without-net-snmp

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		LUAJIT SETUID
OPTIONS_DEFAULT=	SETUID

LUAJIT_DESC=	Use LuaJIT instead of Lua
SETUID_DESC=	Run as pdns_recursor user

LUAJIT_LIB_DEPENDS=	libluajit-5.1.so.2:lang/luajit
LUAJIT_USES_OFF=	lua
LUAJIT_CONFIGURE_ON=	--with-lua=luajit

SETUID_EXTRA_PATCHES=	${PATCHDIR}/extrapatch-setuid
SETUID_VARS=		GROUPS=pdns \
			USERS=pdns_recursor

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200085 && ${SSL_DEFAULT} != openssl
CONFIGURE_ARGS+=	--enable-libdecaf \
			--enable-libsodium
LIB_DEPENDS+=		libdecaf.so:security/libdecaf \
			libsodium.so:security/libsodium
.endif

.include <bsd.port.post.mk>
