PORTNAME=	codebase-memory-mcp
DISTVERSIONPREFIX=v
DISTVERSION=	0.9.0
CATEGORIES=	devel

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	MCP server that indexes codebases into a persistent knowledge graph
WWW=		https://github.com/DeusData/codebase-memory-mcp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	DeusData

PLIST_FILES=	bin/codebase-memory-mcp
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_FILES+=	${DOCSDIR_REL}/freebsd-src.cbmignore
.endif

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} \
		${GMAKE} -f Makefile.cbm cbm \
		CC="${CC}" CXX="${CXX}" \
		CFLAGS_EXTRA='-DCBM_VERSION=\"${DISTVERSION}\" -DCBM_PACKAGE_MANAGED'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/c/codebase-memory-mcp \
		${STAGEDIR}${PREFIX}/bin/codebase-memory-mcp

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/freebsd-src.cbmignore ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
