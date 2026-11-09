PORTNAME=	std.prototype
PORTVERSION=	2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Prototype Oriented Programming with Lua
WWW=		https://luarocks.org/modules/gvvaughan/std.prototype \
		https://lua-stdlib.github.io/prototype/ \
		https://github.com/lua-stdlib/prototype

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}stdlib-normalize>=4:devel/lua-stdlib-normalize@${LUA_FLAVOR}

USES=		lua:module

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	lua-stdlib
GH_PROJECT=	prototype

do-patch:
	@${REINPLACE_CMD} -e 's|@version@|${PORTVERSION}|' ${WRKSRC}/lib/std/prototype/version.lua.in > ${WRKSRC}/lib/std/prototype/version.lua

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}/std/prototype
	${INSTALL_DATA} ${WRKSRC}/lib/std/prototype/*.lua ${STAGEDIR}${LUA_MODSHAREDIR}/std/prototype

.include <bsd.port.mk>
