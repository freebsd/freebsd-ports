# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	typed-ast
PORTVERSION=	1.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast version of Python's ast module with support for PEP484 typed comments #'

LICENSE=	APACHE20 PSFL
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE

USES=		python:3.3+
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/typed_ast/*.so

.include <bsd.port.mk>
