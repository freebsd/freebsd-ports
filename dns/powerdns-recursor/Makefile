# Created by: sten@blinkenlights.nl
# $FreeBSD$

PORTNAME=	recursor
PORTVERSION=	4.0.4
CATEGORIES=	dns ipv6
MASTER_SITES=	http://downloads.powerdns.com/releases/
PKGNAMEPREFIX=	powerdns-
DISTNAME=	pdns-${PORTNAME}-${PORTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS recursor

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libboost_context.so:devel/boost-libs

BROKEN_sparc64=	Does not compile on sparc64

USES=		compiler:c++11-lib cpe gmake localbase pkgconfig ssl tar:bzip2
GNU_CONFIGURE=	YES
CXXFLAGS+=	-D_GLIBCXX_USE_C99

CPE_VENDOR=	powerdns

OPTIONS_DEFINE=	SETUID
OPTIONS_DEFAULT=	LUA SETUID
OPTIONS_RADIO=	LUA_RG
OPTIONS_RADIO_LUA_RG=	LUA LUAJIT
LUAJIT_DESC=		Enable LuaJIT
LUA_RG_DESC=		Lua Engine
SETUID_DESC=		Run as pdns_recursor user

CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/pdns

SUB_FILES=	pkg-message

LUA_CONFIGURE_WITH=	lua
LUA_USES=		lua

LUAJIT_CONFIGURE_WITH=	luajit
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so.2:lang/luajit

SETUID_EXTRA_PATCHES=	${PATCHDIR}/extrapatch-setuid

USE_RC_SUBR+=	pdns-recursor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSETUID}
USERS=		pdns_recursor
GROUPS=		pdns
.endif

.include <bsd.port.mk>
