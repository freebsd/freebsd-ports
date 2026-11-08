PORTNAME=	zstd
PORTVERSION=	0.18.0
CATEGORIES=	archivers

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compression and decompression with Zstandard library
WWW=		https://pecl.php.net/package/zstd \
		https://github.com/kjdev/php-ext-zstd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		php:pecl pkgconfig

CONFIGURE_ARGS=	--with-libzstd

OPTIONS_DEFINE=	APCU
OPTIONS_DEFAULT=APCU
APCU_DESC=	APCu serializer

APCU_CONFIGURE_ENABLE=	apcu
APCU_BUILD_DEPENDS=	${PECL_PKGNAMEPREFIX}APCu>=0:devel/pecl-APCu@${PHP_FLAVOR}
APCU_RUN_DEPENDS=	${PECL_PKGNAMEPREFIX}APCu>=0:devel/pecl-APCu@${PHP_FLAVOR}

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/zstd/

.include <bsd.port.mk>
