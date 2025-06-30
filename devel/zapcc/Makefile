PORTNAME=	zapcc
PORTVERSION=	g20180622
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	C++ caching compiler based on clang
WWW=		https://www.zapcc.com/

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BROKEN_riscv64=		fails to build: CMake Error at cmake/config-ix.cmake:407: Unknown architecture riscv64

BUILD_DEPENDS=	googletest>0:devel/googletest

USES=		cmake compiler:c++11-lang gnome libedit python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	yrnkrn
GH_TAGNAME=	b4c31cc
SHEBANG_GLOB=	*.sh *.py *.pl
SHEBANG_FILES=	tools/clang/tools/clang-format/git-clang-format tools/clang/tools/scan-view/bin/scan-view utils/llvm-lit/llvm-lit.in
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	cling llvm

CMAKE_OFF=	LLVM_ENABLE_WARNINGS LLVM_BUILD_EXAMPLES LLVM_INCLUDE_EXAMPLES LLVM_INCLUDE_TESTS LLVM_INCLUDE_GO_TESTS LLVM_ENABLE_OCAMLDOC LLVM_BUILD_TEST
CMAKE_ON=	LLVM_ENABLE_CXX1Y LLVM_ENABLE_LLD BUILD_SHARED_LIBS

LDFLAGS+=	-Wl,--undefined-version

.include <bsd.port.mk>
