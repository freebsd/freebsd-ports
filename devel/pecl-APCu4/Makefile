# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	APCu
PORTVERSION=	4.0.11
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	APC User Caching

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

CONFLICTS_INSTALL=	pecl-APC

PORTSCOUT=	limit:^4\.

IGNORE_WITH_PHP=71 72 73
USES=		localbase php:pecl
PHP_MODNAME=	${PORTNAME:tl}

PLIST_FILES=	${DATADIR}/apc.php

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/apc.php ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
