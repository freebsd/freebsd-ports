# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	include-what-you-use
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Tool for use with clang to analyze #includes in C and C++ source files

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	clang37:devel/llvm37
RUN_DEPENDS=	clang37:devel/llvm37

USES=		cmake:outsource ncurses python:run
USE_GITHUB=	yes

GH_TAGNAME=	clang_3.7

CMAKE_ARGS+=	-DIWYU_LLVM_INCLUDE_PATH=${LOCALBASE}/llvm37/include \
		-DIWYU_LLVM_LIB_PATH=${LOCALBASE}/llvm37/lib

PLIST_FILES=	bin/fix_includes.py \
		bin/include-what-you-use \
		bin/iwyu_tool.py

.include <bsd.port.mk>
