# Created by: vanilla@
# $FreeBSD$

PORTNAME=	grpcio
PORTVERSION=	1.36.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	HTTP/2-based RPC framework

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>1:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3:devel/py-protobuf@${PY_FLAVOR}
LIB_DEPENDS=	libcares.so:dns/c-ares

USES=		compiler:c++11-lib localbase:ldflags python:3.6+ ssl
USE_PYTHON=	autoplist distutils
MAKE_ENV+=	GRPC_PYTHON_BUILD_SYSTEM_OPENSSL=true \
		GRPC_PYTHON_BUILD_SYSTEM_ZLIB=true \
		GRPC_PYTHON_BUILD_SYSTEM_CARES=true
LDFLAGS+=	-lcares

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/grpc/_cython/cygrpc*.so
	${REINPLACE_CMD} -e 's|${PYTHONPREFIX_SITELIBDIR}/\(.*\)/grpcio/grpc/_cython/cygrpc${PYTHON_EXT_SUFFIX}.so|${PYTHONPREFIX_SITELIBDIR}/grpc/_cython/cygrpc${PYTHON_EXT_SUFFIX}.so|g' ${_PYTHONPKGLIST}

.include <bsd.port.mk>
