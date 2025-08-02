PORTNAME=	zstd
DISTVERSION=	0.14.0
CATEGORIES=	archivers
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	pave@FreeBSD.org
COMMENT=	Zstandard extension for PHP
WWW=		https://github.com/kjdev/php-ext-zstd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		php:ext pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	kjdev
GH_PROJECT=	php-ext-zstd

CONFIGURE_ARGS=	--with-libzstd

.include <bsd.port.pre.mk>

post-patch:
.if ${PHP_VER} >= 85
	@${REINPLACE_CMD} -e 's|ext/standard/php_smart_string|Zend/zend_smart_string|' \
		${WRKSRC}/zstd.c
.endif

.include <bsd.port.post.mk>
