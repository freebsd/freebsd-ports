# Created by: Yarema <yds@Necessitu.de>
# $FreeBSD$

PORTNAME=	lsqlite3
PORTVERSION=	0.9.5
CATEGORIES=	databases
MASTER_SITES=	http://Lua.SQLite.org/index.cgi/zip/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_fsl_9y

MAINTAINER=	yds@Necessitu.de
COMMENT=	LuaSQLite3 - a Lua 5.1 to 5.3 wrapper for the SQLite3 library

LICENSE=	MIT

BUILD_DEPENDS=	${NONEXISTENT}:databases/sqlite3:patch

USES=		localbase:ldflags sqlite:3 zip

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SINGLE=	LUA_VERSION
OPTIONS_SINGLE_LUA_VERSION=	LUA51 LUA52 LUA53
OPTIONS_DEFAULT=LUA${LUA_DEFAULT:S/.//}

LUA51_DESC=	Build for Lua 5.1 and LuaJIT
LUA51_USES=	lua:51
LUA52_DESC=	Build for Lua 5.2
LUA52_USES=	lua:52
LUA53_DESC=	Build for Lua 5.3
LUA53_USES=	lua:53

CFLAGS+=	-pedantic -Wall -Qunused-arguments -fPIC -DPIC\
		-std=c99 -fno-strict-aliasing -I${LUA_INCDIR}\
		-DLSQLITE_VERSION=\"${PORTVERSION}\"
LDFLAGS+=	-shared -pthread -lm -L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/lua${LUA_VER_STR}/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/lua${LUA_VER_STR}/${PORTNAME}

pre-configure:
	@${CP} -p `${MAKE} -V WRKSRC -C ${PORTSDIR}/databases/sqlite3`/sqlite3.[ch] ${WRKSRC}

do-build:
	cd ${WRKSRC} &&\
		${CC} ${CFLAGS} ${LDFLAGS} -lsqlite3\
		-o ${PORTNAME}.so ${PORTNAME}.c
	cd ${WRKSRC} &&\
		${CC} ${CFLAGS} ${LDFLAGS}\
		-I. -Dluaopen_lsqlite3=luaopen_lsqlite3complete\
		-o ${PORTNAME}complete.so ${PORTNAME}.c sqlite3.c

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}.so ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}complete.so ${STAGEDIR}${LUA_MODLIBDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.wiki ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HISTORY ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.lua ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
