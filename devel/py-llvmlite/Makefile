# Created by: David Kalliecharan <dave@dal.ca>
# $FreeBSD$

PORTNAME=	llvmlite
DISTVERSION=	0.31.0
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

# compatible LLVM versions for llvmlite versions 0.29.0 - ...
LLVM_SUPPORTED_MIN=	70
LLVM_SUPPORTED_MAX=	80

.include <bsd.port.pre.mk>

.if ${LLVM_DEFAULT:C/[1-5]./&0/:S,-devel,990,} < ${LLVM_SUPPORTED_MIN}
LLVM_VER=	${LLVM_SUPPORTED_MIN}
.elif ${LLVM_DEFAULT:C/[1-5]./&0/:S,-devel,990,} > ${LLVM_SUPPORTED_MAX}
LLVM_VER=	${LLVM_SUPPORTED_MAX}
.else
LLVM_VER=	${LLVM_DEFAULT}
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/llvmlite/binding/libllvmlite.so

.include <bsd.port.post.mk>
