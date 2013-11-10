# Created by: Alexandros Kosiaris <akosiaris+ports@gmail.com>
# $FreeBSD$

PORTNAME=	celery
PORTVERSION=	3.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Asynchronous task queue/job queue

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}amqp>=0:${PORTSDIR}/net/py-amqp \
		${PYTHON_PKGNAMEPREFIX}billiard>=3.3.0.3:${PORTSDIR}/devel/py-billiard \
		${PYTHON_PKGNAMEPREFIX}pytz>=1.5:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}kombu>=3.0.4:${PORTSDIR}/net/py-kombu \
		${PYTHON_PKGNAMEPREFIX}memcached>=0:${PORTSDIR}/databases/py-memcached

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
