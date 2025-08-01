PORTNAME=	zstd
PORTVERSION=	0.14.0
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

.include <bsd.port.pre.mk>

post-patch:
.if ${PHP_VER} >= 85
	${REINPLACE_CMD} -e 's|ext/standard/php_smart_string|Zend/zend_smart_string|' \
		${WRKSRC}/zstd.c
.endif
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/zstd/

.include <bsd.port.post.mk>
