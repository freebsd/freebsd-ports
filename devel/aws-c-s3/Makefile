# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>

PORTNAME=	aws-c-s3
PORTVERSION=	0.1.31
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C99 library implementation for communicating with the S3 service

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-common \
		libaws-c-cal.so:security/aws-c-cal \
		libaws-c-io.so:devel/aws-c-io \
		libaws-c-compression.so:devel/aws-c-compression \
		libaws-c-http.so:devel/aws-c-http \
		libaws-c-auth.so:security/aws-c-auth \
		libaws-c-sdkutils.so:devel/aws-c-sdkutils \
		libs2n.so:security/s2n

USES=		cmake compiler:c11 ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

CMAKE_ARGS+=	-DBUILD_TESTING=OFF -DBUILD_SHARED_LIBS=ON \
		-DCMAKE_PREFIX_PATH=${LOCALBASE}

USE_LDCONFIG=	yes

.include <bsd.port.mk>
