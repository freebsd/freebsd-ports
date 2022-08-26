PORTNAME=	aws-c-sdkutils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.3
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	AWS SDK C utilities

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-common

USES=		cmake compiler:c11

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON \
		-DBUILD_TESTING=OFF \
		-DCMAKE_PREFIX_PATH=${LOCALBASE}

PORTSCOUT=	limit:^d\.d\.

.include <bsd.port.mk>
