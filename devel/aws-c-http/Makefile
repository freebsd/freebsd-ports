PORTNAME=	aws-c-http
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.4
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C99 implementation of the HTTP/1.1 and HTTP/2 specifications
WWW=		https://github.com/awslabs/aws-c-http

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaws-c-cal.so:security/aws-c-cal \
		libaws-c-common.so:devel/aws-c-common \
		libaws-c-compression.so:devel/aws-c-compression \
		libaws-c-io.so:devel/aws-c-io \
		libs2n.so:security/s2n-tls

USES=		cmake:testing ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
