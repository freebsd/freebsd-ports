PORTNAME=	tree-sitter-typescript
DISTVERSION=	0.23.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	tree_sitter_typescript-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	TypeScript and TSX grammars for tree-sitter
WWW=		https://github.com/tree-sitter/tree-sitter-typescript

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tree-sitter>0:devel/py-tree-sitter@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

post-patch:
	@${MKDIR} ${WRKSRC}/typescript/src/tree_sitter ${WRKSRC}/tsx/src/tree_sitter
	@${CP} ${FILESDIR}/tree_sitter_parser.h ${WRKSRC}/typescript/src/tree_sitter/parser.h
	@${CP} ${FILESDIR}/tree_sitter_parser.h ${WRKSRC}/tsx/src/tree_sitter/parser.h
	@${MKDIR} ${WRKSRC}/common
	@${CP} ${FILESDIR}/common_scanner.h ${WRKSRC}/common/scanner.h

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
