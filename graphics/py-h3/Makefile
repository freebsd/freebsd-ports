PORTNAME=	h3
PORTVERSION=	3.7.7
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding of H3 library
WWW=		https://uber.github.io/h3-py/ \
		https://github.com/uber/h3-py

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	h3>=3.7.2:graphics/h3 \
		${PYTHON_PKGNAMEPREFIX}scikit-build>=0:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libh3.so:graphics/h3
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		cmake:indirect localbase:ldflags ninja:build python
USE_PYTHON=	autoplist concurrent cython pep517 pytest

CFLAGS+=	-I${LOCALBASE}/include/h3
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} ${PYTHON_CMD}

OPTIONS_DEFINE=	NUMPY
OPTIONS_DEFAULT=NUMPY
NUMPY_DESC=	NumPy support

NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/src/h3lib/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
