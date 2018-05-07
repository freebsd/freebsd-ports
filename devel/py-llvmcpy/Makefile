# $FreeBSD$

PORTNAME=	llvmcpy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for LLVM auto-generated from the LLVM-C API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	llvm-config${LLVM_VERSION}:devel/llvm${LLVM_VERSION} \
		${PYTHON_PKGNAMEPREFIX}appdirs>=0:devel/py-appdirs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycparser>=0:devel/py-pycparser@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shutilwhich>=0:sysutils/py-shutilwhich@${FLAVOR}

USES=		python:-3.3 # sysutils/py-shutilwhich has this
USE_GITHUB=	yes
GH_ACCOUNT=	revng
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

# LLVM_CONFIG environment variable overrides this: ex. LLVM_CONFIG=llvm-config40 changes to llvm40
LLVM_VERSION=	50  # README says: It has been tested with LLVM 3.4, 3.8 and 3.9

post-patch:
	@${REINPLACE_CMD} -e 's|"llvm-config"|"llvm-config${LLVM_VERSION}"|' ${WRKSRC}/llvmcpy/llvm.py

.include <bsd.port.mk>
