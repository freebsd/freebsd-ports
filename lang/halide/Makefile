# $FreeBSD$

PORTNAME=	halide
DISTVERSIONPREFIX=	release_
DISTVERSION=	2019_08_27-2654
DISTVERSIONSUFFIX=	-g664dc4993
CATEGORIES=	lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Halide, a language for fast and portable data-parallel computation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT} # because halide expects LLVMConfig.cmake
RUN_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cmake
USE_GITHUB=	yes
GH_PROJECT=	Halide
USE_LDCONFIG=	yes

# use the same compiler that devel/llvmNN installs
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}

CMAKE_ARGS=	-DLLVM_DIR=${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/cmake/llvm
CMAKE_ON=	LLVM_USE_SHARED_LLVM_LIBRARY HALIDE_SHARED_LIBRARY
CMAKE_OFF=	WITH_PYTHON_BINDINGS WITH_APPS WITH_TUTORIALS WITH_DOCS WITH_TESTS # APPS are demos

OPTIONS_DEFINE=	NATIVE

NATIVE_DESC=	Build with native optimizations (-march=native)

post-patch-NATIVE-off:
	@${REINPLACE_CMD} -e 's| -march=native | |' ${WRKSRC}/apps/linear_algebra/Makefile

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share

.include <bsd.port.mk>
