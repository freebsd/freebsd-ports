# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	omnijson
PORTVERSION=	0.1.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Wraps the best Python JSON installed

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest

OPTIONS_DEFINE=	TESTS

TESTS_DESC=		Install tools required to run unit tests
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	kennethreitz

USES=		python
USE_PYTHON=	distutils autoplist

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
