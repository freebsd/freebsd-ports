PORTNAME=	indiweb
PORTVERSION=	0.1.7
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Simple web application to manage INDI server

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bottle>=0:www/py-bottle@${PY_FLAVOR} \

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
