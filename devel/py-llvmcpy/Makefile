# $FreeBSD$

PORTNAME=	llvmcpy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1-8
DISTVERSIONSUFFIX=	-g6635c3a
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for LLVM auto-generated from the LLVM-C API

LICENSE=	MIT

RUN_DEPENDS=	llvm-config${LLVM_VERSION}:devel/llvm${LLVM_VERSION} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	revng
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

# LLVM_CONFIG environment variable overrides this: ex. LLVM_CONFIG=llvm-config40 changes to llvm40
LLVM_VERSION=	39  # README says: It has been tested with LLVM 3.4, 3.8 and 3.9

post-patch:
	@${REINPLACE_CMD} -e 's|"llvm-config"|"llvm-config${LLVM_VERSION}"|' ${WRKSRC}/llvmcpy/llvm.py

.include <bsd.port.mk>
