# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	3.1.4
CATEGORIES=	databases

MAINTAINER=	daniel@blodan.se
COMMENT=	Extension to access Redis

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		php:pecl
USE_PHP=	session:build

OPTIONS_DEFINE=	IGBINARY
IGBINARY_DESC=	Build with Igbinary serializer

IGBINARY_CONFIGURE_ENABLE=	redis-igbinary
IGBINARY_USE=			php=igbinary:build

.include <bsd.port.mk>
