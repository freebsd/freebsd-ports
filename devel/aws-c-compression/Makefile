PORTNAME=	aws-c-compression
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C99 implementation of compression algorithms
WWW=		https://github.com/awslabs/aws-c-compression

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-common

USES=		cmake:testing localbase

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
