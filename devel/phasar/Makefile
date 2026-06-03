PORTNAME=	phasar
DISTVERSIONPREFIX=	v
DISTVERSION=	2503
PORTREVISION=	2
CATEGORIES=	devel science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LLVM-based static analysis framework
WWW=		https://phasar.org \
		https://github.com/secure-software-engineering/phasar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_graph.so:devel/boost-libs \
		libcurl.so:ftp/curl
RUN_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing llvm:lib,min=15,max=15 localbase:ldflags python shebangfix sqlite # compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	secure-software-engineering
GH_TUPLE=	nlohmann:json:9cca280:json/external/json \
		pboettch:json-schema-validator:349cba9:json_schema_validator/external/json-schema-validator

SHEBANG_GLOB=	*.py *.sh

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	PHASAR_BUILD_UNITTESTS
CMAKE_ARGS=	-DPHASAR_CUSTOM_CONFIG_INSTALL_DIR=etc/phasar
CMAKE_TESTING_ON=	PHASAR_BUILD_UNITTESTS

CONFLICTS_INSTALL=	nlohmann-json # see https://github.com/secure-software-engineering/phasar/issues/715

post-patch: # workaround for https://github.com/secure-software-engineering/phasar/issues/564
	# fix up the config directory location
	@${REINPLACE_CMD} \
		-e 's|std::string PhasarConfDir = std::string(EnvHome) + "/.config/phasar/"|std::string PhasarConfDir = "${PREFIX}/etc/phasar/"|; s|if (EnvHome) {|if (true) {|' \
		${WRKSRC}/lib/Config/Configuration.cpp

post-install: # workaround for https://github.com/secure-software-engineering/phasar/issues/566
	@${RM} -r \
		${STAGEDIR}${PREFIX}/include/gtest \
		${STAGEDIR}${PREFIX}/include/nlohmann

# tests as of 2503: 91% tests passed, 5 tests failed out of 54, see https://github.com/secure-software-engineering/phasar/issues/761

.include <bsd.port.mk>
