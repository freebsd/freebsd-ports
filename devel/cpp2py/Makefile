# $FreeBSD$

PORTNAME=	cpp2py
DISTVERSION=	1.5-19
DISTVERSIONSUFFIX=	-g5fd079c
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reflection tools based on clang

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		llvm${LLVM_VER}>0:devel/llvm${LLVM_VER}
RUN_DEPENDS=	${PY_DEPENDS} \
		llvm${LLVM_VER}>0:devel/llvm${LLVM_VER}

USES=		cmake:outsource compiler:c++14-lang python:2.7 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	TRIQS
SHEBANG_FILES=	bin/c*
CMAKE_ARGS=	-DPYTHON_INTERPRETER:STRING=${PYTHON_CMD} \
		-DFREEBSD_LLVM_VER:STRING=${LLVM_VER}
USE_LDCONFIG=	yes

LLVM_VER=	60

post-install: # there's some kind of confusion between cmake's MODULE and CONFIG modes
	@cd ${STAGEDIR}${PREFIX}/share/cmake/Modules && ${CP} Cpp2PyConfig.cmake FindCpp2Py.cmake # can't be found without this

.include <bsd.port.mk>
