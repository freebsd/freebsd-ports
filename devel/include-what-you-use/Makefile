PORTNAME=	include-what-you-use
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool for use with clang to analyze \#includes in C and C++ source files

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

LLVM_VER=	14
BUILD_DEPENDS=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
RUN_DEPENDS=	clang${LLVM_VER}:devel/llvm${LLVM_VER}

USES=		cmake compiler:c++11-lang ncurses python:3.8,run shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	fix_includes.py \
		iwyu_tool.py

CMAKE_ARGS+=	-DLLVM_DIR=${LOCALBASE}/llvm${LLVM_VER}/lib/cmake/llvm \
		-DClang_DIR=${LOCALBASE}/llvm${LLVM_VER}/lib/cmake/clang

.include <bsd.port.mk>
