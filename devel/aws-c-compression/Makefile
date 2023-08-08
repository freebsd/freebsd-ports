PORTNAME=	aws-c-compression
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.17
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C99 implementation of compression algorithms
WWW=		https://github.com/awslabs/aws-c-compression

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-common

USES=		cmake:testing compiler:c11

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH=${LOCALBASE}
CMAKE_ON=	BUILD_SHARED_LIBS
CNAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
