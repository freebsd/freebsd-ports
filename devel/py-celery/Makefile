# Created by: Alexandros Kosiaris <akosiaris+ports@gmail.com>
# $FreeBSD$

PORTNAME=	celery
PORTVERSION=	3.0.21
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Asynchronous task queue/job queue

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}amqplib>=0:${PORTSDIR}/net/py-amqplib \
		${PYTHON_PKGNAMEPREFIX}billiard>=2.7.3.30:${PORTSDIR}/devel/py-billiard \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}kombu>=2.5.12:${PORTSDIR}/net/py-kombu \
		${PYTHON_PKGNAMEPREFIX}memcached>=0:${PORTSDIR}/databases/py-memcached

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
