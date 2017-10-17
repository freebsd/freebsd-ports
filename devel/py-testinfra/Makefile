# Created by: Sofian Brabez <sbz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	testinfra
PORTVERSION=	1.8.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Testinfra python module Serverspec-like for infrastructure testing

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}six>1.4:devel/py-six

USES=	python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
