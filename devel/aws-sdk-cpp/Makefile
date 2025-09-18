PORTNAME=	aws-sdk-cpp
DISTVERSION=	1.11.650
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C++ interface for Amazon Web Services (AWS)
WWW=		https://github.com/aws/aws-sdk-cpp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaws-c-auth.so:security/aws-c-auth \
		libaws-c-cal.so:security/aws-c-cal \
		libaws-c-common.so:devel/aws-c-common \
		libaws-c-compression.so:devel/aws-c-compression \
		libaws-c-event-stream.so:devel/aws-c-event-stream \
		libaws-c-http.so:devel/aws-c-http \
		libaws-c-io.so:devel/aws-c-io \
		libaws-c-mqtt.so:devel/aws-c-mqtt \
		libaws-c-s3.so:devel/aws-c-s3 \
		libaws-c-sdkutils.so:devel/aws-c-sdkutils \
		libaws-checksums.so:devel/aws-checksums \
		libaws-crt-cpp.so:devel/aws-crt-cpp \
		libcurl.so:ftp/curl \
		libpulse.so:audio/pulseaudio \
		libs2n.so:security/s2n-tls

USES=		cmake:testing localbase:ldflags pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	aws
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_ONLY="${BUILD_ONLY}"
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_DEPS ENABLE_TESTING AUTORUN_UNIT_TESTS
CMAKE_TESTING_ON=	ENABLE_TESTING
CMAKE_TESTING_TARGET=	# No internal target for running tests. Run via post-test.

BUILD_ONLY?=

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You can build only the clients you need by defining the option BUILD_ONLY."
	@${ECHO_MSG}
	@${ECHO_MSG} "Example:"
	@${ECHO_MSG} "make BUILD_ONLY=\"s3;ec2;route53\""
	@${ECHO_MSG}
	@${ECHO_MSG} "For more information check the file ${WRKSRC}/Docs/CMake_Parameters.md"
	@${ECHO_MSG}
	@${ECHO_MSG} "If this option is not used, the package will be built with support for all the clients."
	@${ECHO_MSG}

post-patch:
	${REINPLACE_CMD} -e "s,/pkgconfig,/../libdata/pkgconfig,g" \
		${WRKSRC}/src/aws-cpp-sdk-core/CMakeLists.txt \
		${WRKSRC}/cmake/utilities.cmake
	${REINPLACE_CMD} -e 's,"-Werror",,g' \
		${WRKSRC}/cmake/compiler_settings.cmake

post-install:
	@cd ${STAGEDIR}/${LOCALBASE} && \
	${FIND} -s -d * -type f > ${TMPPLIST}

post-test:
	for test_binary in ${BUILD_WRKSRC}/generated/tests/*/*-gen-tests; do \
			echo "Running $$(basename $${test_binary})..."; \
			$$test_binary --gtest_brief=1; \
	done

.include <bsd.port.mk>
