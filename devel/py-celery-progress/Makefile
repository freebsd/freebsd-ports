PORTNAME=	celery-progress
PORTVERSION=	0.1.1
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gettoknowmi@yahoo.com
COMMENT=	Distributed Task Queue
WWW=		https://github.com/celery/celery/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS+=	redis>0:databases/redis \
		rabbitmq>0:net/rabbitmq \
		${PYTHON_PKGNAMEPREFIX}celery>0:devel/py-celery@${PY_FLAVOR} \
		websocat>0:www/websocat

USES=		python:run
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
