# $FreeBSD$

PORTNAME=	tzlocal
PORTVERSION=	1.1.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	melvyn@magemana.nl
COMMENT=	Returns the tzinfo object for the local timezone

LICENSE=	CC0-1.0

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz

OPTIONS_DEFINE=		TEST
OPTIONS_DEFAULT=	TEST
TEST_DESC=		Run test suite

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.options.mk>

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.if !empty(PORT_OPTIONS:MTEST)
pre-install: regression-test
.endif

.include <bsd.port.mk>
