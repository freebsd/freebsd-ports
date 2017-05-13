# $FreeBSD$

PORTNAME=	twilio
PORTVERSION=	6.1.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Python module for communicating with the Twilio API

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httplib2>=0:www/py-httplib2 \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
