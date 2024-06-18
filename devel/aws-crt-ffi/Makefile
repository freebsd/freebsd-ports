PORTNAME=	aws-crt-ffi
PORTVERSION=	0.3.8
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Foreign function interface (FFI) for the AWS Common Runtime (CRT) libraries
WWW=		https://github.com/awslabs/aws-crt-ffi

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaws-c-auth.so:security/aws-c-auth \
		libaws-c-cal.so:security/aws-c-cal \
		libaws-c-common.so:devel/aws-c-common \
		libaws-c-compression.so:devel/aws-c-compression \
		libaws-c-event-stream.so:devel/aws-c-event-stream \
		libaws-c-http.so:devel/aws-c-http \
		libaws-c-io.so:devel/aws-c-io \
		libaws-c-sdkutils.so:devel/aws-c-sdkutils \
		libaws-checksums.so:devel/aws-checksums \
		libs2n.so:security/s2n-tls

USES=		cmake ssl

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE}
CMAKE_OFF=	BUILD_DEPS BUILD_TESTING
CMAKE_ON=	BUILD_SHARED_LIBS
USE_LDCONFIG=	yes

PLIST_FILES=	lib/aws-crt-ffi/cmake/aws-crt-ffi-config.cmake \
		lib/libaws-crt-ffi.so

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

.include <bsd.port.mk>
