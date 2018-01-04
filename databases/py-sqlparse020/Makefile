# $FreeBSD$

PORTNAME=	sqlparse020
PORTVERSION=	0.2.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sqlparse-${DISTVERSION}

MAINTAINER=	axel.rau@chaos1.de
COMMENT=	Non-validating SQL parser for Python (version 0.2.0)

LICENSE=	BSD3CLAUSE

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}sqlparse ${PYTHON_PKGNAMEPREFIX}sqlparse01

.include <bsd.port.mk>
