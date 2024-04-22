PORTNAME=	include-what-you-use
PORTVERSION=	0.22
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool for use with clang to analyze \#includes in C and C++ source files
WWW=		https://include-what-you-use.org

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		cmake llvm:${LLVM_VER},build,run ncurses python:3.8,run shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	fix_includes.py \
		iwyu_tool.py

CMAKE_ARGS+=	-DLLVM_DIR=${LOCALBASE}/llvm${LLVM_VER}/lib/cmake/llvm \
		-DClang_DIR=${LOCALBASE}/llvm${LLVM_VER}/lib/cmake/clang

LLVM_VER=	18

.include <bsd.port.mk>
