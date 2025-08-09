PORTNAME=	aws-c-event-stream
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.6
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C99 implementation of the vnd.amazon.eventstream content-type
WWW=		https://github.com/awslabs/aws-c-event-stream

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaws-c-cal.so:security/aws-c-cal \
		libaws-c-common.so:devel/aws-c-common \
		libaws-c-io.so:devel/aws-c-io \
		libaws-checksums.so:devel/aws-checksums \
		libs2n.so:security/s2n-tls

USES=		cmake:testing ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

LDFLAGS+=	-lexecinfo -lpthread

PORTSCOUT=	limit:^d\.d\.

.include <bsd.port.mk>
