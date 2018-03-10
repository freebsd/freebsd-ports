# Created by: David Kalliecharan <dave@dal.ca>
# $FreeBSD$

PORTNAME=	llvmlite
DISTVERSION=	0.22.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dave@dal.ca
COMMENT=	Lightweight LLVM python binding for writing JIT compilers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to compile: clang++: not found

BUILD_DEPENDS=	${PY_ENUM34}
RUN_DEPENDS=	${PY_ENUM34}
LIB_DEPENDS=	libLLVM-5.0.so:devel/llvm50

# Python 2.7,3.4+
USES=		python fortran
USE_PYTHON=	distutils autoplist

# llvmlite requires devel/llvm50
LLVM_VER=	50

MAKE_ENV=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_VER}

post-patch:
# Requried, because Makefile.freebsd does not see VARS from this Makefile
	@${REINPLACE_CMD} -e "s|%%_GCC_VER%%|${_GCC_VER}|" \
		${WRKSRC}/ffi/Makefile.freebsd

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/llvmlite/binding/libllvmlite.so

.include <bsd.port.mk>
