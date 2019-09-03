# $FreeBSD$

PORTNAME=	holidays
PORTVERSION=	0.9.11
CATEGORIES=	devel
MASTER_SITES=	https://files.pythonhosted.org/packages/d0/17/a452275a0b3e811a381137ff6a61649086af4c5bf2a25755f518cc64b39e/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Generate country, province, & state specific holiday sets on the fly

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR}

NO_ARCH=	yes

.include <bsd.port.mk>
