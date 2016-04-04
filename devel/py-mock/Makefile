# Created by: jessekempf@gmail.com
# $FreeBSD$

PORTNAME=	mock
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jessekempf@gmail.com
COMMENT=	Mock unit tests for Python

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.3:devel/py-pbr \
		${PYTHON_PKGNAMEPREFIX}setuptools${PYTHON_SUFFIX}>0:devel/py-setuptools${PYTHON_SUFFIX}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.3:devel/py-pbr \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six
TESTS_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=  ${PYTHON_PKGNAMEPREFIX}funcsigs>=0:devel/py-funcsigs
.endif

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
