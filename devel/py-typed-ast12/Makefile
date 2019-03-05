# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	typed-ast
PORTVERSION=	1.2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	12

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast version of Python's ast module with support for PEP484 typed comments #'

LICENSE=	APACHE20 PSFL
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE

USES=		python:3.3+
USE_PYTHON=	autoplist distutils

PORTSCOUT=	limit:^1\.2\.

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_ast27.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_ast3.so

.include <bsd.port.mk>
