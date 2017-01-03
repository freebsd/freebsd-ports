# Created by: vanilla@
# $FreeBSD$

PORTNAME=	protobuf
PORTVERSION=	3.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google protobuf Python Client Library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.9:devel/py-six \
		protoc:devel/protobuf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.9:devel/py-six

DO_MAKE_TEST=	${PYTHON_CMD} ${PYDISTUTILS_SETUP}
NO_ARCH=	yes
TEST_TARGET=	test
USE_PYTHON=	autoplist distutils
USES=		python
WRKSRC_SUBDIR=	python

GH_ACCOUNT=	google
USE_GITHUB=	yes

post-patch:
	@${MKDIR} ${WRKSRC}/google/protobuf/compiler/

.include <bsd.port.mk>
