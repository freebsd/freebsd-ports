PORTNAME=	lua-language-server
DISTVERSION=	3.5.4
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Sumneko Lua development server and LSP client
WWW=		https://github.com/sumneko/lua-language-server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		lua:build ninja:make
USE_GITHUB=	yes
GH_ACCOUNT=	sumneko
GH_TUPLE=	actboy168:bee.lua:301ad60:bee/3rd/bee.lua \
		actboy168:luamake:db9d087:luamake/3rd/luamake \
		cppcxy:EmmyLuaCodeStyle:f389817:emmyluacodestyle/3rd/EmmyLuaCodeStyle \
		bjornbytes:lovr-docs:a6fc516:lovr/3rd/lovr-api \
		love2d-community:love-api:69e7e01:love/3rd/love-api \
		sqmedeiros:lpeglabel:b5d7638:lpeglabel/3rd/lpeglabel

BINARY_ALIAS=	gcc=${CC}
SUB_FILES=	lua-language-server
PLIST_FILES=	bin/lua-language-server \
		${DATADIR_REL}/bin/lua-language-server \
		${DATADIR_REL}/bin/main.lua \
		${DATADIR_REL}/debugger.lua \
		${DATADIR_REL}/main.lua
PORTDATA=	locale meta script

post-extract:
	${CP} -rp ${WRKSRC}/3rd/bee.lua ${WRKSRC}/3rd/luamake/3rd

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

.include <bsd.port.mk>
