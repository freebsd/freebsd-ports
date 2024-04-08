PORTNAME=	ipyparallel
PORTVERSION=	8.8.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Interactive Parallel Computing with IPython
WWW=		https://ipyparallel.readthedocs.io/en/latest/ \
		https://github.com/ipython/ipyparallel

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0.25:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab>=4.0<5:devel/py-jupyterlab@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>=0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}entrypoints>=0:devel/py-entrypoints@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=4.4:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=4:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-client>=5:devel/py-jupyter-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=18:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=5.1:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.3:devel/py-traitlets@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testpath>=0:devel/py-testpath@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

SHEBANG_GLOB=	*.py

.include <bsd.port.mk>
