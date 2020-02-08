# Created by: dpejesh@yahoo.com
# $FreeBSD$

PORTNAME=	tinyrpc
PORTVERSION=	0.9.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	0

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small, modular, transport and protocol neutral RPC library

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# tinyrpc 1.0.0+ requires python 3.0+
PORTSCOUT=	limit:^0\.

OPTIONS_DEFINE=	GEVENT HTTPCLIENT WEBSOCKET WSGI ZEROMQ
OPTIONS_DEFAULT=GEVENT HTTPCLIENT
GEVENT_DESC=	Gevent support
HTTPCLIENT_DESC=HTTP client support
WEBSOCKET_DESC=	WebSocket support
WSGI_DESC=	WSGI support
ZEROMQ_DESC=	ZeroMQ support

GEVENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent@${PY_FLAVOR}
HTTPCLIENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent-websocket>=0:www/py-gevent-websocket@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}websocket-client>=0:www/py-websocket-client@${PY_FLAVOR}
WEBSOCKET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent-websocket>=0:www/py-gevent-websocket@${PY_FLAVOR}
WSGI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR}
ZEROMQ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>=0:net/py-pyzmq@${PY_FLAVOR}

.include <bsd.port.mk>

