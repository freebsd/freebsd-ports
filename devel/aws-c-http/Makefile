PORTNAME=	aws-c-http
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.20
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C99 implementation of the HTTP/1.1 and HTTP/2 specifications

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-cal.so:security/aws-c-cal \
		libaws-c-common.so:devel/aws-c-common \
		libaws-c-compression.so:devel/aws-c-compression \
		libaws-c-io.so:devel/aws-c-io \
		libs2n.so:security/s2n

USES=		cmake compiler:c11 ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON \
		-DBUILD_TESTING=OFF \
		-DCMAKE_PREFIX_PATH=${LOCALBASE}

.include <bsd.port.mk>
