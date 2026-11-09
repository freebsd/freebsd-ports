PORTNAME=	stdlib
PORTVERSION=	42
DISTVERSIONPREFIX=	release-v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Standard Lua Libraries
WWW=		https://luarocks.org/modules/gvvaughan/stdlib \
		https://lua-stdlib.github.io/lua-stdlib/ \
		https://github.com/lua-stdlib/lua-stdlib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}optparse>=2:devel/lua-optparse@${LUA_FLAVOR} \
		${LUA_PKGNAMEPREFIX}std.functional>=2:devel/lua-std.functional@${LUA_FLAVOR} \
		${LUA_PKGNAMEPREFIX}std.prototype>=2:devel/lua-std.prototype@${LUA_FLAVOR} \
		${LUA_PKGNAMEPREFIX}stdlib-debug>=1:devel/lua-stdlib-debug@${LUA_FLAVOR} \
		${LUA_PKGNAMEPREFIX}stdlib-normalize>=4:devel/lua-stdlib-normalize@${LUA_FLAVOR}

USES=		lua:module shebangfix

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	lua-stdlib
GH_PROJECT=	lua-stdlib

SHEBANG_FILES=	build-aux/luke

OPTIONS_DEFINE=	DOCS

do-build:
	@cd ${WRKSRC} && build-aux/luke all CFLAGS="${CFLAGS}" LUA="${LOCALBASE}/bin/${LUA_CMD}" LUA_INCDIR="${LUA_INCDIR}" PREFIX="${PREFIX}" version="${PORTVERSION}"

do-install:
	cd ${WRKSRC} && build-aux/luke install INST_LIBDIR="${STAGEDIR}${LUA_MODLIBDIR}" INST_LUADIR="${STAGEDIR}${LUA_MODSHAREDIR}"

do-install-DOCS-on:
	mkdir ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
