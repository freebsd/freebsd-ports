# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beignet
PORTVERSION=	1.1.2
CATEGORIES=	lang
MASTER_SITES=	https://01.org/sites/default/files/
DISTVERSIONSUFFIX=	-source

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenCL library for Intel GPUs

BUILD_DEPENDS=	clang${LLVMVER}:devel/llvm${LLVMVER} \
		opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd \
		libdrm.so:graphics/libdrm
RUN_DEPENDS=	opencl>=0:devel/opencl \
		clang${LLVMVER}:devel/llvm${LLVMVER}

WRKSRC=		${WRKDIR}/Beignet-${PORTVERSION}-Source

USES=		cmake gmake pkgconfig shebangfix
USE_XORG=	sm ice x11 xext xfixes
USE_GL=		gl
SHEBANG_FILES=	src/git_sha1.sh backend/kernels/compile.sh
LLVMVER=	37

CMAKE_ARGS+=	-DLLVM_CONFIG_EXECUTABLE=${LOCALBASE}/bin/llvm-config${LLVMVER}

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON= Beignet needs a graphics driver supported by the Intel KMS driver

BROKEN_FreeBSD_9=	Beignet is only supported on FreeBSD 10.1 and newer

# running tests from makefile doesn't work quite yet, so comment them out for now.
#OPTIONS_DEFINE=	TESTS
#TESTS_DESC=	Build and run the test suite

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000 && ${OSVERSION} < 1002000
BROKEN=		Beignet needs FreeBSD 10.2 or newer due to too old libc++ in 10.1-Release
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|llvm-dis|llvm-dis${LLVMVER}|g; \
		s|clang |clang${LLVMVER} |g' \
		${WRKSRC}/backend/kernels/compile.sh
#post-patch-TESTS-off:
	@${REINPLACE_CMD} -e 's|ADD_SUBDIRECTORY(utests)||g' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${RM} -rf ${STAGEDIR}${PREFIX}/include/CL

#post-install-TESTS-on:
#	@cd ${WRKSRC}/utests && sh ./setenv.sh && ./utest_run

.include <bsd.port.mk>
