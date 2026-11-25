PORTNAME=	celery-progress
DISTVERSION=	0.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	celery_progress-${DISTVERSION}

MAINTAINER=	gettoknowmi@yahoo.com
COMMENT=	Drop in, configurable progress bars for Django/Celery applications
WWW=		https://github.com/czue/celery-progress

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=40.6.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}celery>0:devel/py-celery@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		REDIS WEBSOCKETS
OPTIONS_DEFAULT=	WEBSOCKETS

REDIS_DESC=		Redis channel layer for websocket progress
WEBSOCKETS_DESC=	Websocket progress via Django Channels

REDIS_IMPLIES=		WEBSOCKETS
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}channels-redis>0:www/py-channels-redis@${PY_FLAVOR}
WEBSOCKETS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}channels>0:www/py-channels@${PY_FLAVOR}

.include <bsd.port.mk>
