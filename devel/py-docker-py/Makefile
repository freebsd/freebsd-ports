PORTNAME=	docker-py
PORTVERSION=	1.10.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	API client for docker written in Python

LICENSE=	APACHE20

DEPRECATED=	Use devel/py-docker
EXPIRATION_DATE=	2022-06-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docker-pycreds>=0.2.1:security/py-docker-pycreds@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}requests>=2.5.2:www/py-requests@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}websocket-client>=0.32.0:www/py-websocket-client@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
