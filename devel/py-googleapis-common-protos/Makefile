# $FreeBSD$

PORTNAME=	googleapis-common-protos
PORTVERSION=	1.52.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Common protobufs used in Google APIs

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=3.6.0,1:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	GRPC
GRPC_DESC=	gRPC support

GRPC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>=1.0.0:devel/py-grpcio@${PY_FLAVOR}

.include <bsd.port.mk>
