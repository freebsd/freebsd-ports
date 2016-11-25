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
GH_PROJECT=	tinyrpc
GH_TAGNAME=	0.5

USES=		python:2
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	HTTP WSGI ZEROMQ

HTTP_DESC=	HTTP support
WSGI_DESC=	WSGI support
ZEROMQ_DESC=	ZeroMQ support

OPTIONS_DEFAULT=HTTP

HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests
WSGI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}werkzeug>0:${PORTSDIR}/www/py-gevent \
			${PYTHON_PKGNAMEPREFIX}gevent>0:${PORTSDIR}/devel/py-werkzeug
ZEROMQ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>0:${PORTSDIR}/net/py-pyzmq

.include <bsd.port.mk>
