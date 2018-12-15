# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aws-checksums
PORTVERSION=	20181214
CATEGORIES=	devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Cross-Platform HW accelerated CRC32c and CRC32

LICENSE=	APACHE20

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs
GH_TAGNAME=	b06b1f7

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

USE_LDCONFIG=	yes

.include <bsd.port.mk>
