PORTNAME=	aws-crt-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.3
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C++ wrapper around the aws-c libraries

LICENSE=	APACHE20

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
		libs2n.so:security/s2n

USES=		cmake compiler:c11 ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_DEPS=OFF \
		-DBUILD_SHARED_LIBS=ON \
		-DBUILD_TESTING=OFF \
		-DCMAKE_PREFIX_PATH=${LOCALBASE}

.include <bsd.port.mk>
