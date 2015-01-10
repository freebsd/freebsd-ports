# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asyncio
PORTVERSION=	3.4.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Reference implementation of PEP 3156 (Asynchronous IO)

LICENSE=	APACHE20

USES=		python:3.3+
USE_PYTHON=	distutils autoplist

regression-test: build
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
