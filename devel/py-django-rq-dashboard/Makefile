# $FreeBSD$

PORTNAME=	django-rq-dashboard
PORTVERSION=	0.3.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Monitor your RQ queues, jobs and workers from the Django admin

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-rq>0:devel/py-django-rq

USE_GITHUB=	yes
GH_ACCOUNT=	brutasse

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
