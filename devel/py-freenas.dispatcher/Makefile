# $FreeBSD$

PORTNAME=	freenas.dispatcher
PORTVERSION=	10.2a1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	FreeNAS dispatcher client

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freenas.utils>0:devel/py-freenas.utils@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ws4py>0:www/py-ws4py@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>0:devel/py-gevent@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freenas.utils>0:devel/py-freenas.utils@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
