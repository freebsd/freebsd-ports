PORTNAME=	lua-language-server
DISTVERSION=	3.16.0
CATEGORIES=	devel

MAINTAINER=	dave@freedave.net
COMMENT=	Lua development server and LSP client
WWW=		https://luals.github.io

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		dos2unix lua:build ninja:make
DOS2UNIX_REGEX=	.*\.(cpp|h|lua|md|obj)
USE_GITHUB=	yes
GH_ACCOUNT=	LuaLS

# There are (presently) 2 places with subtrees directly:
#	3rd/		github.com/LuaLS/lua-language-server/tree/5f1226d/3rd
#	meta/3rd	github.com/LuaLS/lua-language-server/tree/5f1226d/meta/3rd
# But the 3rd/luamake, github.com/actboy168/luamake/tree/0e90778 brings in its own
# separate copy of bee (not necessarily the same as in `3rd/`) that has to be
# tracked down.
GH_TUPLE=	cppcxy:EmmyLuaCodeStyle:8500f3a:emmyluacodestyle/3rd/EmmyLuaCodeStyle \
		actboy168:bee.lua:dd7853f:bee/3rd/bee.lua \
		actboy168:json.lua:aff2a3d:json/3rd/json.lua \
		love2d-community:love-api:8536392:love/3rd/love-api \
		bjornbytes:lovr-docs:e89c753:lovr/3rd/lovr-api \
		sqmedeiros:lpeglabel:912b0b9:lpeglabel/3rd/lpeglabel \
		actboy168:luamake:0e90778:luamake/3rd/luamake \
		LuaCATS:cocos4.0:c0b2259:cats_cocos40/meta/3rd/Cocos4.0 \
		LuaCATS:defold:05379b4:cats_defold/meta/3rd/Defold \
		LuaCATS:jass:80d85cb:cats_jass/meta/3rd/Jass \
		LuaCATS:openresty:3bec36f:cats_openresty/meta/3rd/OpenResty \
		LuaCATS:bee:c8ce19f:cats_bee/meta/3rd/bee \
		LuaCATS:busted:5ed85d0:cats_busted/meta/3rd/busted \
		LuaCATS:ffi-reflect:e9037ef:cats_ffi_reflect/meta/3rd/ffi-reflect \
		LuaCATS:luafilesystem:9b5cfc1:cats_lfs/meta/3rd/lfs \
		LuaCATS:love2d:98f7684:cats_love2d/meta/3rd/love2d \
		LuaCATS:lovr:3ba215f:cats_lovr/meta/3rd/lovr \
		LuaCATS:luaecs:21192fb:cats_luaecs/meta/3rd/luaecs \
		LuaCATS:luassert:d3528bb:cats_luassert/meta/3rd/luassert \
		LuaCATS:luv:3615eb1:cats_luv/meta/3rd/luv \
		LuaCATS:skynet:afa6717:cats_skynet/meta/3rd/skynet \
		actboy168:bee.lua:f242926:bee_luamake/3rd/luamake/bee.lua

SUB_FILES=	lua-language-server

PLIST_FILES=	bin/lua-language-server \
		${DATADIR_REL}/bin/lua-language-server \
		${DATADIR_REL}/bin/main.lua \
		${DATADIR_REL}/debugger.lua \
		${DATADIR_REL}/main.lua

PORTDATA=	locale meta script

post-patch:
	${REINPLACE_CMD} -e 's|%LOCALBASE%|${LOCALBASE}|' ${WRKSRC}/3rd/bee.lua/compile/common.lua
	${REINPLACE_CMD} -e 's|%INOTIFY%|${_INOTIFY_}|' ${WRKSRC}/3rd/bee.lua/compile/common.lua
	${REINPLACE_CMD} -e 's|%LOCALBASE%|${LOCALBASE}|' ${WRKSRC}/3rd/luamake/compile/ninja/freebsd.ninja
	${REINPLACE_CMD} -e 's|%LINK_INOTIFY%|${_LINK_INOTIFY_}|' ${WRKSRC}/3rd/luamake/compile/ninja/freebsd.ninja
	${REINPLACE_CMD} -e 's|%WRKDIR%|${WRKDIR}|' ${WRKSRC}/3rd/luamake/bee.lua/test/test.lua
	${REINPLACE_CMD} -e 's|%WRKDIR%|${WRKDIR}|' ${WRKSRC}/3rd/bee.lua/test/test.lua

# `luamake all` instead of `luamake rebuild` because there is a flaky test
do-build:
	cd ${WRKSRC}/3rd/luamake && compile/build.sh
	cd ${WRKSRC} && 3rd/luamake/luamake all

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/lua-language-server ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lua-language-server ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/main.lua ${STAGEDIR}${DATADIR}/bin
	${INSTALL_DATA} ${WRKSRC}/debugger.lua ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/main.lua ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "locale meta script" ${STAGEDIR}${DATADIR}

# you may hit https://github.com/LuaLS/lua-language-server/issues/2896
do-test:
	cd ${WRKSRC} && 3rd/luamake/luamake unit-test

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500050
LIB_DEPENDS+=	libinotify.so:devel/libinotify
_INOTIFY_=	links = "inotify",
_LINK_INOTIFY_=	-linotify
.endif

.include <bsd.port.mk>
