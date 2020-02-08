# Created by: dpejesh@yahoo.com
# $FreeBSD$

PORTNAME=	tinyrpc
PORTVERSION=	1.0.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small, modular, transport and protocol neutral RPC library

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	GEVENT HTTPCLIENT MSGPACK WEBSOCKET WSGI ZEROMQ
OPTIONS_DEFAULT=GEVENT HTTPCLIENT
GEVENT_DESC=	Gevent support
HTTPCLIENT_DESC=HTTP client support
MSGPACK_DESC=	MessagePack support
WEBSOCKET_DESC=	WebSocket support
WSGI_DESC=	WSGI support
ZEROMQ_DESC=	ZeroMQ support

GEVENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent@${PY_FLAVOR}
HTTPCLIENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent-websocket>=0:www/py-gevent-websocket@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}websocket-client>=0:www/py-websocket-client@${PY_FLAVOR}
MSGPACK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR}
WEBSOCKET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent-websocket>=0:www/py-gevent-websocket@${PY_FLAVOR}
WSGI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR}
ZEROMQ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>=0:net/py-pyzmq@${PY_FLAVOR}

.include <bsd.port.mk>
