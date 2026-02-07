PORTNAME=	bzip3
DISTVERSION=	0.1.1
CATEGORIES=	archivers
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	pkaipila@gmail.com
COMMENT=	BZip3 extension for PHP
WWW=		https://github.com/kjdev/php-ext-bzip3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbzip3.so:archivers/bzip3

USES=		localbase php:ext pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	kjdev
GH_PROJECT=	php-ext-bzip3

CONFIGURE_ARGS=	--with-libbzip3

.include <bsd.port.mk>
