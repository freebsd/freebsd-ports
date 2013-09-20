# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rauth
PORTVERSION=	0.5.4
CATEGORIES=	devel www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python library for OAuth 1.0/a, 2.0, and Ofly consumers

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.0.0:${PORTSDIR}/www/py-requests

USE_GITHUB=	yes
GH_ACCOUNT=	litl
GH_COMMIT=	af344ef

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Install tools for unit testing
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS:=	${TEST_DEPENDS}
.endif

# Python3 ready
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}nose>=1.2.1:${PORTSDIR}/devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:${PORTSDIR}/devel/py-mock

regression-test: build
	@cd ${WRKSRC} && nosetests

.include <bsd.port.mk>
