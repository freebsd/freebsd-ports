PORTNAME=	aws-c-compression
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.15
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C99 implementation of compression algorithms

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-common

USES=		cmake compiler:c11

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON \
		-DBUILD_TESTING=OFF \
		-DCMAKE_PREFIX_PATH=${LOCALBASE}

.include <bsd.port.mk>
