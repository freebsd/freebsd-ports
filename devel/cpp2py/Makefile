# $FreeBSD$

PORTNAME=	cpp2py
DISTVERSION=	1.5.20200812
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reflection tools based on clang

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		llvm${LLVM_VER}>0:devel/llvm${LLVM_VER}
RUN_DEPENDS=	${PY_DEPENDS} \
		llvm${LLVM_VER}>0:devel/llvm${LLVM_VER}

USES=		cmake compiler:c++14-lang python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	TRIQS
GH_TAGNAME=	10ab97d2e5e56656227a74118943de02e2265292
SHEBANG_FILES=	bin/c*
CMAKE_ARGS=	-DPYTHON_INTERPRETER:STRING=${PYTHON_CMD} \
		-DFREEBSD_LLVM_VER:STRING=${LLVM_VER}

LLVM_VER=	60

PORTSCOUT=	limit:^[0-9\.]*$$

post-install: # remove unnecessary files
	@cd ${STAGEDIR}${PREFIX} && ${RM} share/cpp2py.modulefile share/cpp2pyvars.sh

.include <bsd.port.mk>
