PORTNAME=	flatbuffers
PORTVERSION=	23.5.9
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	FlatBuffers serialization format for Python
WWW=		https://google.github.io/flatbuffers/ \
		https://github.com/google/flatbuffers

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CPE_VENDOR=	google

OPTIONS_DEFINE=	NUMPY
NUMPY_DESC=	Support scalar vectors as numpy arrays

NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

.include <bsd.port.mk>
