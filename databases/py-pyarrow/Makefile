PORTNAME=	pyarrow
PORTVERSION=	15.0.2
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python library for Apache Arrow
WWW=		https://arrow.apache.org/ \
		https://github.com/apache/arrow/tree/main/python

LICENSE=	APACHE20

BUILD_DEPENDS=	arrow>=${PORTVERSION}<${PORTVERSION}_99:databases/arrow \
		cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}numpy>=0.14,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=40.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libarrow.so:databases/arrow
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16.6,1<2,1:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
