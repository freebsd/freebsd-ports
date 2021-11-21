# Created by: René Ladan <rene@freebsd.org>

PORTNAME=	django-rq
PORTVERSION=	2.5.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj31-
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides Django integration for RQ (Redis Queue)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Extended support of Django 3.1 ends December 2021, upgrade to the Django 3.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=	2021-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django31>=2.0:www/py-django31@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=3:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=1.2:devel/py-rq@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0,1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		redis-server:databases/redis

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-rq \
			${PYTHON_PKGNAMEPREFIX}dj32-django-rq

# https://github.com/rq/django-rq/blob/master/Makefile
do-test:
	cd ${WRKSRC} && coverage-${PYTHON_VER} run ${LOCALBASE}/bin/django-admin.py test django_rq --settings=django_rq.tests.settings --pythonpath=.
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py check --metadata --restructuredtext --strict

.include <bsd.port.mk>
