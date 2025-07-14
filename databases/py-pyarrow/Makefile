PORTNAME=	pyarrow
PORTVERSION=	20.0.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python library for Apache Arrow
WWW=		https://arrow.apache.org/ \
		https://github.com/apache/arrow/tree/main/python

LICENSE=	APACHE20

BUILD_DEPENDS=	arrow>=${PORTVERSION}<${PORTVERSION}_99:databases/arrow \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.25,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libarrow.so:databases/arrow

USES=		cmake:indirect python:3.9+ shebangfix
USE_PYTHON=	autoplist concurrent cython3 pep517

SHEBANG_FILES=	cmake_modules/aws_sdk_cpp_generate_variables.sh

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
