PORTNAME=	redis
DISTVERSION=	6.3.0
CATEGORIES=	databases

MAINTAINER=	wiacek.m@witia.com.pl
COMMENT=	Extension to access Redis
WWW=		https://pecl.php.net/package/redis

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:build,pecl
USE_PHP=	session:build

OPTIONS_DEFINE=		IGBINARY LZ4 ZSTD
OPTIONS_DEFAULT=	LZ4 ZSTD

IGBINARY_DESC=	Build with Igbinary serializer
LZ4_DESC=	Build with lz4 support
ZSTD_DESC=	Build with zstd support

IGBINARY_USE=			PHP=igbinary:build
IGBINARY_CONFIGURE_ENABLE=	redis-igbinary

LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_CONFIGURE_ON=	--enable-redis-lz4 \
			--with-liblz4=${LOCALBASE}

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_CONFIGURE_ON=	--enable-redis-zstd \
			--with-libzstd=${LOCALBASE}

.include <bsd.port.mk>
