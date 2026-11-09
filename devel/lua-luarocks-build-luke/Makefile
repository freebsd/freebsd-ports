PORTNAME=	luarocks-build-luke
PORTVERSION=	0.3.2
DISTVERSIONPREFIX=	luarocks-build-luke-v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	LuaRocks build backend for luke
WWW=		https://luarocks.org/modules/gvvaughan/luarocks-build-luke \
		https://github.com/gvvaughan/luke

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		lua:module

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${LUA_MODSHAREDIR}/luarocks/build/luke.lua

USE_GITHUB=	yes
GH_ACCOUNT=	gvvaughan
GH_PROJECT=	luke

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}/luarocks/build
	${INSTALL_DATA} ${WRKSRC}/build-aux/luarocks-build-luke.lua ${STAGEDIR}${LUA_MODSHAREDIR}/luarocks/build/luke.lua

.include <bsd.port.mk>
