# Created by: René Ladan <rene@freebsd.org>
# $FreeBSD$

PORTNAME=	django-rq
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides Django integration for RQ (Redis Queue)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=1.8.0:www/py-django111@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=3:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=1.0:devel/py-rq@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		redis-server:databases/redis

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}dj22-django-rq

# django-rq 2.2.0+ requires Django 2.0+
PORTSCOUT=	limit:^2\.1\.

# https://github.com/rq/django-rq/blob/master/Makefile
do-test:
	cd ${WRKSRC} && coverage-${PYTHON_VER} run ${LOCALBASE}/bin/django-admin.py test django_rq --settings=django_rq.tests.settings --pythonpath=.
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py check --metadata --restructuredtext --strict

.include <bsd.port.mk>
