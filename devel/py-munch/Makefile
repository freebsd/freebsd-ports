# $FreeBSD$

PORTNAME=	munch
PORTVERSION=	2.5.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Python dict that provides attribute-style access (a la JavaScript)

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=3.0:devel/py-pbr@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
