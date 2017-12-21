# Created by: vanilla@
# $FreeBSD$

PORTNAME=	protobuf
PORTVERSION=	3.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google protobuf Python Client Library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	protoc:devel/protobuf \
		${PYTHON_PKGNAMEPREFIX}six>=1.9:devel/py-six@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.9:devel/py-six@${FLAVOR}

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
