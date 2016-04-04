# $FreeBSD$

PORTNAME=	luarocks
PORTVERSION=	2.3.0
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

OPTIONS_GROUP=		BUILD FETCH
BUILD_DESC=		Build backends
OPTIONS_GROUP_BUILD=	CMAKE GMAKE
FETCH_DESC=		Fetch from repositories
OPTIONS_GROUP_FETCH=	CVS GIT HG SVN

CMAKE_DESC=		CMake support
CMAKE_RUN_DEPENDS=	cmake:devel/cmake
GMAKE_DESC=		GNU Make support
GMAKE_RUN_DEPENDS=	gmake:devel/gmake

CVS_DESC=		CVS support
CVS_RUN_DEPENDS=	cvs:devel/cvs-devel
GIT_DESC=		Git support
GIT_RUN_DEPENDS=	git:devel/git
HG_DESC=		Mercurial support
HG_RUN_DEPENDS=		hg:devel/mercurial
SVN_DESC=		Subversion support
SVN_RUN_DEPENDS=	svn:devel/subversion

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
