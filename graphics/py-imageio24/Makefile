# $FreeBSD$

PORTNAME=	imageio
DISTVERSION=	2.4.1
PORTREVISION=	5
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	24

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python library for reading and writing image, video formats

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreeimage.so:graphics/freeimage
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		${PY_ENUM34} \
		${PY_FUTURES} \
		${PY_PILLOW} \
		${PYNUMPY}

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.4\.

.include <bsd.port.mk>
