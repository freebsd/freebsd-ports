# $FreeBSD$

PORTNAME=	gdbgui
PORTVERSION=	0.7.8.2
CATEGORIES=	devel lang python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Browser-based frontend/gui for GDB

LICENSE=	CC-BY-NC-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.12.2:www/py-flask@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-SocketIO>=2.9.0:www/py-flask-socketio@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0.21.0:net/py-eventlet@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygdbmi>=0.7.3.3:devel/py-pygdbmi@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypugjs>=4.2.0:devel/py-pypugjs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.2.0:textproc/py-pygments@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>=1.2.2:devel/py-gevent@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	cs01
USES=		python:2.7
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
