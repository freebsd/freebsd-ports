PORTNAME=	igbinary
PORTVERSION=	3.2.16
CATEGORIES=	converters

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Replacement for the standard PHP serializer
WWW=		https://pecl.php.net/package/igbinary \
		https://github.com/igbinary/igbinary

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		php:pecl

.include <bsd.port.pre.mk>

post-patch:
.if ${PHP_VER} >= 85
	@${REINPLACE_CMD} -e 's|ext/standard/php_smart_string.h|Zend/zend_smart_string.h|' \
		${WRKSRC}/src/php7/php_igbinary.h
.endif
# Install the real header files
	@${CP} ${WRKSRC}/src/php7/igbinary.h ${WRKSRC}/igbinary.h
	@${CP} ${WRKSRC}/src/php7/php_igbinary.h ${WRKSRC}/php_igbinary.h

.include <bsd.port.post.mk>
