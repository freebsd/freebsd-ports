# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pycparser
PORTVERSION=	2.20
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C parser in Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# README says 2.7+, 3.4, 3.5+
# TravisCI tests 2.6, 2.7, 3.2, 3.4, 3.5
# https://travis-ci.org/eliben/pycparser
# Go with the most accurate without missing any
USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} tests/all_tests.py

.include <bsd.port.mk>
