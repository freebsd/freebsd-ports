PORTNAME=	spyder-kernels
PORTVERSION=	2.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Jupyter kernels for the Spyder console
WWW=		https://github.com/spyder-ide/spyder-kernels

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cloudpickle>0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>0:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipyparallel>0:devel/py-ipyparallel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=7.31.1:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-client>=7.3.4<9:devel/py-jupyter-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=22.1.0:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>0:devel/py-traitlets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wurlitzer>=1.0.3:misc/py-wurlitzer@${PY_FLAVOR}
# 93 passed, 5 skipped, 5 warnings 
# test_django_settings fail if www/djangoXX not installed
TEST_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}codecov>0:devel/py-codecov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cython>0:lang/cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dask>0:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distributed>0:devel/py-distributed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flaky>0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython_genutils>0:devel/py-ipython_genutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-forked>0:devel/py-pytest-forked@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xarray>0:devel/py-xarray@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

.include <bsd.port.mk>
