PORTNAME=	mahotas
PORTVERSION=	1.4.13
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Computer vision and image processing library for Python
WWW=		https://packages.python.org/mahotas/

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libfreeimage.so:graphics/freeimage

USE_GCC=	yes
USES=		python:3.7+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
