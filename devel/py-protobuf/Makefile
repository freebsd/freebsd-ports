# Created by: vanilla@
# $FreeBSD$

PORTNAME=	protobuf
PORTVERSION=	3.6.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google protobuf Python Client Library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	protoc:devel/protobuf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.9:devel/py-six@${PY_FLAVOR}

DO_MAKE_TEST=	${PYTHON_CMD} ${PYDISTUTILS_SETUP}
NO_ARCH=	yes
TEST_TARGET=	test
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>
