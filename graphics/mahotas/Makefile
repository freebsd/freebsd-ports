PORTNAME=	mahotas
PORTVERSION=	1.4.15
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Computer vision and image processing library for Python
WWW=		https://packages.python.org/mahotas/

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libfreeimage.so:graphics/freeimage

USE_GCC=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
