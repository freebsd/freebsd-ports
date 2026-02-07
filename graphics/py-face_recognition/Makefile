PORTNAME=	face_recognition
PORTVERSION=	1.3.0
PORTREVISION=	4
CATEGORIES=	graphics python devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Recognize faces from Python or from the command line
WWW=		https://pypi.org/project/face_recognition/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}face_recognition_models>0:graphics/py-face_recognition_models@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dlib>=19.7:science/py-dlib@${PY_FLAVOR} \
		${PY_PILLOW}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
