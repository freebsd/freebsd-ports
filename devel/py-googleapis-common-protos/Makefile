PORTNAME=	googleapis-common-protos
PORTVERSION=	1.62.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Common protobufs used in Google APIs
WWW=		https://github.com/googleapis/python-api-common-protos

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=4.21.6,1<5.0.0,1:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	GRPC

GRPC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>=1.44.0<2.0.0:devel/py-grpcio@${PY_FLAVOR}

.include <bsd.port.mk>
