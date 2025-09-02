PORTNAME=	blosc2
PORTVERSION=	3.7.0
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and compressed ndarray library with a flexible compute engine
WWW=		https://www.blosc.org/python-blosc2/ \
		https://github.com/Blosc/python-blosc2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	c-blosc2>=2.19.1:archivers/c-blosc2 \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0:devel/py-scikit-build-core@${PY_FLAVOR}
LIB_DEPENDS=	libblosc2.so:archivers/c-blosc2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ndindex>=0:math/py-ndindex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numexpr>=0:math/py-numexpr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py-cpuinfo>=0:sysutils/py-py-cpuinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		cmake:indirect pkgconfig python:3.10+
USE_PYTHON=	autoplist concurrent cython3 pep517

MAKE_ENV=	USE_SYSTEM_BLOSC2=1

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
