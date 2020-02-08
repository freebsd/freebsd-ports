# $FreeBSD$

PORTNAME=	luarocks
PORTVERSION=	3.3.1
CATEGORIES=	devel
MASTER_SITES=	https://luarocks.org/releases/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Package manager for Lua modules

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	curl:ftp/curl \
		zip:archivers/zip

USES=		gmake uniquefiles

CONFIGURE_ARGS=	--lua-version=${LUA_VER} \
		--prefix=${PREFIX} \
		--with-lua-include=${LUA_INCDIR}
HAS_CONFIGURE=	yes
NO_ARCH=	yes
UNIQUE_SUFFIX=	${LUA_VER_STR}
UNIQUE_SUFFIX_FILES=	bin/luarocks bin/luarocks-admin

OPTIONS_DEFINE=	LUAJIT
LUAJIT_DESC=	Use LuaJIT instead of Lua

LUAJIT_BUILD_DEPENDS=	luajit:lang/luajit
LUAJIT_RUN_DEPENDS=	luajit:lang/luajit
LUAJIT_CONFIGURE_ON=	--lua-suffix=jit
LUAJIT_PLIST_SUB=	LUA_VER=${LUA_VER} \
			LUA_MODSHAREDIR=share/lua/${LUA_VER}
LUAJIT_VARS=		LUA_INCDIR=${LOCALBASE}/include/luajit-2.0 \
			LUA_PKGNAMEPREFIX=lua51- \
			LUA_VER=5.1
LUAJIT_USES_OFF=	lua

post-patch:
# /usr/local is a mix of site-local data and packages installs.
# If PREFIX/LOCALBASE changes, look for dependencies there as well.
.if defined(PREFIX) && ${PREFIX} != "/usr/local" && ${PREFIX} != "/usr"
	@${REINPLACE_CMD} '/external_deps_dirs/ s|{ |&"${PREFIX}", |' \
		${WRKSRC}/src/luarocks/core/cfg.lua
.endif

post-install:
# Let @sample manage default config
	${MV} ${STAGEDIR}${ETCDIR}/config-${LUA_VER}.lua \
		${STAGEDIR}${ETCDIR}/config-${LUA_VER}.lua.sample

.include <bsd.port.mk>
