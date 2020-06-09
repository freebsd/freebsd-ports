# $FreeBSD$

PORTNAME=	halide
DISTVERSIONPREFIX=	release_
DISTVERSION=	2019_08_27-2023
DISTVERSIONSUFFIX=	-g48f9a1c75
PORTREVISION=	1
CATEGORIES=	lang

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	49c7ee068327af7e1dc71cdd37afb61f3132097f.patch:-p1 # FreeBSD compatibility patches

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
CMAKE_OFF=	WITH_PYTHON_BINDINGS WITH_APPS WITH_TUTORIALS WITH_DOCS # APPS are demos

OPTIONS_DEFINE=	NATIVE

NATIVE_DESC=	Build with native optimizations (-march=native)

post-patch-NATIVE-off:
	@${REINPLACE_CMD} -e 's| -march=native | |' ${WRKSRC}/apps/linear_algebra/Makefile

post-install: # see https://github.com/halide/Halide/issues/4952
.for f in tools tutorial CODE_OF_CONDUCT.md README.md README_cmake.md README_rungen.md README_webassembly.md
	@${RM} -r ${STAGEDIR}${PREFIX}/${f}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake
	@${MV} ${STAGEDIR}${PREFIX}/*.cmake ${STAGEDIR}${PREFIX}/lib/cmake
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MV} ${STAGEDIR}${PREFIX}/halide_config.make ${STAGEDIR}${DATADIR}
	@${MV} ${STAGEDIR}${PREFIX}/bin/libHalide.so ${STAGEDIR}${PREFIX}/lib
	@${RMDIR} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
