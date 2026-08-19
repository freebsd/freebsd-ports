PORTNAME=	grpcio-reflection
PORTVERSION=	1.82.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	grpcio_reflection-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Standard Protobuf Reflection Service for gRPC
WWW=		https://grpc.io/ \
		https://github.com/grpc/grpc/tree/master/src/python/grpcio_reflection

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio-tools>=${PORTVERSION}:devel/py-grpcio-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>=${PORTVERSION}:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=6.33.5,1<8.0.0,1:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
