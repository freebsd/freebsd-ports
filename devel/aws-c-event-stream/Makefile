PORTNAME=	aws-c-event-stream
PORTVERSION=	0.2.7
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C99 implementation of the vnd.amazon.eventstream content-type

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-common \
		libaws-checksums.so:devel/aws-checksums \
		libaws-c-io.so:devel/aws-c-io \
		libs2n.so:security/s2n \
		libaws-c-cal.so:security/aws-c-cal

USES=		cmake compiler:c11 ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_LIBDIR=${LOCALBASE}/lib
LDFLAGS+=	-lexecinfo -lpthread

USE_LDCONFIG=	yes

.include <bsd.port.mk>
