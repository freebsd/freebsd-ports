# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	APCu
PORTVERSION=	5.1.16
CATEGORIES=	devel
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	APC User Caching

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_WITH_PHP=56

CONFLICTS_INSTALL=	pecl-APC

USES=		localbase php:pecl
PHP_MODNAME=	${PORTNAME:tl}

PLIST_FILES=	${DATADIR}/apc.php

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/apc.php ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
