# New ports collection makefile for:	lua-alien
# Date created:				24 Aug 2010
# Whom:					Anonymous
#
# $FreeBSD$
#

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

LIB_DEPENDS=	ffi:${PORTSDIR}/devel/libffi

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
	${MKDIR} ${LUA_MODLIBDIR}/${PORTNAME}
.for f in core.so struct.so
	${INSTALL_PROGRAM} ${WRKSRC}/src/alien/${f} \
		${LUA_MODLIBDIR}/${PORTNAME}
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/alien.lua ${LUA_MODSHAREDIR}
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/constants ${DATADIR}
	${TAR} cf - -C${WRKSRC} ${TESTS_EXCLUDE:S,^,--exclude ,} tests \
		| ${TAR} xof - -C${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${TAR} cf - -C${WRKSRC}/doc . | ${TAR} xof - -C${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${TAR} cf - -C${WRKSRC}/samples . | ${TAR} xof - -C${EXAMPLESDIR}
.endif

regression-test:	build
	${LN} -fs ${TESTS_EXCLUDE:S,tests/,../src/,} ${WRKSRC}/tests
	cd ${WRKSRC}/tests && ${LUA_CMD} test_alien.lua
	${RM} -f ${TESTS_EXCLUDE:S,^,${WRKSRC}/,}

.include <bsd.port.mk>
