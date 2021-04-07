PORTNAME=	onigurumacffi
PORTVERSION=	0.0.21
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Python cffi bindings for the oniguruma regex engine

LIB_DEPENDS=	libonig.so:devel/oniguruma
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=0:devel/py-cffi@${PY_FLAVOR}

USES=		localbase python:3.7+
USE_PYTHON=	autoplist distutils flavors

.include <bsd.port.mk>
