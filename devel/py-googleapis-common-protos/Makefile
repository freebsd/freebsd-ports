PORTNAME=	googleapis-common-protos
PORTVERSION=	1.70.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	googleapis_common_protos-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Common protobufs used in Google APIs
WWW=		https://github.com/googleapis/google-cloud-python/tree/main/packages/googleapis-common-protos \
		https://github.com/googleapis/google-cloud-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=4.21.6,1<7.0.0,1:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	GRPC

GRPC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>=1.44.0<2.0.0:devel/py-grpcio@${PY_FLAVOR}

.include <bsd.port.mk>
