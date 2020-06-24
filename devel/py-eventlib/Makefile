# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eventlib
PORTVERSION=	0.1.5
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to make it easy to track events in python/django apps

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}celery>=3.0.0:devel/py-celery@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django22>=0:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ejson>=0:devel/py-ejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}logan>=0.5.0:devel/py-logan@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis2>=2.7.1:databases/py-redis2@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
