PORTNAME=	dm-tree
DISTVERSION=	0.1.10
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for working with nested data structures
WWW=		https://tree.readthedocs.io/en/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}
LIB_DEPENDS=	libabsl_strings.so:devel/abseil

USES=		localbase python
USE_PYTHON=	pep517 autoplist concurrent pytest

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}absl-py>=0.6.1:devel/py-absl-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=18.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.11.2:devel/py-wrapt@${PY_FLAVOR}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/tree

# tests as of 0.1.10: 70 passed

.include <bsd.port.mk>
