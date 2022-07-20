PORTNAME=	aws-c-io
PORTVERSION=	0.10.17
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Event driven framework for implementing application protocols

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-common \
		libaws-c-cal.so:security/aws-c-cal \
		libs2n.so:security/s2n

USES=		cmake compiler:c11 ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_LIBDIR=${LOCALBASE}/lib
USE_LDCONFIG=	yes

.include <bsd.port.mk>
