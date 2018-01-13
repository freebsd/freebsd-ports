# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eventlib
PORTVERSION=	0.1.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to make it easy to track events in python/django apps

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}celery>=3.0.0:devel/py-celery@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django111>=0:www/py-django111@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ejson>=0:devel/py-ejson@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}logan>=0.5.0:devel/py-logan@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=2.7.1:databases/py-redis@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>
