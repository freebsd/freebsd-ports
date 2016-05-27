# Created by: René Ladan <rene@freebsd.org>
# $FreeBSD$

PORTNAME=	django-rq
PORTVERSION=	0.9.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Provides Django integration for RQ (Redis Queue)

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>=1.5:www/py-django18 \
		${PYTHON_PKGNAMEPREFIX}rq>=0.5.5:devel/py-rq

USE_GITHUB=	yes
GH_ACCOUNT=	ui

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
