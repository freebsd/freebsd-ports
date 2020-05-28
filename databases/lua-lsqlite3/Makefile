# Created by: Yarema <yds@Necessitu.de>
# $FreeBSD$

PORTNAME=	lsqlite3
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://Lua.SQLite.org/index.cgi/zip/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_fsl_9y

MAINTAINER=	yds@Necessitu.de
COMMENT=	Lua 5.1 to 5.3 wrapper for SQLite3 library

LICENSE=	MIT

BUILD_DEPENDS=	${NONEXISTENT}:databases/sqlite3:patch

USES=		localbase:ldflags sqlite:3 zip lua:module

OPTIONS_DEFINE=	DOCS EXAMPLES

CFLAGS+=	-pedantic -Wall -Qunused-arguments -fPIC -DPIC\
		-std=c99 -fno-strict-aliasing -I${LUA_INCDIR}\
		-DLSQLITE_VERSION=\"${PORTVERSION}\"
LDFLAGS+=	-shared -pthread -lm -L${LOCALBASE}/lib

DOCSDIR=	${LUA_DOCSDIR}
EXAMPLESDIR=	${LUA_EXAMPLESDIR}

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
