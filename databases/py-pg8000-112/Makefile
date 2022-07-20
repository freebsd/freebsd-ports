PORTNAME=	pg8000
PORTVERSION=	1.12.5
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-112

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Pure-Python Interface to the PostgreSQL Database

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}pg8000 # lib/python3.8/site-packages/pg8000/__init__.py

NO_ARCH=	yes

.include <bsd.port.mk>
