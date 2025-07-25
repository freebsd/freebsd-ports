PORTNAME=	willow
PORTVERSION=	1.11.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper that combines multiple Python image libraries into one API
WWW=		https://willow.wagtail.org/latest/ \
		https://github.com/wagtail/Willow

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7<1.0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filetype>=1.0.10:devel/py-filetype@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	HEIF
OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	PILLOW WAND OPENCV
OPTIONS_DEFAULT=HEIF PILLOW
HEIF_DESC=	HEIF support
OPENCV_DESC=	Use OpenCV as backend
PILLOW_DESC=	Use Pillow as backend
WAND_DESC=	Use Wand as backend

HEIF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow-heif>=0.13.0:graphics/py-pillow-heif@${PY_FLAVOR}
OPENCV_RUN_DEPENDS=	opencv>=0:graphics/opencv
PILLOW_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=11.3.0<12.0.0:graphics/py-pillow@${PY_FLAVOR}
WAND_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wand>=0.6<1.0:graphics/py-wand@${PY_FLAVOR}

.include <bsd.port.mk>
