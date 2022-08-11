PORTNAME=	pg8000
PORTVERSION=	1.28.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Pure-Python Interface to the PostgreSQL Database

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}passlib>=0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scramp>=0:security/py-scramp@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}pg8000-112 # lib/python3.8/site-packages/pg8000/__init__.py

NO_ARCH=	yes

.include <bsd.port.mk>
