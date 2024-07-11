PORTNAME=	zarr
DISTVERSION=	2.18.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of chunked, compressed, N-dimensional arrays for Python
WWW=		https://zarr.readthedocs.io/en/stable/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asciitree>0:graphics/py-asciitree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasteners>0:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numcodecs>=0.10.0:misc/py-numcodecs@${PY_FLAVOR} \
		${PYNUMPY}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fsspec>0:devel/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 7 tests fail, see https://github.com/zarr-developers/zarr-python/issues/1819

NO_ARCH=	yes

.include <bsd.port.mk>
