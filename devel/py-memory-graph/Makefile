PORTNAME=	memory-graph
DISTVERSION=	0.3.65
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	memory_graph-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Teaching tool for debugging references and mutable data types
WWW=		https://github.com/bterwijn/memory_graph

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graphviz>0:graphics/py-graphviz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 0.3.65: 6 passed in 0.74s

.include <bsd.port.mk>
