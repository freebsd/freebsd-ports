PORTNAME=	ldc
PORTVERSION=	1.23.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	acm@FreeBSD.org
COMMENT=	LLVM-based D compiler

LICENSE=	BSD3CLAUSE

BROKEN_armv6=	fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_armv7=	fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_i386=	function core.bitop.bsf (uint v) is not callable using argument types (ulong)
BROKEN_riscv64=	fails to compile: unable to get target for 'riscv64-portbld-freebsd13.0', see -version and -mtriple.

LLVM_VERSION=	10
BUILD_DEPENDS=	llvm70>0:devel/llvm70 \
		llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}
RUN_DEPENDS=	llvm70>0:devel/llvm70 \
		llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}
LIB_DEPENDS=	libconfig.so:devel/libconfig

USES=		ninja cmake:insource

USE_GITHUB=	yes
GH_ACCOUNT=	ldc-developers
GH_PROJECT=	ldc
GH_TUPLE=	ldc-developers:ldc:911589c:tree/ltsmaster \
		ldc-developers:druntime:13b1ccf:druntimelts/ltsmaster/runtime/druntime \
		ldc-developers:phobos:1d758b2:phoboslts/ltsmaster/runtime/phobos \
		ldc-developers:druntime:cc97ccd:druntime/runtime/druntime \
		ldc-developers:phobos:8ae121c:phobos/runtime/phobos

USE_LDCONFIG=	yes

CC=		${LOCALBASE}/bin/clang${LLVM_VERSION}
CXX=		${LOCALBASE}/bin/clang++${LLVM_VERSION}
LLVM_CONFIG=	${LOCALBASE}/bin/llvm-config${LLVM_VERSION}
LDCVER=		${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "aarch64" || ${ARCH} == "amd64"
CFLAGS+=		-fPIC
.endif

.if ${OPSYS} == FreeBSD
EXTRA_PATCHES=	${PATCHDIR}/fbsd12-*
.endif

CMAKE_ARGS+=	-DLDC_INSTALL_PREFIX="${PREFIX}" \
		-DD_COMPILER:STRING="${WRKSRC}/ltsmaster/bin/ldmd2" \
		-DCMAKE_C_COMPILER:STRING="${CC}" \
		-DCMAKE_CXX_COMPILER:STRING="${CXX}" \
		-DLLVM_CONFIG:PATH=${LLVM_CONFIG} \
		-DBUILD_SHARED_LIBS:STRING="BOTH"

pre-configure:
	@cd ${WRKSRC}/ltsmaster && \
	    ${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} -GNinja .
	@cd ${WRKSRC}/ltsmaster && \
	    ${SETENV} ${MAKE_ENV} ninja

.include <bsd.port.post.mk>
