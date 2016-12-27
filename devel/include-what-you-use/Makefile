# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	include-what-you-use
PORTVERSION=	0.7
CATEGORIES=	devel

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Tool for use with clang to analyze #includes in C and C++ source files

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	clang39:devel/llvm39
RUN_DEPENDS=	clang39:devel/llvm39

BROKEN_FreeBSD_9=	does not build

USES=		cmake:outsource ncurses python:run
USE_GITHUB=	yes

GH_TAGNAME=	clang_3.9

CMAKE_ARGS+=	-DIWYU_LLVM_INCLUDE_PATH=${LOCALBASE}/llvm39/include \
		-DIWYU_LLVM_LIB_PATH=${LOCALBASE}/llvm39/lib

.include <bsd.port.mk>
