# Created by: René Ladan <rene@freebsd.org>
# $FreeBSD$

PORTNAME=	django-rq
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Provides Django integration for RQ (Redis Queue)

LICENSE=	MIT

TEST_DEPENDS=	redis-server:databases/redis \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>0:www/py-django111@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=0.5.5:devel/py-rq@${FLAVOR}

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	rq

do-test:
	cd ${WRKSRC} && ${TEST_ENV} ${MAKE} ${TEST_ARGS}

.include <bsd.port.mk>
