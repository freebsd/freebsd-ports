# Created by: David Kalliecharan <dave@dal.ca>
# $FreeBSD$

PORTNAME=	llvmlite
PORTVERSION=	0.16.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dave@dal.ca
COMMENT=	Lightweight LLVM python binding for writing JIT compilers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to compile: clang++: not found

BUILD_DEPENDS=	${PY_ENUM34}

# Python 2.7,3.4+
USES=		python fortran
USE_PYTHON=	distutils autoplist

# llvmlite-0.13.0 requires devel/llvm38
LLVM_VER=	39

BUILD_DEPENDS+=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}

MAKE_ENV=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_VER}

post-patch:
# Requried, because Makefile.freebsd does not see VARS from this Makefile
	${REINPLACE_CMD} -e "s|%%_GCC_VER%%|${_GCC_VER}|" \
		${WRKSRC}/ffi/Makefile.freebsd

.include <bsd.port.mk>
