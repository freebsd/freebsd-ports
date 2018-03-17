# $FreeBSD$

PORTNAME=	pytools
PORTVERSION=	2018.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Collection of tools for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.0:devel/py-appdirs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.2.0:devel/py-decorator@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.6.0,1:math/py-numpy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.8.0:devel/py-six@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>
