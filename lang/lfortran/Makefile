PORTNAME=	lfortran
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
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
		libunwind.so:devel/libunwind	\
		libLLVM-${LLVM_VERSION}.so:devel/llvm${LLVM_VERSION}
RUN_DEPENDS=	dwarfdump:devel/dwarfdump

USE_GITHUB=	yes

USES=		bison cmake:testing compiler:c++17-lang python:build shebangfix
SHEBANG_FILES=	*.sh
BINARY_ALIAS=	python=${PYTHON_CMD}
CMAKE_ON=	LFORTRAN_BUILD_ALL WITH_DWARFDUMP WITH_FMT WITH_JSON WITH_LINKH WITH_LLVM WITH_UNWIND

LLVM_VERSION=	11

OPTIONS_DEFINE=	DOCS

# Xeus: version 2.4.1 is required
#LIB_DEPENDS+=	libxeus.so:devel/xeus
#CMAKE_ON+=	WITH_XEUS

# BFD: /usr/local/include/bfd.h:2108:3: error: unknown type name 'ENUM_BITFIELD'
#USE_BINUTILS=	yes
#CMAKE_ON+=	WITH_BFD

pre-configure:
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/version

.include <bsd.port.mk>
