# $FreeBSD$

PORTNAME=	zapcc
PORTVERSION=	g20180622
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	C++ caching compiler based on clang

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	googletest>0:devel/googletest

USES=		cmake libedit python:3.4+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	yrnkrn
GH_PROJECT=	zapcc
GH_TAGNAME=	b4c31cc
SHEBANG_GLOB=	*.sh *.py *.pl
SHEBANG_FILES=	tools/clang/tools/clang-format/git-clang-format tools/clang/tools/scan-view/bin/scan-view utils/llvm-lit/llvm-lit.in
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_OFF=	LLVM_ENABLE_WARNINGS LLVM_BUILD_EXAMPLES LLVM_INCLUDE_EXAMPLES LLVM_INCLUDE_TESTS LLVM_INCLUDE_GO_TESTS LLVM_ENABLE_OCAMLDOC LLVM_BUILD_TEST
CMAKE_ON=	LLVM_ENABLE_CXX1Y LLVM_ENABLE_LLD BUILD_SHARED_LIBS

.include <bsd.port.mk>
