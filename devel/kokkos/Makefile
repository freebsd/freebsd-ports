PORTNAME=	kokkos
DISTVERSION=	4.5.01
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ performance portability programming ecosystem
WWW=		https://kokkos.org/ \
		https://github.com/kokkos/kokkos

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

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
OPTIONS_DEFAULT=	SERIAL # both choices are assumed by science/nlcglib
.if exists(/usr/include/omp.h)
OPTIONS_DEFAULT+=	OPENMP
.endif

OPENMP_CMAKE_BOOL=	Kokkos_ENABLE_OPENMP

SERIAL_DESC=		Enable serial backend
SERIAL_CMAKE_BOOL=	Kokkos_ENABLE_SERIAL

post-install: # workaround for https://github.com/kokkos/kokkos/issues/4983
	${RM} ${STAGEDIR}${PREFIX}/include/CMakeLists.txt

.include <bsd.port.mk>
