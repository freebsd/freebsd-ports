PORTNAME=	libsimdpp
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1-400
DISTVERSIONSUFFIX=	-g9dac213d
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only zero-overhead C++ wrapper of SIMD instructions
WWW=		https://github.com/p12tic/libsimdpp

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	p12tic

NO_BUILD=	yes
NO_ARCH=	yes

TEST_TARGET=	check

PLIST_SUB=	VER="${PORTVERSION:R}"

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/p12tic/libsimdpp/issues/194

PORTSCOUT=	limit:^[v1-9]

.include <bsd.port.mk>
