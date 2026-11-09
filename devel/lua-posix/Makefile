PORTNAME=	posix
PORTVERSION=	38
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lua bindings for POSIX APIs
WWW=		https://luarocks.org/modules/gvvaughan/luaposix \
		https://github.com/luaposix/luaposix

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LUA_PKGNAMEPREFIX}luarocks>=0:devel/lua-luarocks@${LUA_FLAVOR} \
		${LUA_PKGNAMEPREFIX}luarocks-build-luke>=0.2:devel/lua-luarocks-build-luke@${LUA_FLAVOR}
RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}stdlib-normalize>=0:devel/lua-stdlib-normalize@${LUA_FLAVOR}

USES=		lua:52+,module

USE_GITHUB=	yes
GH_ACCOUNT=	luaposix
GH_PROJECT=	luaposix

do-build:
	@cd ${WRKSRC} && ${SETENV} CC="${CC}" CFLAGS="${CFLAGS}" ${LOCALBASE}/bin/luarocks${LUA_VER_STR} --lua-version=${LUA_VER} make --deps-mode=none --tree=${WRKSRC}/.tree ${WRKSRC}/luaposix-${PORTVERSION}-1.rockspec
	@${FIND} ${WRKSRC}/.tree/lib/lua/${LUA_VER}/posix -name '*.so' -exec ${STRIP_CMD} {} +

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	cd ${WRKSRC}/.tree/lib/lua/${LUA_VER} && ${COPYTREE_SHARE} posix ${STAGEDIR}${LUA_MODLIBDIR}
	cd ${WRKSRC}/.tree/share/lua/${LUA_VER} && ${COPYTREE_SHARE} posix ${STAGEDIR}${LUA_MODSHAREDIR}

.include <bsd.port.mk>
