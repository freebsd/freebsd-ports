PORTNAME=	nvc
DISTVERSIONPREFIX=	r
DISTVERSION=	1.5.1
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	VHDL compiler and simulator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
RUN_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
TEST_DEPENDS=	check>0:devel/check

USES=		autoreconf compiler:c++14-lang gmake localbase pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	nickg

GNU_CONFIGURE=	yes

LDFLAGS+=	-lexecinfo

CONFIGURE_ARGS=	--with-llvm=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT}

TEST_TARGET=	check # tests fail to compile: https://github.com/nickg/nvc/issues/413

MAKE_ARGS=	CFLAGS="${CFLAGS}" # only for tests

post-install:
	${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
