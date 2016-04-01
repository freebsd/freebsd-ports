# $FreeBSD$

PORTNAME=	freenas.dispatcher
PORTVERSION=	10.2a1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	FreeNAS dispatcher client

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freenas.utils>0:devel/py-freenas.utils
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ws4py>0:www/py-ws4py \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema \
		${PYTHON_PKGNAMEPREFIX}gevent>0:devel/py-gevent \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}freenas.utils>0:devel/py-freenas.utils

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
