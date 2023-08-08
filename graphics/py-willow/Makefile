PORTNAME=	willow
PORTVERSION=	1.5
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Willow-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper that combines multiple Python image libraries into one API
WWW=		https://github.com/wagtail/Willow

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7<1.0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filetype>=1.0.7:devel/py-filetype@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	PILLOW WAND OPENCV
OPTIONS_DEFAULT=PILLOW
OPENCV_DESC=	Use OpenCV as backend
PILLOW_DESC=	Use Pillow as backend
WAND_DESC=	Use Wand as backend

OPENCV_RUN_DEPENDS=	opencv>=0:graphics/opencv
PILLOW_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR}
WAND_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wand>=0:graphics/py-wand@${PY_FLAVOR}

.include <bsd.port.mk>
