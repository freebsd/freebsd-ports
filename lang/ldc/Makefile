PORTNAME=	ldc
PORTVERSION=	1.30.0
CATEGORIES=	lang
MASTER_SITES=	https://github.com/ldc-developers/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTVERSIONSUFFIX=	-src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	LLVM-based D compiler
WWW=		https://wiki.dlang.org/LDC

LICENSE=	BSD3CLAUSE

BROKEN_armv6=	fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_armv7=	fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_i386=	function core.bitop.bsf (uint v) is not callable using argument types (ulong)
BROKEN_riscv64=	fails to compile: unable to get target for 'riscv64-portbld-freebsd13.0', see -version and -mtriple.

LLVM_VERSION=	13
BUILD_DEPENDS=	gdmd>0:devel/gdmd \
		gdc11:lang/gcc11
RUN_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}
LIB_DEPENDS=	libconfig.so:devel/libconfig

USES=		ninja cmake:insource pkgconfig

#USE_GITHUB=	yes
#GH_ACCOUNT=	ldc-developers
#GH_PROJECT=	ldc

USE_LDCONFIG=	yes

CC=		${LOCALBASE}/bin/clang${LLVM_VERSION}
CXX=		${LOCALBASE}/bin/clang++${LLVM_VERSION}
LLVM_CONFIG=	${LOCALBASE}/bin/llvm-config${LLVM_VERSION}
LDCVER=		${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "aarch64" || ${ARCH} == "amd64"
CFLAGS+=		-fPIC
.endif

CMAKE_ARGS+=	-DLDC_INSTALL_PREFIX="${PREFIX}" \
		-DD_COMPILER="${PREFIX}/bin/gdmd" \
		-DCMAKE_C_COMPILER="${CC}" \
		-DCMAKE_CXX_COMPILER="${CXX}" \
		-DLLVM_CONFIG=${LLVM_CONFIG} \
		-DBUILD_SHARED_LIBS="BOTH" \
		-DBUILD_LTO_LIBS=ON

.include <bsd.port.post.mk>
