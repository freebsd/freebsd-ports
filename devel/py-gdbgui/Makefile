# $FreeBSD$

PORTNAME=	gdbgui
PORTVERSION=	0.7.7.0
CATEGORIES=	devel lang python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Browser-based frontend/gui for GDB

LICENSE=	CC-BY-NC-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.12:www/py-flask \
		${PYTHON_PKGNAMEPREFIX}Flask-SocketIO>=2.8.4:www/py-flask-socketio \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0.20.1:net/py-eventlet \
		${PYTHON_PKGNAMEPREFIX}pygdbmi>=0.7.3.3:devel/py-pygdbmi \
		${PYTHON_PKGNAMEPREFIX}pypugjs>=4.2.0:devel/py-pypugjs \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.2.0:textproc/py-pygments

USE_GITHUB=	yes
GH_ACCOUNT=	cs01
USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
