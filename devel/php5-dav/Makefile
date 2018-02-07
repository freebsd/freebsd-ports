# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	dav
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://download.pureftpd.org/php-webdav/
PKGNAMEPREFIX=	php5-
DISTNAME=	php-webdav-${PORTVERSION}

MAINTAINER=	komarov@valerka.net
COMMENT=	The PHP WebDAV extension

LICENSE=	ISCL

LIB_DEPENDS=	libneon.so:www/neon

USES=		php:ext

IGNORE_WITH_PHP=	70 71 72

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
