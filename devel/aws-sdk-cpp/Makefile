PORTNAME=	aws-sdk-cpp
PORTVERSION=	1.8.121
CATEGORIES=	devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C++ interface for Amazon Web Services (AWS)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=		fails to build: runaway process
BROKEN_armv7=		fails to build: runaway process
BROKEN_i386=		fails to build: compiler runs out of memory
BROKEN_powerpc=		fails to build: compiler runs out of memory

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpulse.so:audio/pulseaudio \
		libaws-c-common.so:devel/aws-c-common \
		libaws-checksums.so:devel/aws-checksums \
		libaws-c-event-stream.so:devel/aws-c-event-stream

USES=		cmake:noninja localbase:ldflags pkgconfig compiler:c++11-lib ssl

BUILD_ONLY?=

OPTIONS_DEFINE=	TEST
OPTIONS_SUB=	yes

TEST_CMAKE_OFF=	-DENABLE_TESTING=OFF

CMAKE_ARGS+=	-DBUILD_DEPS=OFF -DBUILD_ONLY="${BUILD_ONLY}"

USE_GITHUB=	yes
GH_ACCOUNT=	aws
USE_LDCONFIG=	yes
CXXFLAGS+=	-Wno-error -Wno-c11-extensions

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
		${WRKSRC}/aws-cpp-sdk-core/CMakeLists.txt \
		${WRKSRC}/cmake/utilities.cmake

post-install:
	@cd ${STAGEDIR}/${LOCALBASE} && \
	${FIND} -s -d * -type f > ${TMPPLIST}

.include <bsd.port.mk>
