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

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/zstd/

.include <bsd.port.mk>
