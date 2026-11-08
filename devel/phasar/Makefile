PORTNAME=	phasar
DISTVERSIONPREFIX=	v
DISTVERSION=	2604
PORTREVISION=	1
CATEGORIES=	devel science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LLVM-based static analysis framework
WWW=		https://phasar.org \
		https://github.com/secure-software-engineering/phasar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_graph.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libLLVM-16.so:devel/llvm16 \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing llvm:build,min=20,max=20,noexport localbase:ldflags python shebangfix sqlite compiler:c++20-lang
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py *.sh

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	PHASAR_BUILD_UNITTESTS
CMAKE_TESTING_ON=	PHASAR_BUILD_UNITTESTS

.include <bsd.port.pre.mk>

# The C++20 code requires a newer clang than LLVM 16; compile with LLVM 20
# while still linking against the LLVM 16 libraries.
CMAKE_ARGS+=	-DLLVM_DIR=${LOCALBASE}/llvm16/lib/cmake/llvm

CC=		${LOCALBASE}/llvm20/bin/clang
CPP=		${LOCALBASE}/llvm20/bin/clang-cpp
CXX=		${LOCALBASE}/llvm20/bin/clang++

USE_GITHUB=	yes
GH_ACCOUNT=	secure-software-engineering
GH_TUPLE=	nlohmann:json:9cca280:json/external/json \
		pboettch:json-schema-validator:349cba9:json_schema_validator/external/json-schema-validator

CONFLICTS_INSTALL=nlohmann-json # see https://github.com/secure-software-engineering/phasar/issues/715

post-install: # workaround for https://github.com/secure-software-engineering/phasar/issues/566
	@${RM} -r \
		${STAGEDIR}${PREFIX}/include/gtest \
		${STAGEDIR}${PREFIX}/include/nlohmann

# tests as of 2604: 93% tests passed, 4 tests failed out of 56, see https://github.com/secure-software-engineering/phasar/issues/761

.include <bsd.port.post.mk>
