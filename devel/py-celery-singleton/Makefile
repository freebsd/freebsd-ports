PORTNAME=	celery-singleton
PORTVERSION=	0.3.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Prevent duplicate celery tasks
WWW=		https://github.com/steinitzu/celery-singleton

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>0:databases/py-redis@${PY_FLAVOR}

USES=		python:run
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
