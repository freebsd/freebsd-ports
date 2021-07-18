# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	h3
PORTVERSION=	3.7.3
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding of H3 library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake \
		h3>=${PORTVERSION:R}:graphics/h3 \
		${PYTHON_PKGNAMEPREFIX}scikit-build>=0:devel/py-scikit-build@${PY_FLAVOR}
LIB_DEPENDS=	libh3.so:graphics/h3
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		localbase:ldflags ninja:build python:3.6+
USE_PYTHON=	autoplist concurrent cython distutils

CFLAGS+=	-I${LOCALBASE}/include/h3

OPTIONS_DEFINE=	NUMPY
OPTIONS_DEFAULT=NUMPY
NUMPY_DESC=	NumPy support

NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

do-test:
	cd ${WRKSRC} && ${SETENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
