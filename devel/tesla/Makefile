# $FreeBSD$

PORTNAME=	tesla
DISTVERSION=	0.0.20140425
PORTREVISION=	6
CATEGORIES=	devel lang

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Temporally Enhanced Security Logic Assertions

BUILD_DEPENDS=	clang33:lang/clang33
RUN_DEPENDS=	clang33:lang/clang33
LIB_DEPENDS=	libprotobuf.so:devel/protobuf

BROKEN_armv6=		fails to link: cmTC_8106f uses VFP register arguments, testCCompiler.c.o does not

SHEBANG_FILES=	scripts/highlight-transitions

USES=		cmake:outsource execinfo python:run shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-TESLA
GH_PROJECT=	TESLA
GH_TAGNAME=	3136f0f

CC=		clang33
CXX=		clang++33

CMAKE_ARGS+=	-DCMAKE_LLVM_CONFIG=llvm-config33

.include <bsd.port.mk>
