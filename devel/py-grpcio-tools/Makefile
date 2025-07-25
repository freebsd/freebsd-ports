PORTNAME=	grpcio-tools
PORTVERSION=	1.74.0
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	grpcio_tools-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Protobuf code generator for gRPC
WWW=		https://pypi.org/project/grpcio-tools/

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>1:devel/py-grpcio@${PY_FLAVOR}
LIB_DEPENDS=	libcares.so:dns/c-ares

USES=		compiler:c++11-lang localbase:ldflags python
USE_PYTHON=	autoplist distutils
CFLAGS+=	-DHAVE_PTHREAD=1
LDFLAGS+=	-lcares

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/grpc_tools/_protoc_compiler*.so

.include <bsd.port.mk>
