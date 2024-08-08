PORTNAME=	opensycl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.4
CATEGORIES=	lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-backend implementation of SYCL for CPUs and GPUs
WWW=		https://github.com/OpenSYCL/OpenSYCL

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to compile: error: static_assert failed due to requirement 'sizeof(hipsycl::glue::unique_id) == 2 * sizeof(void *)'
BROKEN_FreeBSD_13_armv7=	configure fails: Cannot run simple program using std::filesystem

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake llvm:15 python shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	OpenSYCL
GH_PROJECT=	OpenSYCL

SHEBANG_FILES=	bin/syclcc-clang cmake/syclcc-launcher

.if !exists(/usr/include/omp.h)
USES+=	compiler:gcc-c++11-lib
.else
USES+=	compiler:c++11-lang
.endif

do-test: # many tests fail, see https://github.com/OpenSYCL/OpenSYCL/issues/996
	@cd ${WRKSRC}/tests && \
		mkdir -p build && \
		cd build && \
			${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} \
				-DCMAKE_PREFIX_PATH=${STAGEDIR}${PREFIX} \
				-DOpenSYCL_DIR="${STAGEDIR}${PREFIX}/lib/cmake/OpenSYCL" \
				-DOPENSYCL_TARGETS="omp;hip:gfx801" .. && \
			${SETENV} ${MAKE_ENV} ${MAKE_CMD} && \
			for f in device_compilation_tests rt_tests sycl_tests; do \
				${ECHO} "==> running tests from $$f"; \
				./$${f}; \
			done

.include <bsd.port.mk>
