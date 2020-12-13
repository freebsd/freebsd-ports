# $FreeBSD$

PORTNAME=	python-socketio
PORTVERSION=	4.6.1
CATEGORIES=	devel python net
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python implementation of the Socket.IO realtime client and server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-engineio>=3.13.0<4:devel/py-python-engineio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
