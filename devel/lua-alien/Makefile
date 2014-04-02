# Created by: Anonymous
# $FreeBSD$

PORTNAME=	alien
PORTVERSION=	0.5.1
CATEGORIES=	devel
MASTER_SITES=	http://nodeload.github.com/mascarenhas/alien/tarball/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTFILES=	${DISTVERSION}
DIST_SUBDIR=	lua-${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lua -> C FFI

LICENSE=	MIT

LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi

USE_LUA=	5.1

WRKSRC=		${WRKDIR}/${GITHUB_USER}-${PORTNAME}-${GITHUB_SRC_SUFX}
CFLAGS+=	-I${LOCALBASE}/include -I${LUA_INCDIR} \
		-DBSD -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR} -llua -shared
MAKE_ENV+=	LIB_OPTION="${LDFLAGS}" LIB_EXT=".so" LUA="${LUA_CMD}"
TESTS_EXCLUDE=	tests/alien tests/alien.lua

GITHUB_USER=	mascarenhas
GITHUB_SRC_SUFX=e667d5d

.if ${CFLAGS:M-fstack-prot*}
MAKE_ENV+=	__MAKE_CONF= # inherit CFLAGS only once
CFLAGS+=	-fno-stack-protector
.endif

# add lua prefix to directories
.for p in data: docs:doc/ examples:examples/
${p:C/:.*//:U}DIR_REL=	share/${p:C/.*://}${LUA_PKGNAMEPREFIX}${PORTNAME}
${p:C/:.*//:U}DIR=	${PREFIX}/${${p:C/:.*//:U}DIR_REL}
.endfor

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:	.SILENT
	${RM} -rf ${WRKSRC}/libffi
	${FIND} ${WRKSRC} -type f -name .git-darcs-dir -delete

post-patch:	.SILENT
	${REINPLACE_CMD} '1s|.*|#! ${LUA_CMD}|' ${WRKSRC}/src/constants
	${REINPLACE_CMD} -i '' \
		-e 's|/usr/lib|${PREFIX}/lib|' \
		-e '/luarocks/d' \
		${WRKSRC}/samples/*.lua ${WRKSRC}/tests/*.lua

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}/${PORTNAME}
	(cd ${WRKSRC}/src/alien && ${INSTALL_PROGRAM} core.so struct.so \
		${STAGEDIR}${LUA_MODLIBDIR}/${PORTNAME})
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/src/alien.lua ${STAGEDIR}${LUA_MODSHAREDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/constants ${STAGEDIR}${DATADIR}
	${TAR} cf - -C${WRKSRC} ${TESTS_EXCLUDE:S,^,--exclude ,} tests \
		| ${TAR} xof - -C${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

regression-test:	build
	${LN} -fs ${TESTS_EXCLUDE:S,tests/,../src/,} ${WRKSRC}/tests
	cd ${WRKSRC}/tests && ${LUA_CMD} test_alien.lua
	${RM} -f ${TESTS_EXCLUDE:S,^,${WRKSRC}/,}

.include <bsd.port.mk>
