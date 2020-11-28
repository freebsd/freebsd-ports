# Created by: David Kalliecharan <dave@dal.ca>
# $FreeBSD$

PORTNAME=	llvmlite
DISTVERSION=	0.34.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dave@dal.ca
COMMENT=	Lightweight LLVM python binding for writing JIT compilers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_ENUM34} \
		llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}
RUN_DEPENDS=	${PY_ENUM34} \
		llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}

USES=		compiler:c++11-lib python fortran
USE_PYTHON=	distutils autoplist
CXXFLAGS=	-fPIC

MAKE_ENV=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_VER}

LLVM_VER=	${LLVM_DEFAULT}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/llvmlite/binding/libllvmlite.so

.include <bsd.port.mk>
