# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sanetime
PORTVERSION=	4.2.3
CATEGORIES=	devel python astro
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	A sane date/time Python interface, with Django support

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>=2010:${PORTSDIR}/devel/py-pytz
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}unittest2:${PORTSDIR}/devel/py-unittest2

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Include tools for unit tests
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS:=	${TEST_DEPENDS}
.endif

USE_PYTHON=		2
USE_PYDISTUTILS=	easy_install

regression-test: build
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
