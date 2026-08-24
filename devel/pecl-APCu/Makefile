PORTNAME=	APCu
PORTVERSION=	5.1.28
CATEGORIES=	devel
DISTNAME=	apcu-${PORTVERSION}

PATCH_SITES=	https://github.com/krakjoe/apcu/commit/
PATCHFILES=	90899684be91c4f750512c2f840f487286ecb807.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	APC User Caching
WWW=		https://pecl.php.net/package/apcu \
		https://github.com/krakjoe/apcu

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase php:pecl

PHP_MODNAME=	apcu

PLIST_FILES=	${DATADIR}/apc.php

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/apc.php ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
