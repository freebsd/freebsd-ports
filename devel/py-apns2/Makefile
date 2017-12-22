# $FreeBSD$

PORTNAME=	apns2
PORTVERSION=	0.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org

COMMENT=	Python client for Apple Push Notification service

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyper>0:www/py-hyper@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>0:www/py-pyjwt@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
