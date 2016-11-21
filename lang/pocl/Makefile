# $FreeBSD$

PORTNAME=	pocl
PORTVERSION=	0.13
CATEGORIES=	lang
MASTER_SITES=	SF/pocl \
		http://portablecl.org/downloads/

MAINTAINER=	ohartman@zedat.fu-berlin.de
COMMENT=	POrtable Computing Language (POCL)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	llvm${LLVM_VERSION}>=0:devel/llvm${LLVM_VERSION} \
		opencl>=2.1:devel/opencl
LIB_DEPENDS=	libhwloc.so:devel/hwloc \
		libOpenCL.so:devel/ocl-icd \
		libltdl.so:devel/libltdl
RUN_DEPENDS=	llvm${LLVM_VERSION}>=0:devel/llvm${LLVM_VERSION}

CONFLICTS=		freeocl[0-9]*

BROKEN_FreeBSD_9=	pocl is not supported on 9.x
BROKEN_FreeBSD_10=	pocl is not supported on 10.x
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON_amd64=	only tested on amd64

LLVM_VERSION=	37

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GL=		yes
USES=		gmake localbase ncurses pathfix pkgconfig libtool:keepla

INSTALL_TARGET= install-strip

MAKE_ARGS+=	PKGCONFIGDIR=${PREFIX}/libdata/pkgconfig

CONFIGURE_ENV=	LLVM_CONFIG="${LOCALBASE}/llvm${LLVM_VERSION}/bin/llvm-config" \
		CLANGXX_FLAGS=-std=gnu++11
# needed for the libltdl configure check
LDFLAGS+=	-L${LOCALBASE}/lib

ALL_TARGET=	all

OCL_ICD_VENDORS?=	${PREFIX}/etc/OpenCL/vendors

OPTIONS_DEFINE=		DEBUG

OPTIONS_GROUP=		TEST
OPTIONS_GROUP_TEST=	OCLBOOK

OCLBOOK_DESC=	Tests from the OpenCL book
DEBUG_DESC=	Debug build of pocl 

OCLBOOK_CONFIGURE_ENABLE= enable_testsuites="opencl-book-samples,cloverleaf,opencl_book_samples,halide,vexcl"
OCLBOOK_ALL_TARGET=	check

DEBUG_CONFIGURE_ENABLE=	debug

TEST_TARGET=	check

.include <bsd.port.mk>
