PORTNAME=	kokkos
DISTVERSION=	4.4.00
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ performance portability programming ecosystem
WWW=		https://github.com/kokkos/kokkos

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc # Kokkos assumes a 64-bit build; i.e., 8-byte pointers, but found 4-byte pointers instead

RUN_DEPENDS=	bash:shells/bash

USES=		cmake:testing compiler:c++17-lang shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes
SHEBANG_FILES=	bin/nvcc_wrapper bin/kokkos_launch_compiler

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	Kokkos_ENABLE_TESTS # 2 tests fail, see https://github.com/kokkos/kokkos/issues/5400

LDFLAGS+=	-lexecinfo

TEST_ENV=	OMP_PROC_BIND=false

OPTIONS_DEFINE=		OPENMP SERIAL
OPTIONS_DEFAULT=	OPENMP SERIAL # both choices are assumed by science/nlcglib

OPENMP_CMAKE_BOOL=	Kokkos_ENABLE_OPENMP

SERIAL_DESC=		Enable serial backend
SERIAL_CMAKE_BOOL=	Kokkos_ENABLE_SERIAL

post-install: # workaround for https://github.com/kokkos/kokkos/issues/4983
	${RM} ${STAGEDIR}${PREFIX}/include/CMakeLists.txt

.include <bsd.port.mk>
