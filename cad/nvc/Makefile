PORTNAME=	nvc
DISTVERSIONPREFIX=	r
DISTVERSION=	1.6.1
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	VHDL compiler and simulator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	llvm-config${LLVM_VERSION}:devel/llvm${LLVM_VERSION} \
		${LOCALBASE}/include/unwind.h:devel/libunwind
RUN_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}
TEST_DEPENDS=	check>0:devel/check

USES=		autoreconf compiler:c++14-lang localbase pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	nickg

GNU_CONFIGURE=	yes

LDFLAGS+=	-lexecinfo

CONFIGURE_ARGS=	--with-llvm=${LOCALBASE}/bin/llvm-config${LLVM_VERSION}

TEST_TARGET=	check # one test fails

MAKE_ARGS=	CFLAGS="${CFLAGS}" # only for tests

LLVM_VERSION=	${LLVM_DEFAULT}

post-install:
	${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
