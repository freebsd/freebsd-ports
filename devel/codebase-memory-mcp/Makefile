PORTNAME=	codebase-memory-mcp
DISTVERSIONPREFIX=v
DISTVERSION=	0.10.8
CATEGORIES=	devel

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	MCP server that indexes codebases into a persistent knowledge graph
WWW=		https://github.com/DeusData/codebase-memory-mcp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	DeusData

# Assumes a 64-bit size_t; fails to build on 32-bit archs
ONLY_FOR_ARCHS=	aarch64 amd64

PLIST_FILES=	bin/codebase-memory-mcp
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_FILES+=	${DOCSDIR_REL}/freebsd-src.cbmignore
.endif

# FreeBSD sysctl OID-tree extractor: two source files added by the port (wired
# into Makefile.cbm and the pipeline via patches). Not shippable as patches
# because patch(1) cannot create new files.
post-extract:
	${CP} ${FILESDIR}/extract_sysctl.c ${WRKSRC}/internal/cbm/extract_sysctl.c
	${CP} ${FILESDIR}/pass_sysctl.c ${WRKSRC}/src/pipeline/pass_sysctl.c

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} \
		${GMAKE} -f Makefile.cbm cbm \
		CC="${CC}" CXX="${CXX}" \
		CFLAGS_EXTRA='-DCBM_VERSION=\"${DISTVERSION}\" -DCBM_PKG_PREFIX=\"${PREFIX}\"'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/c/codebase-memory-mcp \
		${STAGEDIR}${PREFIX}/bin/codebase-memory-mcp

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/freebsd-src.cbmignore ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
