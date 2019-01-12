# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aws-checksums
PORTVERSION=	0.1.2
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Cross-Platform HW accelerated CRC32c and CRC32

LICENSE=	APACHE20

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

USE_LDCONFIG=	yes

.include <bsd.port.mk>
