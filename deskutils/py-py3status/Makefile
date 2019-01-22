# Created by: Martin Wilke
# $FreeBSD$

PORTNAME=	py3status
PORTVERSION=	3.16
CATEGORIES=	deskutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Extensible i3status wrapper written in python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-api-python-client>=0:www/py-google-api-python-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gflags>=0:devel/py-python-gflags@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauth2client>0:security/py-oauth2client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyudev>0:devel/py-pyudev@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	ultrabug
GH_PROJECT=	py3status

NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
