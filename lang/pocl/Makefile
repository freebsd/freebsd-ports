PORTNAME=	pocl
DISTVERSIONPREFIX=	v
DISTVERSION=	7.1
CATEGORIES=	lang

MAINTAINER=	ohartmann@walstatt.org
COMMENT=	POrtable Computing Language (POCL)
WWW=		https://portablecl.org/docs/html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	only tested on ${ONLY_FOR_ARCHS:tW:S/ /, /g}

_BR_DEPENDS=	opencl>=3:devel/opencl \
		spirv-llvm-translator-llvm${LLVM_VERSION}>=${LLVM_VERSION}:devel/spirv-llvm-translator@llvm${LLVM_VERSION} \
		spirv-tools>0:graphics/spirv-tools
BUILD_DEPENDS=	${_BR_DEPENDS}
LIB_DEPENDS=	libhwloc.so:devel/hwloc2 \
		libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	${_BR_DEPENDS}

USES=		cmake:noninja gmake localbase:ldflags ncurses pkgconfig python
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS=	${CMAKE_ARGS_${ARCH}} \
		-DENABLE_HOST_CPU_DEVICES=ON \
		-DENABLE_HOST_CPU_DEVICES_OPENMP=ON \
		-DENABLE_ICD=ON \
		-DENABLE_LATEST_CXX_STD=YES \
		-DENABLE_POCL_BUILDING=OFF \
		-DENABLE_SPIRV=ON \
		-DHAVE_OCL_ICD_30_COMPATIBLE=ON \
		-DHOST_COMPILER_SUPPORTS_FLOAT16:BOOL=OFF \
		-DLLVM_CONFIG_LOCATION=${LOCALBASE}/bin/llvm-config${LLVM_VERSION}/ \
		-DPOCL_ICD_ABSOLUTE_PATH=ON \
		-DPOCL_INSTALL_PKGCONFIG_DIR="${PREFIX}/libdata/pkgconfig" \
		-DWITH_LLVM_CONFIG="${LOCALBASE}/llvm${LLVM_VERSION}/bin/llvm-config"

CMAKE_ARGS_aarch64=	-DLLC_HOST_CPU=cortex-a53
CMAKE_ARGS_powerpc64=	-DLLC_HOST_CPU=ppc64
CMAKE_ARGS_powerpc64le=	-DLLC_HOST_CPU=ppc64le
CMAKE_ARGS_amd64=	-DKERNELLIB_HOST_CPU_VARIANTS=distro

PLIST_SUB=		CONFIGURE_TARGET=${CONFIGURE_TARGET:S/amd64/x86_64/}

OPTIONS_DEFINE=		CONFORMANCE DEBUG DOCS DOCS_PDF LTTNG OMP REMOTE \
			SHARED_LIBS STATIC_LLVM TESTS
OPTIONS_DEFAULT=	LLVM21 OMP SHARED_LIBS TESTS
OPTIONS_SINGLE=		LLVM
OPTIONS_SINGLE_LLVM=	LLVM17 LLVM18 LLVM19 LLVM20 LLVM21 LLVMDEFAULT
OPTIONS_SUB=		yes

CONFORMANCE_DESC=	Conformant pocl build (defaults to OFF)
DEBUG_DESC=		Build POCL with DEBUG messages
DOCS_DESC=		Build documentation (needs textproc/py-sphinx)
DOCS_PDF_DESC=		Build PDF alongside with standard HTML docs
LLVM17_DESC=		Use llvm 17
LLVM18_DESC=		Use llvm 18
LLVM19_DESC=		Use llvm 19
LLVM20_DESC=		Use llvm 20
LLVM21_DESC=		Use llvm 21
LLVMDEFAULT_DESC=	Use default llvm version
LLVM_DESC=		LLVM version to choose
LTTNG_DESC=		Trace both server and client lib with lttng
OMP_DESC=		Enable OpenMP on CPU driver
REMOTE_DESC=		Enable pocld, a remote server (esperimental)
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

LLVM17_USES=		llvm:17,build,lib,run
LLVM18_USES=		llvm:18,build,lib,run
LLVM19_USES=		llvm:19,build,lib,run
LLVM20_USES=		llvm:20,build,lib,run
LLVM21_USES=		llvm:21,build,lib,run
LLVMDEFAULT_USES=	llvm:min=17,max=21,build,lib,run

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
