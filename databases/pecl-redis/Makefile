PORTNAME=	redis
PORTVERSION=	5.3.7
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	daniel@blodan.se
COMMENT=	Extension to access Redis
WWW=		https://pecl.php.net/package/redis

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		php:build,pecl
USE_PHP=	session:build
IGNORE_WITH_PHP=	84

OPTIONS_DEFINE=	IGBINARY
IGBINARY_DESC=	Build with Igbinary serializer

IGBINARY_CONFIGURE_ENABLE=	redis-igbinary
IGBINARY_USE=			PHP=igbinary:build

.include <bsd.port.mk>
