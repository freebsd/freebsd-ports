PORTNAME=	std.functional
PORTVERSION=	2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Functional Programming with Lua
WWW=		https://luarocks.org/modules/gvvaughan/std.functional \
		https://lua-stdlib.github.io/functional/ \
		https://github.com/lua-stdlib/functional

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}stdlib-normalize>=4:devel/lua-stdlib-normalize@${LUA_FLAVOR}

USES=		lua:module

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	lua-stdlib
GH_PROJECT=	functional

do-patch:
	@${REINPLACE_CMD} -e 's|@version@|${PORTVERSION}|' ${WRKSRC}/lib/std/functional/version.lua.in > ${WRKSRC}/lib/std/functional/version.lua

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}/std/functional
	${INSTALL_DATA} ${WRKSRC}/lib/std/functional/*.lua ${STAGEDIR}${LUA_MODSHAREDIR}/std/functional

.include <bsd.port.mk>
