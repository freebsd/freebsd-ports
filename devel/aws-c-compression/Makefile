PORTNAME=	aws-c-compression
PORTVERSION=	0.2.14
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C99 implementation of compression algorithms

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-common

USES=		cmake compiler:c11

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

CMAKE_ARGS+=	-DBUILD_TESTING=OFF -DBUILD_SHARED_LIBS=ON \
		-DCMAKE_PREFIX_PATH=${LOCALBASE}

USE_LDCONFIG=	yes

.include <bsd.port.mk>
