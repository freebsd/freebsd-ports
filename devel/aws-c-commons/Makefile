# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aws-c-common
PORTVERSION=	20181212
CATEGORIES=	devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Core c99 package for AWS SDK for C

LICENSE=	APACHE20

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs
GH_TAGNAME=	5a85d87

CFLAGS+=	-D__BSD_VISIBLE=1
CMAKE_ARGS+=	-DBUILD_TESTING=OFF -DBUILD_SHARED_LIBS=ON

USE_LDCONFIG=	yes

.include <bsd.port.mk>
