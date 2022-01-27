PORTNAME=	aws-sdk-cpp
PORTVERSION=	1.9.183
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
		libaws-c-event-stream.so:devel/aws-c-event-stream \
		libaws-crt-cpp.so:devel/aws-crt-cpp \
		libaws-c-mqtt.so:devel/aws-c-mqtt \
		libaws-c-s3.so:devel/aws-c-s3 \
		libaws-c-auth.so:security/aws-c-auth \
		libaws-c-http.so:devel/aws-c-http \
		libaws-c-io.so:devel/aws-c-io \
		libs2n.so:security/s2n \
		libaws-c-compression.so:devel/aws-c-compression \
		libaws-c-cal.so:security/aws-c-cal \
		libaws-c-sdkutils.so:devel/aws-c-sdkutils \
		libnghttp2.so:www/libnghttp2 \
		libssh2.so:security/libssh2 \
		libdbus-1.so:devel/dbus \
		libsndfile.so:audio/libsndfile \
		libFLAC.so:audio/flac \
		libopus.so:audio/opus \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg

USES=		cmake:noninja compiler:c++11-lib gettext-runtime localbase:ldflags \
		pkgconfig ssl xorg
USE_XORG=	x11 xcb ice sm xtst xau xdmcp xext xi

BUILD_ONLY?=

OPTIONS_DEFINE=	TEST
OPTIONS_SUB=	yes

TEST_CMAKE_OFF=	-DENABLE_TESTING=OFF

CMAKE_ARGS+=	-DBUILD_DEPS=OFF -DBUILD_ONLY="${BUILD_ONLY}" \
		-DCMAKE_PREFIX_PATH=${LOCALBASE} -DCMAKE_INSTALL_LIBDIR=lib

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
	${REINPLACE_CMD} -e 's,"-Werror",,g' \
		${WRKSRC}/cmake/compiler_settings.cmake

post-install:
	@cd ${STAGEDIR}/${LOCALBASE} && \
	${FIND} -s -d * -type f > ${TMPPLIST}

.include <bsd.port.mk>
