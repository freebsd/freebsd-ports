# $FreeBSD$

PORTNAME=	luarocks
PORTVERSION=	2.4.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Package manager for Lua modules

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	zip:archivers/zip \
		curl:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	keplerproject

NO_ARCH=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-lua-include=${LUA_INCDIR} \
		--lua-version=${LUA_VER} \
		--with-downloader=curl \
		--versioned-rocks-dir
ALL_TARGET=	build

OPTIONS_DEFINE=	LUAJIT
LUAJIT_DESC=		Use LuaJIT instead of Lua
LUAJIT_BUILD_DEPENDS=	luajit:lang/luajit
LUAJIT_RUN_DEPENDS=	luajit:lang/luajit
LUAJIT_CONFIGURE_ON=	--lua-suffix=jit
LUAJIT_PLIST_SUB=	LUA_VER=${LUA_VER} \
			LUA_MODSHAREDIR=share/lua/${LUA_VER}
LUAJIT_VARS=		LUA_INCDIR=${LOCALBASE}/include/luajit-2.0 \
			LUA_VER=5.1 LUA_PKGNAMEPREFIX=lua51-
LUAJIT_USES_OFF=	lua

post-patch:
# Don't install unprefixed binaries to avoid package conflict with
# luarocks built against different lang/lua* versions
	@${REINPLACE_CMD} '/ln -/d' ${WRKSRC}/Makefile.install.inc

post-build:
# NO_ARCH requires https://bugs.archlinux.org/task/40388
	@${REINPLACE_CMD} -e '/LUAROCKS_UNAME_M/d' \
		${WRKSRC}/src/luarocks/site_config.lua

.include <bsd.port.mk>
