# Created by: David Kalliecharan <dave@dal.ca>
# $FreeBSD$

PORTNAME=	llvmlite
PORTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dave@dal.ca
COMMENT=	Lightweight LLVM python binding for writing JIT compilers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_9=	llvm38 does not find include cmath

# Python 2.7,3.4+
USES=		python fortran
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

# llvmlite-0.13.0 requires devel/llvm38
LLVM_VER=	38

# Python 2.7 requires enum34, unnecessary for Python 3.4+
.if ${PYTHON_REL} < 3400
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34
.endif

BUILD_DEPENDS+=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}

MAKE_ENV=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_VER}

post-patch:
# Requried, because Makefile.freebsd does not see VARS from this Makefile
	${REINPLACE_CMD} -e "s|%%_GCC_VER%%|${_GCC_VER}|" \
		${WRKSRC}/ffi/Makefile.freebsd

.include <bsd.port.post.mk>
