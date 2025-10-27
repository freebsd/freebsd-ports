PORTNAME=	python-socketio
PORTVERSION=	5.14.2
CATEGORIES=	devel net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python_socketio-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python implementation of the Socket.IO realtime client and server
WWW=		https://github.com/miguelgrinberg/python-socketio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bidict>=0.21.0:devel/py-bidict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-engineio>=4.11.0:devel/py-python-engineio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ASYNCIO_CLIENT CLIENT
OPTIONS_DEFAULT=ASYNCIO_CLIENT CLIENT
CLIENT_DESC=	Standard client support
ASYNCIO_CLIENT_DESC=	Asynchronous client support

ASYNCIO_CLIENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.4:www/py-aiohttp@${PY_FLAVOR}
CLIENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.21.0:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}websocket-client>=0.54.0:www/py-websocket-client@${PY_FLAVOR}

.include <bsd.port.mk>
