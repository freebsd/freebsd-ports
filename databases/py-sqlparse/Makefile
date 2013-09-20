# Created by: Roland van Laar <roland@micite.net>
# $FreeBSD$

PORTNAME=	sqlparse
PORTVERSION=	0.1.2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	roland@micite.net
COMMENT=	A non-validating SQL parser for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|distutils.core|setuptools|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
