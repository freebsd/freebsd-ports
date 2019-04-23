# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	include-what-you-use
PORTVERSION=	0.11
CATEGORIES=	devel

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Tool for use with clang to analyze #includes in C and C++ source files

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	clang70:devel/llvm70
RUN_DEPENDS=	clang70:devel/llvm70

USES=		cmake compiler:c++11-lang ncurses python:run shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	fix_includes.py \
		iwyu_tool.py

GH_TAGNAME=	clang_7.0

CMAKE_ARGS+=	-DLLVM_DIR=${LOCALBASE}/llvm70/lib/cmake/llvm \
		-DClang_DIR=${LOCALBASE}/llvm70/lib/cmake/clang

.include <bsd.port.mk>
