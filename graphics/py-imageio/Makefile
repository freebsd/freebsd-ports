# $FreeBSD$

PORTNAME=	imageio
PORTVERSION=	2.9.0
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python library for reading and writing image, video formats

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreeimage.so:graphics/freeimage
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		${PYTHON_PKGNAMEPREFIX}imageio-ffmpeg>=0:graphics/py-imageio-ffmpeg@${PY_FLAVOR} \
		${PYNUMPY} \
		${PY_PILLOW}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
