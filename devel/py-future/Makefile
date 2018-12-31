# Created by: Muhammad Moinur Rahman<5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	future
PORTVERSION=	0.17.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Clean single-source support for Python 3 and 2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
