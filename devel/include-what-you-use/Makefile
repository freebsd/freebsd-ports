# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	include-what-you-use
PORTVERSION=	0.15
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for use with clang to analyze \#includes in C and C++ source files

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

LLVM_VER=	11
BUILD_DEPENDS=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
RUN_DEPENDS=	clang${LLVM_VER}:devel/llvm${LLVM_VER}

USES=		cmake compiler:c++11-lang ncurses python:run shebangfix
USE_GITHUB=	yes
GH_TAGNAME=	clang_${LLVM_VER}

SHEBANG_FILES=	fix_includes.py \
		iwyu_tool.py

CMAKE_ARGS+=	-DLLVM_DIR=${LOCALBASE}/llvm${LLVM_VER}/lib/cmake/llvm \
		-DClang_DIR=${LOCALBASE}/llvm${LLVM_VER}/lib/cmake/clang

.include <bsd.port.mk>
