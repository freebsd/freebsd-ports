# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beignet
DISTVERSION=	1.3.2
DISTVERSIONSUFFIX=	-source
PORTREVISION=	8
CATEGORIES=	lang
MASTER_SITES=	https://01.org/sites/default/files/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Legacy OpenCL implementation for Intel HD (Gen7 to Gen9.5)

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT} \
		opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd \
		libdrm.so:graphics/libdrm
RUN_DEPENDS=	opencl>=0:devel/opencl \
		clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}

WRKSRC=		${WRKDIR}/Beignet-${DISTVERSION}-Source

USES=		cmake gl ncurses pkgconfig shebangfix xorg
USE_XORG=	sm ice x11 xext xfixes
USE_GL=		gl egl
USE_LDCONFIG=	${LOCALBASE}/lib/${PORTNAME}
SHEBANG_FILES=	src/git_sha1.sh backend/kernels/compile.sh
ALL_TARGET=	all

CMAKE_ARGS=	-DCLANG_EXECUTABLE:FILEPATH=${LOCALBASE}/bin/clang${LLVM_DEFAULT} \
		-DLLVM_AS_EXECUTABLE:FILEPATH=${LOCALBASE}/bin/llvm-as${LLVM_DEFAULT} \
		-DLLVM_CONFIG_EXECUTABLE:FILEPATH=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT} \
		-DLLVM_LINK_EXECUTABLE:FILEPATH=${LOCALBASE}/bin/llvm-link${LLVM_DEFAULT}

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	Beignet needs a graphics driver supported by the Intel KMS driver

OPTIONS_DEFINE=	FP64 OCL20 TEST
OPTIONS_DEFAULT=	OCL20
OPTIONS_EXCLUDE_i386=	OCL20
OPTIONS_SUB=	yes

FP64_DESC=	Double precision (experimental)
FP64_CMAKE_BOOL=	EXPERIMENTAL_DOUBLE

OCL20_DESC=	OpenCL 2.0 support
OCL20_CMAKE_BOOL=	ENABLE_OPENCL_20

TEST_ALL_TARGET=	flat_address_space utest_run

post-patch:
	@${REINPLACE_CMD} -e 's|llvm-dis|llvm-dis${LLVM_DEFAULT}|g; \
		s|clang |clang${LLVM_DEFAULT} |g' \
		${WRKSRC}/backend/kernels/compile.sh

# XXX bug 213732: compiler_device_enqueue() Interrupt signal (SIGSEGV) received.
do-test-TEST-on:
	-@(cd ${TEST_WRKSRC}/utests; . ./setenv.sh; \
		./flat_address_space; ./utest_run; )

pre-install-TEST-on: do-test-TEST-on

.include <bsd.port.mk>
