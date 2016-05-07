# $FreeBSD$

PORTNAME=	pytools
PORTVERSION=	2016.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Collection of tools for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.0:devel/py-appdirs \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.2.0:devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}six>=1.8.0:devel/py-six

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python

.include <bsd.port.mk>
