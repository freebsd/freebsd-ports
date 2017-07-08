# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beignet
PORTVERSION=	1.3.1
PORTREVISION=	1
DISTVERSIONSUFFIX=	-source
CATEGORIES=	lang
MASTER_SITES=	https://01.org/sites/default/files/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenCL library for Intel GPUs

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	clang${LLVMVER}:devel/llvm${LLVMVER} \
		opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd \
		libdrm.so:graphics/libdrm
RUN_DEPENDS=	opencl>=0:devel/opencl \
		clang${LLVMVER}:devel/llvm${LLVMVER}

WRKSRC=		${WRKDIR}/Beignet-${PORTVERSION}-Source

USES=		cmake ncurses pkgconfig shebangfix
USE_XORG=	sm ice x11 xext xfixes
USE_GL=		gl egl
USE_LDCONFIG=	${LOCALBASE}/lib/${PORTNAME}
SHEBANG_FILES=	src/git_sha1.sh backend/kernels/compile.sh
ALL_TARGET=	all
LLVMVER=	${MESA_LLVM_VER:U39}

CMAKE_ARGS+=	-DLLVM_CONFIG_EXECUTABLE=${LOCALBASE}/bin/llvm-config${LLVMVER}

PLIST_SUB=	OCL20=${"${ARCH:Mamd64}" != "":?"":"@comment "}

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	Beignet needs a graphics driver supported by the Intel KMS driver

OPTIONS_DEFINE=	FP64 TEST
FP64_DESC=	Double precision (experimental)

FP64_CMAKE_BOOL=	EXPERIMENTAL_DOUBLE
TEST_ALL_TARGET=	flat_address_space utest_run

post-patch:
	@${REINPLACE_CMD} -e 's|llvm-dis|llvm-dis${LLVMVER}|g; \
		s|clang |clang${LLVMVER} |g' \
		${WRKSRC}/backend/kernels/compile.sh

# XXX bug 213732: compiler_fill_gl_image() [FAILED]
do-test-TEST-on:
	-@(cd ${TEST_WRKSRC}/utests; . ./setenv.sh; \
		./flat_address_space; ./utest_run; )

pre-install-TEST-on: do-test-TEST-on

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/include/CL

.include <bsd.port.mk>
