PORTNAME=	aws-c-io
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.21
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Event driven framework for implementing application protocols
WWW=		https://github.com/awslabs/aws-c-io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaws-c-cal.so:security/aws-c-cal \
		libaws-c-common.so:devel/aws-c-common \
		libs2n.so:security/s2n-tls

USES=		cmake:testing compiler:c11 ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

USE_LDCONFIG=	yes

# do-test: fails, "ld: error: lib/libaws-c-cal.so.1.0.0: undefined reference to aws_device_random_buffer_append [--no-allow-shlib-undefined]"
# see also: https://github.com/awslabs/aws-c-io/issues/565

CMAKE_ARGS+=	-DCMAKE_INSTALL_LIBDIR=${LOCALBASE}/lib
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
