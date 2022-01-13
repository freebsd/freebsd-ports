# Created by: Sir l33tname <sirl33tname@gmail.com>

PORTNAME=	zlib
PORTVERSION=	1.2
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	archivers
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sirl33tname@gmail.com
COMMENT=	Simple streaming interface to zlib for the Lua Programming Language

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	brimworks
GH_PROJECT=	lua-zlib

USES=		lua:51,module

CONFLICTS_INSTALL=	${LUA_PKGNAMEPREFIX}lzlib # lib/lua/5.1/zlib.so

ALL_TARGET=	bsd
MAKE_ENV+=	LUAPATH="${LOCALBASE}"
MAKE_ENV+=	LUACPATH="${STAGEDIR}${LUA_MODLIBDIR}"
MAKE_ENV+=	INCDIR="-I${LUA_INCDIR}"
MAKE_ENV+=	LUALIBDIR="-L${LUA_MODLIBDIR}"
LLD_UNSAFE=	yes

PLIST_FILES=	${LUA_MODLIBDIR}/zlib.so

DOCSDIR=	${STAGEDIR}/share/doc/${UNIQUENAME}

pre-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
