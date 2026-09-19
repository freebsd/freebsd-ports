PORTNAME=	memory-graph
DISTVERSION=	0.3.87
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	memory_graph-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Teaching tool for debugging references and mutable data types
WWW=		https://github.com/bterwijn/memory_graph

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graphviz>0:graphics/py-graphviz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} LD_PRELOAD=/lib/libgcc_s.so.1 PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		memory_graph/test_sequence.py \
		memory_graph/test_slicer.py \
		memory_graph/test_slices.py \
		memory_graph/test_slices_iterator.py

# tests as of 0.3.87: 6 passed in 0.39s

.include <bsd.port.mk>
