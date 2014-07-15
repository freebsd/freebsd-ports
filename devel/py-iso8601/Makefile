# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iso8601
PORTVERSION=	0.1.10
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Simple module to parse ISO 8601 dates

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.4.2:${PORTSDIR}/devel/py-pytest

OPTIONS_DEFINE=		TESTS

TESTS_DESC=		Install tools to run test suite
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

regression-test: extract
	@cd ${WRKSRC} && py.test

.include <bsd.port.mk>
