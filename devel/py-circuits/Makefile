# Created by: Kubilay Kocak <koobs.freebsd@gmail.com>
# $FreeBSD$

PORTNAME=	circuits
PORTVERSION=	2.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Asynchronous Component-based Event Application Framework

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:${PORTSDIR}/devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}pygments>0:${PORTSDIR}/textproc/py-pygments

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Install tools for unit tests
# Bypass ports infrastructure bug
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS:=	${TEST_DEPENDS}
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
