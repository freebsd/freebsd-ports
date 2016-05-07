# $FreeBSD$

PORTNAME=	apscheduler
PORTVERSION=	3.0.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	APScheduler-${DISTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	In-process task scheduler with Cron-like capabilities

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}tzlocal>0:devel/py-tzlocal

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	TEST

TEST_BUILD_DEPENDS=${PYTHON_PKGNAMEPREFIX}pytest>=2.5.1:devel/py-pytest
TEST_MAKE_ENV=	TZ=UTC
PYDISTUTILS_TEST_TARGET?=	test

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTEST} && ${PYTHON_REL} < 3300
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock
.endif

.if ${PYTHON_REL} < 3200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}futures>0:devel/py-futures
.endif

pre-install-TEST-on:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_TEST_TARGET} ${PYDISTUTILS_TESTARGS})

.include <bsd.port.post.mk>
