# Created by: vanilla@
# $FreeBSD$

PORTNAME=	grpcio
PORTVERSION=	1.4.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	HTTP/2-based RPC framework

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>1:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}enum34>1:devel/py-enum34 \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3:devel/py-protobuf
LIB_DEPENDS=	libcares.so:dns/c-ares

BROKEN_aarch64=		fails to compile: cpu-aarch64-linux.c: fatal error: 'sys/auxv.h' file not found
BROKEN_powerpc64=	fails to compile: cpu-ppc64le.c: 'AT_HWCAP2' undeclared

USES=		python
USE_PYTHON=	distutils
CFLAGS+=	-Ithird_party/boringssl/include \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lcares

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/grpc/_cython/cygrpc.so

.include <bsd.port.mk>
