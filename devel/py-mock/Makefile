# Created by: jessekempf@gmail.com
# $FreeBSD$

PORTNAME=	mock
PORTVERSION=	1.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jessekempf@gmail.com
COMMENT=	Mock unit tests for Python

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.3:${PORTSDIR}/devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.3:${PORTSDIR}/devel/py-pbr

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Install tox for running unit tests

USES=		python
USE_PYTHON=	distutils autoplist

TESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tox>0:${PORTSDIR}/devel/py-tox

.include <bsd.port.mk>
