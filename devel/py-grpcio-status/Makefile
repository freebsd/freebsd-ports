PORTNAME=	grpcio-status
PORTVERSION=	1.62.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Status proto mapping for gRPC
WWW=		https://grpc.io/ \
		https://github.com/grpc/grpc/tree/master/src/python/grpcio_status

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}googleapis-common-protos>=1.5.5:devel/py-googleapis-common-protos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=${PORTVERSION}:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.21.6,1:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
