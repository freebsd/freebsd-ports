PORTNAME=	igbinary
PORTVERSION=	3.2.15
CATEGORIES=	converters

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Replacement for the standard PHP serializer
WWW=		https://pecl.php.net/package/igbinary

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		php:pecl

post-patch:
# Install the real header files
	@${CP} ${WRKSRC}/src/php7/igbinary.h ${WRKSRC}/igbinary.h
	@${CP} ${WRKSRC}/src/php7/php_igbinary.h ${WRKSRC}/php_igbinary.h

.include <bsd.port.mk>
