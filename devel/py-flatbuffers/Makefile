PORTNAME=	flatbuffers
PORTVERSION=	2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	FlatBuffers serialization format for Python

LICENSE=	APACHE20

USES=		cpe python:3.7+
USE_PYTHON=	autoplist concurrent distutils

MAKE_ENV=	VERSION=${PORTVERSION}
NO_ARCH=	yes

CPE_VENDOR=	google

OPTIONS_DEFINE=	NUMPY
NUMPY_DESC=	Support scalar vectors as numpy arrays

NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

.include <bsd.port.mk>
