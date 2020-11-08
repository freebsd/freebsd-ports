# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	more-itertools
PORTVERSION=	8.6.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	More routines for operating on iterables, beyond itertools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
