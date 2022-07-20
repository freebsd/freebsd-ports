PORTNAME=	hash_ring
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of consistent hashing in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-memcached>=0:databases/py-python-memcached@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
