# Created by: Trevor Caira <trevor@bitba.se>
# $FreeBSD$
#

PORTNAME=	stripe
PORTVERSION=	1.25.0
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Stripe Python bindings

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0.8.8:${PORTSDIR}/www/py-requests
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycurl>=7.19:${PORTSDIR}/ftp/py-pycurl \
		${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:${PORTSDIR}/devel/py-mock

OPTIONS_DEFINE=	TESTS

TESTS_DESC=		Install test suite requirements
TESTS_BUILD_DEPENDS=	${RUN_DEPENDS} \
			${TEST_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

regression-test: build
	@cd ${WRKSRC} && ${SETENV} SKIP_PYCURL_TESTS=no ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
