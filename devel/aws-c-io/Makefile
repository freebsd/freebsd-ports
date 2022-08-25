PORTNAME=	aws-c-io
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.2
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Event driven framework for implementing application protocols

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-cal.so:security/aws-c-cal \
		libaws-c-common.so:devel/aws-c-common \
		libs2n.so:security/s2n

USES=		cmake compiler:c11 ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON \
		-DCMAKE_INSTALL_LIBDIR=${LOCALBASE}/lib

.include <bsd.port.mk>
