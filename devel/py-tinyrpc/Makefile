# Created by: dpejesh@yahoo.com
# $FreeBSD$

PORTNAME=	tinyrpc
PORTVERSION=	0.5
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dpejesh@yahoo.com
COMMENT=	Modular RPC Libray

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	mbr

USES=		python:2.7
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	HTTP WSGI ZEROMQ

HTTP_DESC=	HTTP support
WSGI_DESC=	WSGI support
ZEROMQ_DESC=	ZeroMQ support

OPTIONS_DEFAULT=HTTP

HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${FLAVOR}
WSGI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>0:devel/py-gevent@${FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug@${FLAVOR}
ZEROMQ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>0:net/py-pyzmq@${FLAVOR}

.include <bsd.port.mk>
