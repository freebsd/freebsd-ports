# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	dav
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://download.pureftpd.org/php-webdav/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTNAME=	php-webdav-${PORTVERSION}

MAINTAINER=	komarov@valerka.net
COMMENT=	The PHP WebDAV extension

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	ISCL

LIB_DEPENDS=	libneon.so:www/neon

USES=		php:ext

IGNORE_WITH_PHP=	71 72 73

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
