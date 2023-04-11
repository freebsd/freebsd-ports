PORTNAME=	ldc
PORTVERSION=	1.32.0
DISTVERSIONSUFFIX=	-src
CATEGORIES=	lang
MASTER_SITES=	https://github.com/ldc-developers/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	LLVM-based D compiler
WWW=		https://wiki.dlang.org/LDC

LICENSE=	BSD3CLAUSE

BROKEN_armv6=	fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_armv7=	fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_i386=	function core.bitop.bsf (uint v) is not callable using argument types (ulong)
BROKEN_riscv64=	fails to compile: unable to get target for 'riscv64-portbld-freebsd13.0', see -version and -mtriple.

BUILD_DEPENDS=	gdmd>0:devel/gdmd
RUN_DEPENDS=	llvm${_LLVM_VER}>0:devel/llvm${_LLVM_VER}
LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libgphobos.so:lang/gcc${_GCC_VER} \
		libLLVM-${_LLVM_VER}.so:devel/llvm${_LLVM_VER}

USES=		ninja cmake:insource pkgconfig

#USE_GITHUB=	yes
#GH_ACCOUNT=	ldc-developers
#GH_PROJECT=	ldc

USE_LDCONFIG=	yes

CC=		${LOCALBASE}/bin/clang${_LLVM_VER}
CXX=		${LOCALBASE}/bin/clang++${_LLVM_VER}
LLVM_CONFIG=	${LOCALBASE}/bin/llvm-config${_LLVM_VER}

_GCC_VER=	11
_LLVM_VER=	15

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

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ldc-build-runtime
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ldc-profdata
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ldc-prune-cache
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ldc2
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ldmd2

.include <bsd.port.post.mk>
