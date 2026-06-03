PORTNAME=	imutils
PORTVERSION=	0.5.4
PORTREVISION=	4
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Series of convenience image processing functions
WWW=		https://github.com/PyImageSearch/imutils

RUN_DEPENDS=	opencv>0:graphics/opencv ${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
