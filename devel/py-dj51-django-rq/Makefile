PORTNAME=	django-rq
PORTVERSION=	3.0.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj51-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides Django integration for RQ (Redis Queue)
WWW=		https://github.com/rq/django-rq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Extended support of Django 5.1 ends December 2025, upgrade to the Django 5.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=2025-12-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django51>=3.2:www/py-django51@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=3.5:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=2:devel/py-rq@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj51-django-redis>0:www/py-dj51-django-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq-scheduler>=0:devel/py-rq-scheduler@${PY_FLAVOR} \
		redis-server:databases/redis

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes
TEST_ENV=	PYTHONPATH=.

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*django-rq

OPTIONS_DEFINE=	SENTRY
SENTRY_DESC=	Sentry support

SENTRY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sentry-sdk>=1.0.0:devel/py-sentry-sdk@${PY_FLAVOR}

# https://github.com/rq/django-rq/blob/master/Makefile
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${LOCALBASE}/bin/django-admin test django_rq --settings=django_rq.tests.settings -v2

.include <bsd.port.mk>
