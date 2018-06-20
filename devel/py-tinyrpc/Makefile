# Created by: dpejesh@yahoo.com
# $FreeBSD$

PORTNAME=	tinyrpc
PORTVERSION=	0.9.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dpejesh@yahoo.com
COMMENT=	Modular RPC Libray

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>0:devel/py-gevent@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	HTTP WSGI ZEROMQ

OPTIONS_DEFAULT=	HTTP

HTTP_DESC=	HTTP support
WSGI_DESC=	WSGI support
ZEROMQ_DESC=	ZeroMQ support

HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent-websocket>0:www/py-gevent-websocket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
WSGI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug@${PY_FLAVOR}
ZEROMQ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>0:net/py-pyzmq@${PY_FLAVOR}

.include <bsd.port.mk>
