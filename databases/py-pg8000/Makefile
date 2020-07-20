# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pg8000
PORTVERSION=	1.16.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Pure-Python Interface to the PostgreSQL Database

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}passlib>=0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scramp>=0:security/py-scramp@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
