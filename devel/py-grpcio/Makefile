# Created by: vanilla@
# $FreeBSD$

PORTNAME=	grpcio
PORTVERSION=	1.7.0
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	HTTP/2-based RPC framework

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>1:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3:devel/py-protobuf
LIB_DEPENDS=	libcares.so:dns/c-ares

BROKEN_powerpc64=	fails to compile: cpu-ppc64le.c: 'AT_HWCAP2' undeclared

USES=		localbase:ldflags python
USE_PYTHON=	autoplist distutils
CFLAGS+=	-Ithird_party/boringssl/include
LDFLAGS+=	-lcares

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} == "2.7"
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>1:devel/py-enum34 \
		${PYTHON_PKGNAMEPREFIX}futures>=3:devel/py-futures
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/grpc/_cython/cygrpc.so
	${REINPLACE_CMD} -e 's|${PYTHONPREFIX_SITELIBDIR}/\(.*\)/grpcio/grpc/_cython/cygrpc.so|${PYTHONPREFIX_SITELIBDIR}/grpc/_cython/cygrpc.so|g' ${_PYTHONPKGLIST}

.include <bsd.port.post.mk>
