PORTNAME=	pytype
PORTVERSION=	2023.11.29
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python type inferencer
WWW=		https://google.github.io/pytype/ \
		https://github.com/google/pytype

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ninja:devel/ninja \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.10.1:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=40.8.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	ninja>=1.10.2:devel/ninja \
		${PYTHON_PKGNAMEPREFIX}attrs>=21.4.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlab>=0.8:devel/py-importlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.2:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libcst>=1.0.1:devel/py-libcst@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=0,1:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycnite>=2023.10.11:devel/py-pycnite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydot>=1.4.2:graphics/py-pydot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.8.9:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.2:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.3.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

post-patch:
	@${RM} ${WRKSRC}/pytype/tools/merge_pyi/test_data/parse_error.py

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
