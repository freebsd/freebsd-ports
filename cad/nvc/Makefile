PORTNAME=	nvc
DISTVERSION=	1.18.1
CATEGORIES=	cad
MASTER_SITES=	https://www.nickg.me.uk/files/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	VHDL compiler and simulator
WWW=		https://www.nickg.me.uk/nvc/ \
		https://github.com/nickg/nvc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64
# /wrkdirs/usr/ports/cad/nvc/work/nvc-1.18.0/src/jit/jit-code.c:858:42: error: use of undeclared identifier 'veneer'
#  858 |                        veneer, ARRAY_LEN(veneer));
#      |
# https://github.com/nickg/nvc/blob/14f8f7c4a1733fc39b35799e8ae0328e91d1ae0f/src/jit/jit-code.c#L854
ONLY_FOR_ARCHS_REASON=	compilation fails: jit-code.c:858:42: error: use of undeclared identifier 'veneer'

BUILD_DEPENDS=	llvm-config${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
LIB_DEPENDS=	libcapstone.so:devel/capstone \
		libffi.so:devel/libffi \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	bash:shells/bash \
		llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}
TEST_DEPENDS=	check>0:devel/check

USES=		autoreconf compiler:c++14-lang localbase pkgconfig shebangfix

SHEBANG_FILES=	contrib/functions.sh

GNU_CONFIGURE=	yes
CONFIGURE_CMD=	${WRKSRC}/configure
CONFIGURE_ARGS=	--with-llvm=${LOCALBASE}/bin/llvm-config${LLVM_VERSION}

MAKE_ARGS=	CFLAGS="${CFLAGS}" # only for tests
TEST_TARGET=	check

LDFLAGS+=	-lexecinfo

# outsource build is required by the project
BUILD_WRKSRC=		${BUILD_DIR}
CONFIGURE_WRKSRC=	${BUILD_DIR}
INSTALL_WRKSRC=		${BUILD_DIR}
TEST_WRKSRC=		${WRKSRC}/.build

BUILD_DIR=	${WRKSRC}/.build
LLVM_VERSION=	${LLVM_DEFAULT}

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
