PORTNAME=	array-api-compat
PORTVERSION=	1.12.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/data-apis/array-api-compat/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	array_api_compat-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Array API compatibility library
WWW=		https://data-apis.org/array-api-compat/ \
		https://github.com/data-apis/array-api-compat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DASK NUMPY SPARSE
DASK_DESC=	Dask array support
SPARSE_DESC=	Sparse array support

DASK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dask>=2024.9.0:devel/py-dask@${PY_FLAVOR}
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.22,1:math/py-numpy@${PY_FLAVOR}
SPARSE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sparse>=0.15.1:devel/py-sparse@${PY_FLAVOR}

.include <bsd.port.mk>
