# Created by: vanilla@
# $FreeBSD$

PORTNAME=	grpcio-tools
PORTVERSION=	1.36.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Protobuf code generator for gRPC

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>1:devel/py-grpcio@${PY_FLAVOR}
LIB_DEPENDS=	libcares.so:dns/c-ares

USES=		compiler:c++11-lang localbase:ldflags python:3.5+
USE_PYTHON=	autoplist distutils
CFLAGS+=	-DHAVE_PTHREAD=1
LDFLAGS+=	-lcares

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/grpc_tools/_protoc_compiler*.so

.include <bsd.port.mk>
