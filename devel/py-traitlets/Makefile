# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	traitlets
PORTVERSION=	4.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Configuration system for Python applications

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>=0:devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}ipython_genutils>=0:devel/py-ipython_genutils \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>=0:devel/py-enum34
.endif

.if ${PYTHON_VER} == 2.7
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock
.endif

do-test:
	@(cd ${TEST_WRKSRC} && py.test-${PYTHON_VER} traitlets)

.include <bsd.port.post.mk>
