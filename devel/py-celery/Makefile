# Created by: Alexandros Kosiaris <akosiaris+ports@gmail.com>
# $FreeBSD$

PORTNAME=	celery
PORTVERSION=	4.0.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Asynchronous task queue/job queue

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}billiard>=3.3.0.21:devel/py-billiard@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=1.5:devel/py-pytz@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kombu>=3.0.36:net/py-kombu@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-memcached>=0:databases/py-python-memcached@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
