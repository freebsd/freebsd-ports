# Created by: sten@blinkenlights.nl
# $FreeBSD$

PORTNAME=	recursor
DISTVERSION=	4.0.9
PORTREVISION?=	3
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/
PKGNAMEPREFIX=	powerdns-
PKGNAMESUFFIX=	40
DISTNAME=	pdns-${PORTNAME}-${DISTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS recursor

LICENSE=	GPLv2

DEPRECATED=		FreeBSD 10.3 has reached EoL since 2018-04-30; users should upgrade and use dns/powerdns-recursor instead
EXPIRATION_DATE=	2018-12-31

BROKEN_armv6=		fails to compile: use of overloaded operator << is ambiguous
BROKEN_armv7=		fails to compile: use of overloaded operator << is ambiguous
BROKEN_sparc64=		fails to compile: json11.cpp: undefined reference to std::__throw_out_of_range_fmt
BROKEN_powerpc64=	fails to compile: dnslabeltext.cc: undefined reference to std::__cxx11::basic_string

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libboost_context.so:devel/boost-libs \
		libprotobuf.so:devel/protobuf

CONFLICTS_INSTALL=	powerdns-recursor

USES=		compiler:c++11-lib cpe gmake localbase:ldflags pkgconfig ssl tar:bzip2
GNU_CONFIGURE=	YES
CXXFLAGS+=	-D_GLIBCXX_USE_C99
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/pdns \
		--with-protobuf

CPE_VENDOR=	powerdns

USE_RC_SUBR=	pdns-recursor

OPTIONS_DEFINE=	OPTALGO SETUID
OPTIONS_DEFAULT=	LUA SETUID
OPTIONS_RADIO=	LUA_RG
OPTIONS_RADIO_LUA_RG=	LUA LUAJIT
LUAJIT_DESC=		Enable LuaJIT
LUA_RG_DESC=		Lua Engine
OPTALGO_DESC=		Enable optional algorithms (12, 15 & 16)
SETUID_DESC=		Run as pdns_recursor user

LUA_CONFIGURE_WITH=	lua
LUA_USES=		lua

LUAJIT_CONFIGURE_WITH=	luajit
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so.2:lang/luajit

OPTALGO_CONFIGURE_ON=	--enable-botan \
			--enable-libdecaf \
			--enable-libsodium
OPTALGO_LIB_DEPENDS=	libbotan-2.so:security/botan2 \
			libdecaf.so:security/libdecaf \
			libsodium.so:security/libsodium

SETUID_VARS=	USERS=pdns_recursor GROUPS=pdns
SETUID_EXTRA_PATCHES=	${PATCHDIR}/extrapatch-setuid

SUB_FILES=	pkg-message

.include <bsd.port.mk>
