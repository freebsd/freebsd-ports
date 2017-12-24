# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	include-what-you-use
PORTVERSION=	0.8
CATEGORIES=	devel

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Tool for use with clang to analyze #includes in C and C++ source files

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BROKEN_powerpc64=	fails to compile: cc1plus: unrecognized command line option "-std=c++11"

BUILD_DEPENDS=	clang40:devel/llvm40
RUN_DEPENDS=	clang40:devel/llvm40

USES=		cmake:outsource ncurses python:run shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	fix_includes.py \
		iwyu_tool.py

GH_TAGNAME=	clang_4.0

CMAKE_ARGS+=	-DIWYU_LLVM_INCLUDE_PATH=${LOCALBASE}/llvm40/include \
		-DIWYU_LLVM_LIB_PATH=${LOCALBASE}/llvm40/lib

.include <bsd.port.mk>
