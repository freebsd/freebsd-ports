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
		libzstd.so:archivers/zstd
RUN_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing localbase:ldflags python shebangfix sqlite compiler:c++20-lang
# LLVM 16-22 supported with 16 and 22 most tested, we need 20+ for C++ support so use 22
USES+=		llvm:22,build
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py *.sh

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	PHASAR_BUILD_UNITTESTS
CMAKE_TESTING_ON=	PHASAR_BUILD_UNITTESTS

.include <bsd.port.pre.mk>

CMAKE_ARGS+=	-DPHASAR_LLVM_VERSION=${LLVM_VERSION}.1
CMAKE_ARGS+=	-DLLVM_DIR=${LOCALBASE}/llvm${PHASER_LLVM_VERSION}/lib/cmake/llvm

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
