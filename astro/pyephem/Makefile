# Created by: db
# $FreeBSD$

PORTNAME=	pyephem
PORTVERSION=	3.7.7.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	astro math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Scientific-grade astronomical computations for Python

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ephem==${PORTVERSION}:astro/py-ephem@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
