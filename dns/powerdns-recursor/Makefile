# Created by: sten@blinkenlights.nl
# $FreeBSD$

PORTNAME=	recursor
DISTVERSION=	4.1.14
PORTREVISION=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/
PKGNAMEPREFIX=	powerdns-
DISTNAME=	pdns-${PORTNAME}-${DISTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS recursor

LICENSE=	GPLv2

BROKEN_armv6=		fails to compile: use of overloaded operator << is ambiguous
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

CXXFLAGS+=	-D_GLIBCXX_USE_C99

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		LUAJIT OPTALGO SETUID
OPTIONS_DEFAULT=	SETUID

LUAJIT_DESC=	Use LuaJIT instead of Lua
OPTALGO_DESC=	Enable optional algorithms (12, 15 & 16)
SETUID_DESC=	Run as pdns_recursor user

LUAJIT_LIB_DEPENDS=	libluajit-5.1.so.2:lang/luajit
LUAJIT_USES_OFF=	lua
LUAJIT_CONFIGURE_WITH=	luajit

OPTALGO_LIB_DEPENDS=	libbotan-2.so:security/botan2 \
			libdecaf.so:security/libdecaf \
			libsodium.so:security/libsodium
OPTALGO_CONFIGURE_ON=	--enable-botan \
			--enable-libdecaf \
			--enable-libsodium

SETUID_EXTRA_PATCHES=	${PATCHDIR}/extrapatch-setuid
SETUID_VARS=		GROUPS=pdns \
			USERS=pdns_recursor

.include <bsd.port.mk>
