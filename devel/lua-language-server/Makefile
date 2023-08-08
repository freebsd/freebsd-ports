PORTNAME=	lua-language-server
DISTVERSION=	3.6.9
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Lua development server and LSP client
WWW=		https://github.com/luals/lua-language-server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Versions after 3.6.9 dump core (and do not compile)
EXPIRATION_DATE=2023-08-15

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		compiler:features dos2unix lua:build ninja:make
USE_GITHUB=	yes
GH_ACCOUNT=	luals
GH_TUPLE=	actboy168:bee.lua:c4e989a:bee/3rd/bee.lua \
		actboy168:bee.lua:eff9325:bee_luamake/3rd/luamake/3rd/bee.lua \
		actboy168:json.lua:b5f5e7b:json/3rd/json.lua \
		actboy168:luamake:3d8d1fd:luamake/3rd/luamake \
		cppcxy:EmmyLuaCodeStyle:66eeece:emmyluacodestyle/3rd/EmmyLuaCodeStyle \
		bjornbytes:lovr-docs:8900d79:lovr/3rd/lovr-api \
		love2d-community:love-api:495ecc7:love/3rd/love-api \
		sqmedeiros:lpeglabel:e25eb35:lpeglabel/3rd/lpeglabel

BINARY_ALIAS=	gcc=${CC}
DOS2UNIX_FILES=	3rd/bee.lua/bee/thread/spinlock.h \
		3rd/luamake/3rd/bee.lua/bee/thread/spinlock.h
SUB_FILES=	lua-language-server
PLIST_FILES=	bin/lua-language-server \
		${DATADIR_REL}/bin/lua-language-server \
		${DATADIR_REL}/bin/main.lua \
		${DATADIR_REL}/debugger.lua \
		${DATADIR_REL}/main.lua
PORTDATA=	locale meta script

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 130
BUILD_DEPENDS+=	llvm13>0:devel/llvm13
CPP=		${LOCALBASE}/bin/clang-cpp13
CC=		${LOCALBASE}/bin/clang13
CXX=		${LOCALBASE}/bin/clang++13
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%CC%%|${CC}|; s|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/3rd/luamake/compile/ninja/freebsd.ninja \
		${WRKSRC}/3rd/bee.lua/compile/common.lua

do-build:
	${DO_MAKE_BUILD} -C ${WRKSRC}/3rd/luamake -f compile/ninja/freebsd.ninja
	cd ${WRKSRC} && ${MAKE_ENV} ./3rd/luamake/luamake -v

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/lua-language-server ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lua-language-server ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/main.lua ${STAGEDIR}${DATADIR}/bin
	${INSTALL_DATA} ${WRKSRC}/debugger.lua ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/main.lua ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "locale meta script" ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
