PORTNAME=	lsqlite3
DISTVERSION=	0.9.6
CATEGORIES=	databases
MASTER_SITES=	https://lua.sqlite.org/home/zip/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_v${DISTVERSION:C/\.//g}

MAINTAINER=	yds@Necessitu.de
COMMENT=	Lua wrapper for SQLite3 library
WWW=		http://Lua.SQLite.org/index.cgi/doc/tip/doc/lsqlite3.wiki

LICENSE=	MIT

BUILD_DEPENDS=	${NONEXISTENT}:databases/sqlite3:build
TEST_DEPENDS=	${LUA_FLAVOR}-lunitx>0:devel/lua-lunitx

USES=		localbase:ldflags sqlite:3 zip lua:module

TEST_TARGET=	test

CFLAGS+=	-pedantic -Wall -Qunused-arguments -fPIC -DPIC\
		-std=c99 -fno-strict-aliasing -I${LUA_INCDIR}\
		-DLSQLITE_VERSION=\"${DISTVERSION}\"
LDFLAGS+=	-shared -pthread -lm -L${LOCALBASE}/lib

DOCSDIR=	${LUA_DOCSDIR}
EXAMPLESDIR=	${LUA_EXAMPLESDIR}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} 's|LUAEXE=.*|LUAEXE= ${LUA_CMD}|' ${WRKSRC}/Makefile

pre-configure:
	@${CP} -p `${SETENV} -u FLAVOR ${MAKE} -V WRKSRC -C ${PORTSDIR}/databases/sqlite3`/sqlite3.[ch] ${WRKSRC}

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
