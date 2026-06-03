PORTNAME=	tree-sitter-sql
PORTVERSION=	0.3.11
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	tree_sitter_sql-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tree-sitter Grammar for SQL (Python module)
WWW=		https://github.com/derekstride/tree-sitter-sql

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
