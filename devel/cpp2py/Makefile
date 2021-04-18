PORTNAME=	cpp2py
DISTVERSION=	2.0.0
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	44d5238ab4f05ed4064736ffd2f2b63438d3f64c.patch:-p1 # fix build on i386

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

USES=		cmake compiler:c++14-lang gettext-runtime python:3.7+ shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	TRIQS

SHEBANG_FILES=	bin/c*

CMAKE_ARGS=	-DPYTHON_INTERPRETER:STRING=${PYTHON_CMD} \
		-DFREEBSD_LLVM_VER:STRING=${LLVM_VER}

LLVM_VER=	10

PORTSCOUT=	limit:^[0-9\.]*$$

post-install: # remove the unnecessary file: https://github.com/TRIQS/cpp2py/issues/41
	@${RM} ${STAGEDIR}${PREFIX}/share/cpp2pyvars.sh

.include <bsd.port.mk>
