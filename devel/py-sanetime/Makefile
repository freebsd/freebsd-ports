# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sanetime
PORTVERSION=	4.2.3
PORTREVISION=	1
CATEGORIES=	devel python astro
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Sane date/time Python interface, with Django support

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>=2010:${PORTSDIR}/devel/py-pytz
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}unittest2:${PORTSDIR}/devel/py-unittest2

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Include tools for unit tests

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

.include <bsd.port.options.mk>

regression-test: build
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
