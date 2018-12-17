# Created by: vanilla@
# $FreeBSD$

PORTNAME=	grpcio
PORTVERSION=	1.17.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	HTTP/2-based RPC framework

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>1:devel/py-six@${PY_FLAVOR} \
		${PY_ENUM34} \
		${PY_FUTURES} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3:devel/py-protobuf@${PY_FLAVOR}
LIB_DEPENDS=	libcares.so:dns/c-ares

BROKEN_powerpc64=	fails to compile: cpu-ppc64le.c: 'AT_HWCAP2' undeclared

USES=		compiler:gcc-c++11-lib localbase:ldflags python
USE_PYTHON=	autoplist distutils
MAKE_ENV+=	GRPC_PYTHON_BUILD_SYSTEM_ZLIB=true \
		GRPC_PYTHON_BUILD_SYSTEM_CARES=true
CFLAGS+=	-Ithird_party/boringssl/include
LDFLAGS+=	-lcares

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/grpc/_cython/cygrpc.so
	${REINPLACE_CMD} -e 's|${PYTHONPREFIX_SITELIBDIR}/\(.*\)/grpcio/grpc/_cython/cygrpc.so|${PYTHONPREFIX_SITELIBDIR}/grpc/_cython/cygrpc.so|g' ${_PYTHONPKGLIST}

.include <bsd.port.mk>
