# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	4.2.0
CATEGORIES=	databases

MAINTAINER=	daniel@blodan.se
COMMENT=	Extension to access Redis

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		php:pecl
USE_PHP=	session:build

CONFLICTS_INSTALL=	pecl-redis3

OPTIONS_DEFINE=	IGBINARY
IGBINARY_DESC=	Build with Igbinary serializer

IGBINARY_CONFIGURE_ENABLE=	redis-igbinary
IGBINARY_USE=			php=igbinary:build

.include <bsd.port.mk>
