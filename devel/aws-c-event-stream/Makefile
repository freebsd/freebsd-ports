# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aws-c-event-stream
PORTVERSION=	20181214
CATEGORIES=	devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C99 implementation of the vnd.amazon.eventstream content-type

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-commons \
		libaws-checksums.so:devel/aws-checksums

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs
GH_TAGNAME=	46391e3

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
LDFLAGS+=	-lexecinfo -lpthread

USE_LDCONFIG=	yes

.include <bsd.port.mk>
