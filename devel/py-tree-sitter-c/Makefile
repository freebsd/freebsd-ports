PORTNAME=	tree-sitter-c
DISTVERSION=	0.24.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	tree_sitter_c-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C grammar for tree-sitter
WWW=		https://github.com/tree-sitter/tree-sitter-c

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tree-sitter>0:devel/py-tree-sitter@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
