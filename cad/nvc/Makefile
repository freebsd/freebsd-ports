PORTNAME=	nvc
DISTVERSIONPREFIX=	r
DISTVERSION=	1.17.1
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	VHDL compiler and simulator
WWW=		https://github.com/nickg/nvc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv7=	compilation fails: no member named '_gregs' in 'mcontext_t'; did you mean '__gregs', see https://github.com/nickg/nvc/issues/534
BROKEN_i386=	compilation fails: static assertion failed due to requirement 'sizeof(jit_ir_t) == 40': Static assertion failed, see https://github.com/nickg/nvc/issues/1133
BROKEN_FreeBSD_14_i386=	clang creashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=265826

BUILD_DEPENDS=	llvm-config${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
LIB_DEPENDS=	libelf.so:devel/libelf \
		libffi.so:devel/libffi \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION} \
		bash:shells/bash
TEST_DEPENDS=	check>0:devel/check

USES=		autoreconf compiler:c++14-lang localbase pkgconfig shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	nickg

SHEBANG_FILES=	contrib/functions.sh

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

LDFLAGS+=	-lexecinfo

CONFIGURE_ARGS=	--with-llvm=${LOCALBASE}/bin/llvm-config${LLVM_VERSION}

MAKE_JOBS_UNSAFE=	yes # workaround for https://github.com/nickg/nvc/issues/746

TEST_TARGET=	check
TEST_WRKSRC=	${WRKSRC}/.build

MAKE_ARGS=	CFLAGS="${CFLAGS}" # only for tests

LLVM_VERSION=	${LLVM_DEFAULT}

# outsource build is required by the project
BUILD_DIR=		${WRKSRC}/.build
BUILD_WRKSRC=		${BUILD_DIR}
CONFIGURE_WRKSRC=	${BUILD_DIR}
INSTALL_WRKSRC=		${BUILD_DIR}
CONFIGURE_CMD=		${WRKSRC}/configure

.include <bsd.port.options.mk>

.if ${ARCH} == "i386" # see the bug#268319 for the LTO failure on i386
CONFIGURE_ARGS+=	--disable-lto # workaround for https://github.com/nickg/nvc/issues/579 (undefined symbol: _GLOBAL_OFFSET_TABLE_, see error: undefined symbol: _GLOBAL_OFFSET_TABLE_)
.endif

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
