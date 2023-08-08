PORTNAME=	lfortran
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.0
PORTREVISION=	2
CATEGORIES=	lang

MAINTAINER=	fortran@FreeBSD.org
COMMENT=	Modern interactive Fortran compiler built on top of LLVM
WWW=		https://lfortran.org/

LICENSE=	BSD3CLAUSE

BROKEN_FreeBSD_12=	use of undeclared identifier '_Unwind_Backtrace'
BROKEN_i386=	sizeof(YYSTYPE) != sizeof(Vec<AST::ast_t*>)

BUILD_DEPENDS=	bash:shells/bash		\
		re2c>0:devel/re2c		\
		dwarfdump:devel/dwarfdump	\
		rapidjson>0:devel/rapidjson
LIB_DEPENDS=	libfmt.so:devel/libfmt	\
		libzstd.so:archivers/zstd	\
		libunwind.so:devel/libunwind	\
		libLLVM-${LLVM_VERSION}.so:devel/llvm${LLVM_VERSION}
RUN_DEPENDS=	dwarfdump:devel/dwarfdump

USE_GITHUB=	yes

USES=		bison cmake:testing compiler:c++17-lang pkgconfig	\
		python:build ssl shebangfix
SHEBANG_FILES=	*.sh
BINARY_ALIAS=	python=${PYTHON_CMD}
CMAKE_ON=	LFORTRAN_BUILD_ALL WITH_DWARFDUMP WITH_FMT WITH_JSON	\
		WITH_LINKH WITH_LLVM WITH_STACKTRACE WITH_UNWIND

LLVM_VERSION=	15

OPTIONS_DEFINE=	DOCS

# Xeus: version 3.0.5 is required and xeus-zmq 1.0.2
# + xtl-quant-stack + cppzmq + nlohmann_json + LibUUID + libzmq4
BUILD_DEPENDS+=	xtl-quant-stack>=0.7:devel/xtl-quant-stack	\
		nlohmann-json>0:devel/nlohmann-json	\
		cppzmq>=4.8.1:net/cppzmq
LIB_DEPENDS+=	libxeus.so:devel/xeus	\
		libzmq.so:net/libzmq4	\
		libxeus-zmq.so:devel/xeus-zmq	\
		libuuid.so:misc/e2fsprogs-libuuid
CMAKE_ON+=	WITH_XEUS

# BFD:
USE_BINUTILS=	yes
CMAKE_ON+=	WITH_BFD
LIB_DEPENDS+=	libbfd-2.40.so:devel/binutils

pre-configure:
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/version

.include <bsd.port.mk>
