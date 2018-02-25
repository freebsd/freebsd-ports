# Created by: Yuri Victorovich
# $FreeBSD$

PORTNAME=	opuslib
PORTVERSION=	2.0.0
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings to the libopus, IETF low-delay audio codec

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${LOCALBASE}/lib/libopus.so:audio/opus
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=4.4.1:devel/py-coverage \
		${PYTHON_PKGNAMEPREFIX}nose>=1.3.7:devel/py-nose

USES=		python:-2.7
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

# tests are broken: https://github.com/OnBeep/opuslib/issues/4
TEST_TARGET=	test
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYSETUP}

.include <bsd.port.mk>
