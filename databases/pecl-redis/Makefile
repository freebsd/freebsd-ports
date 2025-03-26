PORTNAME=	redis
DISTVERSION=	6.2.0
CATEGORIES=	databases

MAINTAINER=	wiacek.m@witia.com.pl
COMMENT=	Extension to access Redis
WWW=		https://pecl.php.net/package/redis

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:build,pecl
USE_PHP=	session:build

OPTIONS_DEFINE=	IGBINARY
IGBINARY_DESC=	Build with Igbinary serializer

IGBINARY_USE=			PHP=igbinary:build
IGBINARY_CONFIGURE_ENABLE=	redis-igbinary

.include <bsd.port.mk>
