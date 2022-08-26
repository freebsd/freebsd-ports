PORTNAME=	aws-c-event-stream
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.14
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C99 implementation of the vnd.amazon.eventstream content-type

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-cal.so:security/aws-c-cal \
		libaws-c-common.so:devel/aws-c-common \
		libaws-c-io.so:devel/aws-c-io \
		libaws-checksums.so:devel/aws-checksums \
		libs2n.so:security/s2n

USES=		cmake compiler:c11 ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON \
		-DCMAKE_INSTALL_LIBDIR=${LOCALBASE}/lib
LDFLAGS+=	-lexecinfo -lpthread

PORTSCOUT=	limit:^d\.d\.

.include <bsd.port.mk>
