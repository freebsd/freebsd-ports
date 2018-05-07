# Created by: sten@blinkenlights.nl
# $FreeBSD$

PORTNAME=	recursor
DISTVERSION=	4.1.2
PORTREVISION=	3
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/
PKGNAMEPREFIX=	powerdns-
DISTNAME=	pdns-${PORTNAME}-${DISTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS recursor

LICENSE=	GPLv2

BROKEN_armv6=		fails to compile: use of overloaded operator << is ambiguous
BROKEN_armv7=		fails to compile: use of overloaded operator << is ambiguous
BROKEN_sparc64=		fails to compile: json11.cpp: undefined reference to std::__throw_out_of_range_fmt
BROKEN_powerpc64=	fails to compile: dnslabeltext.cc: undefined reference to std::__cxx11::basic_string

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libboost_context.so:devel/boost-libs \
		libprotobuf.so:devel/protobuf

CONFLICTS_INSTALL=	powerdns-recursor40

USES=		compiler:c++11-lib cpe gmake localbase:ldflags pkgconfig ssl tar:bzip2
GNU_CONFIGURE=	YES
CXXFLAGS+=	-D_GLIBCXX_USE_C99
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/pdns \
		--with-protobuf

CPE_VENDOR=	powerdns

USE_RC_SUBR=	pdns-recursor

OPTIONS_DEFINE=		LUAJIT OPTALGO SETUID
OPTIONS_DEFAULT=	SETUID
LUAJIT_CONFIGURE_WITH=	luajit
LUAJIT_DESC=		Use LuaJIT instead of Lua
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so.2:lang/luajit
LUAJIT_USES_OFF=	lua
OPTALGO_CONFIGURE_ON=	--enable-botan \
			--enable-libdecaf \
			--enable-libsodium
OPTALGO_DESC=		Enable optional algorithms (12, 15 & 16)
OPTALGO_LIB_DEPENDS=	libbotan-2.so:security/botan2 \
			libdecaf.so:security/libdecaf \
			libsodium.so:security/libsodium
SETUID_DESC=		Run as pdns_recursor user
SETUID_EXTRA_PATCHES=	${PATCHDIR}/extrapatch-setuid
SETUID_VARS=		USERS=pdns_recursor GROUPS=pdns

SUB_FILES=	pkg-message

.include <bsd.port.mk>
