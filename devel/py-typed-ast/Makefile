# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	typed-ast
PORTVERSION=	1.4.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	typed_ast-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fork of Python ast modules with type comment support

LICENSE=	APACHE20 PSFL
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/typed_ast/*.so

.include <bsd.port.mk>
