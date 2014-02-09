# Created by: jessekempf@gmail.com
# $FreeBSD$

PORTNAME=	mock
PORTVERSION=	1.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jessekempf@gmail.com
COMMENT=	Mock unit tests for Python

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Install tox for running unit tests

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

TESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tox>0:${PORTSDIR}/devel/py-tox

.include <bsd.port.mk>
