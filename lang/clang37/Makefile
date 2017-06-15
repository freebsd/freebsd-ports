# Created by: Brooks Davis
# $FreeBSD$

PORTNAME=	clang
PORTVERSION=	3.7
PORTREVISION=	3
CATEGORIES=	lang devel
PKGNAMESUFFIX=	${LLVM_SUFFIX}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	C, Objective-C, and C++ compiler (use devel/llvm${LLVM_SUFFIX})

RUN_DEPENDS+=	${LOCALBASE}/bin/clang${LLVM_SUFFIX}:devel/llvm${LLVM_SUFFIX}

LLVM_SUFFIX=	37

USES=		metaport

.include <bsd.port.mk>
