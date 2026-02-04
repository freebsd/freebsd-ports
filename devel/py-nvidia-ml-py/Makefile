PORTNAME=	nvidia_ml_py
PORTVERSION=	13.590.48
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tiga@FreeBSD.org
COMMENT=	Python bindings to the NVIDIA Management Library
WWW=		https://pypi.org/project/nvidia-ml-py/

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
