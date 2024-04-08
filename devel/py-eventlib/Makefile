PORTNAME=	eventlib
PORTVERSION=	0.1.5
PORTREVISION=	5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to make it easy to track events in python/django apps
WWW=		https://github.com/Yipit/eventlib

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}celery>=3.0.0:devel/py-celery@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django32>=0:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ejson>=0:devel/py-ejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}logan>=0.5.0:devel/py-logan@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis2>=2.7.1:databases/py-redis2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
