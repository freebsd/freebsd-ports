PORTNAME=	clang-uml
PORTVERSION=	0.6.2
CATEGORIES=	graphics lang textproc

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	C++ UML diagram generator based on Clang
WWW=		https://github.com/bkryza/clang-uml

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libyaml-cpp.so:devel/yaml-cpp

USES=		cmake:testing compiler:c++17-lang llvm:noexport,lib \
		localbase:ldflags

CMAKE_ARGS=	-DCLANG_UML_ENABLE_BACKTRACE=OFF \
		-DBUILD_TESTS=OFF
CMAKE_TESTING_ON=BUILD_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	bkryza

BUILD_WRKSRC_TESTS=	${BUILD_WRKSRC}/tests
TESTING_UNSAFE=		some tests fail

pre-test:
	@if [ "${BUILD_WRKSRC_TESTS:H:H}" != "${WRKDIR}" ]; then \
		${ECHO_CMD} This software expects tests data to be located at \
		../../tests relative to ;\
		${ECHO_CMD} ${BUILD_WRKSRC_TESTS} ;\
		${ECHO_CMD} but this path is outside of ;\
		${ECHO_CMD} ${WRKDIR}; \
		${FALSE}; \
	fi
	${RM} ${WRKDIR}/tests
	${LN} -s ${WRKSRC}/tests ${WRKDIR}/tests

.include <bsd.port.mk>
