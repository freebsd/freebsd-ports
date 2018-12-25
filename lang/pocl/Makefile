# $FreeBSD$

PORTNAME=	pocl
PORTVERSION=	0.14
CATEGORIES=	lang
MASTER_SITES=	SF/pocl \
		http://portablecl.org/downloads/

MAINTAINER=	ohartman@zedat.fu-berlin.de
COMMENT=	POrtable Computing Language (POCL)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	only tested on x86

BUILD_DEPENDS=	llvm${LLVM_VERSION}>=0:devel/llvm${LLVM_VERSION} \
		opencl>=2.1:devel/opencl
LIB_DEPENDS=	libhwloc.so:devel/hwloc \
		libOpenCL.so:devel/ocl-icd \
		libltdl.so:devel/libltdl
RUN_DEPENDS=	llvm${LLVM_VERSION}>=0:devel/llvm${LLVM_VERSION}

LLVM_VERSION=	${MESA_LLVM_VER:U40}

USES=		cmake localbase:ldflags ncurses pkgconfig
USE_CXXSTD=	gnu++11
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DWITH_LLVM_CONFIG="${LOCALBASE}/llvm${LLVM_VERSION}/bin/llvm-config" \
		-DPOCL_INSTALL_PKGCONFIG_DIR="${PREFIX}/libdata/pkgconfig" \
		-DKERNELLIB_HOST_CPU_VARIANTS="distro"
PLIST_SUB=	OPSYS=${OPSYS:tl} ARCH=${ARCH:S/amd64/x86_64/}

OPTIONS_DEFINE=	TEST

TEST_DESC=	Tests from the OpenCL book
TEST_CMAKE_OFF=	-DENABLE_TESTSUITES=""
TEST_CMAKE_ON=	-DENABLE_TESTSUITES="all"
TEST_TARGET=	test

pre-install-TEST-on: do-test

.include <bsd.port.mk>
