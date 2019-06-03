# $FreeBSD$

PORTNAME=	flatbuffers
PORTVERSION=	1.11
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	FlatBuffers serialization format for Python

LICENSE=	APACHE20
#LICENSE_FILE=	Not packaged in PyPI sdist

USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	NUMPY

NUMPY_DESC=	Support scalar vectors as numpy arrays

NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

MAKE_ENV+=	VERSION=${PORTVERSION}

NO_ARCH=	yes

.include <bsd.port.mk>
