PORTNAME=	face_recognition_models
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	graphics python devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Models used by the face_recognition package
WWW=		https://pypi.org/project/face_recognition_models/

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
