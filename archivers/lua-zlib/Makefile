PORTNAME=	zlib
DISTVERSIONPREFIX=v
DISTVERSION=	1.4
CATEGORIES=	archivers
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sirl33tname@gmail.com
COMMENT=	Simple streaming interface to zlib for the Lua Programming Language
WWW=		https://github.com/brimworks/lua-zlib

LICENSE=	MIT

USES=		lua:module
USE_GITHUB=	yes
GH_ACCOUNT=	brimworks
GH_PROJECT=	lua-zlib

MAKE_ENV+=	LUAPATH="${LOCALBASE}"
MAKE_ENV+=	LUACPATH="${STAGEDIR}${LUA_MODLIBDIR}"
MAKE_ENV+=	INCDIR="-I${LUA_INCDIR}"
MAKE_ENV+=	LUALIBDIR="-L${LUA_MODLIBDIR}"
ALL_TARGET=	bsd
LLD_UNSAFE=	yes

CONFLICTS_INSTALL=	${LUA_PKGNAMEPREFIX}lzlib # lib/lua/5.*/zlib.so

DOCSDIR=	${STAGEDIR}/share/doc/${UNIQUENAME}

PLIST_FILES=	${LUA_MODLIBDIR}/zlib.so

pre-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
