PORTNAME=	zarr
PORTVERSION=	2.13.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of chunked, compressed, N-dimensional arrays for Python
WWW=		https://zarr.readthedocs.io/en/stable/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asciitree>0:graphics/py-asciitree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasteners>0:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numcodecs>=0.10.0:misc/py-numcodecs@${PY_FLAVOR} \
		${PYNUMPY}

USES=		python:3.8+
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
