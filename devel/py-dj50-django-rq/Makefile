PORTNAME=	django-rq
PORTVERSION=	2.10.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj50-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Provides Django integration for RQ (Redis Queue)
WWW=		https://github.com/rq/django-rq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django50>=3.2:www/py-django50@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=3:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=1.14:devel/py-rq@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj50-django-redis>0:www/py-dj50-django-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq-scheduler>=0:devel/py-rq-scheduler@${PY_FLAVOR} \
		redis-server:databases/redis

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	PYTHONPATH="."

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

# https://github.com/rq/django-rq/blob/master/Makefile
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${LOCALBASE}/bin/django-admin test django_rq --settings=django_rq.tests.settings -v2

.include <bsd.port.mk>
