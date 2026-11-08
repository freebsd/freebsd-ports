PORTNAME=	igbinary-session
DISTVERSION=	3.2.16
CATEGORIES=	converters
DISTNAME=	igbinary-${DISTVERSION}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Replacement for the standard PHP serializer (+session support)
WWW=		https://pecl.php.net/package/igbinary \
		https://github.com/igbinary/igbinary

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PECL_PKGNAMEPREFIX}APCu>=0:devel/pecl-APCu@${PHP_FLAVOR}

USES=		php:pecl
USE_PHP=	session:build

PHP_MODNAME=	igbinary

CONFLICTS=	pecl-igbinary

post-patch:
	@${CP} ${WRKSRC}/src/php7/igbinary.h ${WRKSRC}/igbinary.h
	@${CP} ${WRKSRC}/src/php7/php_igbinary.h ${WRKSRC}/php_igbinary.h

.include <bsd.port.mk>
