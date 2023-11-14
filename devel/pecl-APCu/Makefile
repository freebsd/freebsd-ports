PORTNAME=	APCu
PORTVERSION=	5.1.23
CATEGORIES=	devel
DISTNAME=	apcu-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	APC User Caching
WWW=		https://pecl.php.net/package/apcu

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase php:pecl

PHP_MODNAME=	apcu

PLIST_FILES=	${DATADIR}/apc.php

CONFLICTS_INSTALL=	pecl-APC

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/apc.php ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
