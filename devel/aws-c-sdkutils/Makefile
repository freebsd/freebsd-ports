PORTNAME=	aws-c-sdkutils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.19
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	AWS SDK C utilities
WWW=		https://github.com/awslabs/aws-c-sdkutils

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-common

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH=${LOCALBASE}
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
