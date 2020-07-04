# $FreeBSD$

PORTNAME=	lua-resty-redis
DISTVERSIONPREFIX=	v
DISTVERSION=	0.27
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	arcade@b1t.name
COMMENT=	Redis client driver for the ngx_lua nginx module

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	luajit-openresty>=2.1:lang/luajit-openresty

USE_GITHUB=	yes
GH_ACCOUNT=	openresty

NO_ARCH=	yes
NO_BUILD=	yes

LUA_MODSHAREDIR=	${LOCALBASE}/share/lua/5.1

PLIST_SUB=	LUA_MODSHAREDIR=${LUA_MODSHAREDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${LUA_MODSHAREDIR} "-name *\.lua")

.include <bsd.port.mk>
