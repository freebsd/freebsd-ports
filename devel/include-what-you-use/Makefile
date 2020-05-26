# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	include-what-you-use
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Tool for use with clang to analyze \#includes in C and C++ source files

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BROKEN_powerpc64=	fails to configure: Could NOT find Git (missing: GIT_EXECUTABLE)

LLVM_VER=	80
BUILD_DEPENDS=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
RUN_DEPENDS=	clang${LLVM_VER}:devel/llvm${LLVM_VER}

USES=		cmake compiler:c++11-lang ncurses python:run shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	fix_includes.py \
		iwyu_tool.py

GH_TAGNAME=	clang_8.0

CMAKE_ARGS+=	-DLLVM_DIR=${LOCALBASE}/llvm${LLVM_VER}/lib/cmake/llvm \
		-DClang_DIR=${LOCALBASE}/llvm${LLVM_VER}/lib/cmake/clang

.include <bsd.port.mk>
