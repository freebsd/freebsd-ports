# Created by: Roland van Laar <roland@micite.net>
# $FreeBSD$

PORTNAME=	sqlparse
PORTVERSION=	0.2.4
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Non-validating SQL parser for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}sqlparse020

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
