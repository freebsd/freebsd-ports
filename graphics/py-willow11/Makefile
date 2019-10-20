# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	willow
PORTVERSION=	1.1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	11
DISTNAME=	Willow-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper that combines multiple Python image libraries into one API

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.1\.

OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	PILLOW WAND OPENCV
OPTIONS_DEFAULT=PILLOW
OPENCV_DESC=	Use OpenCV as backend
PILLOW_DESC=	Use Pillow as backend
WAND_DESC=	Use Wand as backend

OPENCV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opencv>=0:graphics/py-opencv@${PY_FLAVOR}
PILLOW_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR}
WAND_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wand>=0:graphics/py-wand@${PY_FLAVOR}

.include <bsd.port.mk>
