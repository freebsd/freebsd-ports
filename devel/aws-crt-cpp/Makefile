PORTNAME=	aws-crt-cpp
PORTVERSION=	0.17.14
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C++ wrapper around the aws-c libraries

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-mqtt.so:devel/aws-c-mqtt \
		libaws-c-event-stream.so:devel/aws-c-event-stream \
		libaws-c-s3.so:devel/aws-c-s3 \
		libaws-checksums.so:devel/aws-checksums \
		libaws-c-auth.so:security/aws-c-auth \
		libaws-c-http.so:devel/aws-c-http \
		libaws-c-io.so:devel/aws-c-io \
		libs2n.so:security/s2n \
		libaws-c-compression.so:devel/aws-c-compression \
		libaws-c-cal.so:security/aws-c-cal \
		libaws-c-sdkutils.so:devel/aws-c-sdkutils \
		libaws-c-common.so:devel/aws-c-common

USES=		cmake compiler:c11 ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

CMAKE_ARGS+=	-DBUILD_TESTING=OFF -DBUILD_SHARED_LIBS=ON \
		-DBUILD_DEPS=OFF -DCMAKE_PREFIX_PATH=${LOCALBASE}

USE_LDCONFIG=	yes

.include <bsd.port.mk>
