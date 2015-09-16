# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twiggy
PORTVERSION=	0.4.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Twiggy-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Pythonic logger

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils

regression-test: build
	@cd ${WRKSRC} && ${SETENV} TWIGGY_UNDER_TEST=1 \
		${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
