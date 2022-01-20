# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>

PORTNAME=	aws-c-mqtt
PORTVERSION=	0.7.10
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C99 implementation of the MQTT 3.1.1 specification

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-common \
		libaws-c-cal.so:security/aws-c-cal \
		libaws-c-io.so:devel/aws-c-io \
		libaws-c-compression.so:devel/aws-c-compression \
		libaws-c-http.so:devel/aws-c-http \
		libs2n.so:security/s2n

USES=		cmake compiler:c11 ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

CMAKE_ARGS+=	-DBUILD_TESTING=OFF -DBUILD_SHARED_LIBS=ON \
		-DCMAKE_PREFIX_PATH=${LOCALBASE}

USE_LDCONFIG=	yes

.include <bsd.port.mk>
