PORTNAME=	grpc-stubs
PORTVERSION=	1.53.0.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mypy stubs for gRPC
WWW=		https://github.com/shabbyrobe/grpc-stubs

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>=0:devel/py-grpcio@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
