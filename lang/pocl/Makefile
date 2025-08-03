PORTNAME=	pocl
DISTVERSIONPREFIX=	v
DISTVERSION=	7.0
CATEGORIES=	lang

MAINTAINER=	ohartmann@walstatt.org
COMMENT=	POrtable Computing Language (POCL)
WWW=		https://portablecl.org/docs/html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	only tested on ${ONLY_FOR_ARCHS:tW:S/ /, /g}

BUILD_DEPENDS=	clang${LLVM_VER}:devel/llvm${LLVM_VER} \
		opencl>=3:devel/opencl \
		spirv-llvm-translator-llvm${LLVM_VER}>=${LLVM_VER}:devel/spirv-llvm-translator@llvm${LLVM_VER} \
		spirv-tools>0:graphics/spirv-tools

LIB_DEPENDS=	libhwloc.so:devel/hwloc2 \
		libLLVM-${LLVM_VER}.so:devel/llvm${LLVM_VER} \
		libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	${BUILD_DEPENDS}

USES=		cmake:noninja gmake localbase:ldflags ncurses pkgconfig python
USE_GITHUB=	yes
USE_LDCONFIG=	yes

LLVM_VER=	20
CMAKE_ARGS=	${CMAKE_ARGS_${ARCH}} \
		-DENABLE_HOST_CPU_DEVICES=ON \
		-DENABLE_HOST_CPU_DEVICES_OPENMP=ON \
		-DENABLE_ICD=ON \
		-DENABLE_LATEST_CXX_STD=YES \
		-DENABLE_POCL_BUILDING=OFF \
		-DENABLE_SPIRV=ON \
		-DHAVE_OCL_ICD_30_COMPATIBLE=ON \
		-DHOST_COMPILER_SUPPORTS_FLOAT16:BOOL=OFF \
		-DLLVM_CONFIG_LOCATION=${LOCALBASE}/bin/llvm-config${LLVM_VER}/ \
		-DPOCL_ICD_ABSOLUTE_PATH=ON \
		-DPOCL_INSTALL_PKGCONFIG_DIR="${PREFIX}/libdata/pkgconfig" \
		-DWITH_LLVM_CONFIG="${LOCALBASE}/llvm${LLVM_VER}/bin/llvm-config"

CMAKE_ARGS_aarch64=	-DLLC_HOST_CPU=cortex-a53
CMAKE_ARGS_powerpc64=	-DLLC_HOST_CPU=ppc64
CMAKE_ARGS_powerpc64le=	-DLLC_HOST_CPU=ppc64le
CMAKE_ARGS_amd64=	-DKERNELLIB_HOST_CPU_VARIANTS=distro

PLIST_SUB=	CONFIGURE_TARGET=${CONFIGURE_TARGET:S/amd64/x86_64/}

OPTIONS_DEFINE=		CONFORMANCE DEBUG DOCS DOCS_PDF LTTNG OMP REMOTE \
			SHARED_LIBS STATIC_LLVM TESTS
OPTIONS_DEFAULT=	OMP SHARED_LIBS TESTS
OPTIONS_SUB=		yes

CONFORMANCE_DESC=	Conformant pocl build (defaults to OFF)
DEBUG_DESC=		Build POCL with DEBUG messages
DOCS_DESC=		Build documentation (needs textproc/py-sphinx)
DOCS_PDF_DESC=		Build PDF alongside with standard HTML docs
LTTNG_DESC=		Trace both server and client lib with lttng
OMP_DESC=		Enable OpenMP on CPU driver
REMOTE_DESC=		Enable pocld, a remote server
SHARED_LIBS_DESC=	Build shared libs
STATIC_LLVM_DESC=	Have static libLLVM
TESTS_DESC=		Enable compilation of internal tests

CONFORMANCE_CMAKE_ON=	-DENABLE_CONFORMANCE=ON
CONFORMANCE_CMAKE_OFF=	-DENABLE_CONFORMANCE=OFF

DEBUG_CMAKE_ON=		-DPOCL_DEBUG_MESSAGES=ON
DEBUG_CMAKE_OFF=	-DPOCL_DEBUG_MESSAGES=OFF

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR}
DOCS_CMAKE_ON=		-DENABLE_DOCS=ON
DOCS_CMAKE_OFF=		-DENABLE_DOCS=OFF

DOCS_PDF_IMPLIES=	DOCS
DOCS_PDF_BROKEN=	TeX error: Unicode character ≈ (U+2248) not set up for use with LaTeX.

LTTNG_LIB_DEPENDS=	liblttng-ust.so:sysutils/lttng-ust
LTTNG_CMAKE_ON=		-DENABLE_LTTNG=YES
LTTNG_CMAKE_OFF=	-DENABLE_LTTNG=NO

OMP_CMAKE_ON=	-DENABLE_HOST_CPU_DEVICES_OPENMP=YES
OMP_CMAKE_OFF=	-DENABLE_HOST_CPU_DEVICES_OPENMP=NO

REMOTE_BROKEN=		Not compiling. FreeBSD lacks sockettype AF_VSOCK
REMOTE_CMAKE_ON=	-DENABLE_REMOTE_SERVER=ON
REMOTE_CMAKE_OFF=	-DENABLE_REMOTE_SERVER=OFF

SHARED_LIBS_CMAKE_ON=	-DBUILD_SHARED_LIBS=ON
SHARED_LIBS_CMAKE_OFF=	-DBUILD_SHARED_LIBS=OFF

STATIC_LLVM_CMAKE_ON=	-DSTATIC_LLVM_LLVM=ON
STATIC_LLVM_CMAKE_OFF=	-DSTATIC_LLVM_LLVM=OFF

TESTS_CMAKE_ON=		-DENABLE_TESTS=ON
TESTS_CMAKE_OFF=	-DENABLE_TESTS=OFF

do-build-DOCS-on:
	${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC}/doc/sphinx html dirhtml
do-build-DOCS_PDF-on:
	${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC}/doc/sphinx latex
	${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC}/doc/sphinx/build/latex all-pdf
post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/sphinx/build/html/*.html ${STAGEDIR}${DOCSDIR}/html/
post-install-DOCS_PDF-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/sphinx/build/latex/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64
PLIST_SUB+=	AARCH64="" \
		PPC64="@comment " \
		PPC64LE="@comment " \
		X86="@comment "
.elif ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	AARCH64="@comment " \
		PPC64="@comment " \
		PPC64LE="@comment " \
		X86=""
.elif ${ARCH} == powerpc64
PLIST_SUB+=	AARCH64="@comment " \
		PPC64="" \
		PPC64LE="@comment " \
		X86="@comment "
.else
PLIST_SUB+=	AARCH64="@comment " \
		PPC64="@comment " \
		PPC64LE="" \
		X86="@comment "
.endif

.include <bsd.port.mk>
