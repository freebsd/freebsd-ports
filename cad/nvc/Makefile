PORTNAME=	nvc
DISTVERSIONPREFIX=	r
DISTVERSION=	1.7.0
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	VHDL compiler and simulator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	llvm-config${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
RUN_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION} \
		bash:shells/bash
TEST_DEPENDS=	check>0:devel/check
.if !exists(/usr/include/unwind.h)
LIB_DEPENDS=	libunwind.so:devel/libunwind
.endif

USES=		autoreconf compiler:c++14-lang localbase pkgconfig shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	nickg

SHEBANG_FILES=	contrib/functions.sh

GNU_CONFIGURE=	yes

LDFLAGS+=	-lexecinfo

CONFIGURE_ARGS=	--with-llvm=${LOCALBASE}/bin/llvm-config${LLVM_VERSION}

TEST_TARGET=	check # one test fails

MAKE_ARGS=	CFLAGS="${CFLAGS}" # only for tests

LLVM_VERSION=	${LLVM_DEFAULT}

# outsource build is required by the project
BUILD_DIR=		${WRKSRC}/.build
BUILD_WRKSRC=		${BUILD_DIR}
CONFIGURE_WRKSRC=	${BUILD_DIR}
INSTALL_WRKSRC=		${BUILD_DIR}
CONFIGURE_CMD=		${WRKSRC}/configure

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
