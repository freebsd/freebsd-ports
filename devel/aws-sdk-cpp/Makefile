# $FreeBSD$

PORTNAME=	aws-sdk-cpp
PORTVERSION=	1.8.68
CATEGORIES=	devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C++ interface for Amazon Web Services (AWS)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=		fails to build: runaway process
BROKEN_armv7=		fails to build: runaway process
BROKEN_i386=		fails to build: compiler runs out of memory

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpulse.so:audio/pulseaudio \
		libaws-c-common.so:devel/aws-c-common \
		libaws-checksums.so:devel/aws-checksums \
		libaws-c-event-stream.so:devel/aws-c-event-stream

USES=		cmake:noninja pkgconfig compiler:c++11-lib ssl

OPTIONS_DEFINE=	TEST
OPTIONS_SUB=	yes

TEST_CMAKE_OFF=	-DENABLE_TESTING=OFF

CMAKE_ARGS+=	-DBUILD_DEPS=OFF

USE_GITHUB=	yes
GH_ACCOUNT=	aws
USE_LDCONFIG=	yes
CXXFLAGS+=	-Wno-error -Wno-c11-extensions
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} -e "s,/pkgconfig,/../libdata/pkgconfig,g" \
		${WRKSRC}/aws-cpp-sdk-core/CMakeLists.txt \
		${WRKSRC}/cmake/utilities.cmake

.include <bsd.port.mk>
