# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	dav
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	http://download.pureftpd.org/php-webdav/
PKGNAMEPREFIX=	php5-
DISTNAME=	php-webdav-${PORTVERSION}

MAINTAINER=	komarov@valerka.net
COMMENT=	The PHP WebDAV extension

LICENSE=	BSD

LIB_DEPENDS=	neon.27:${PORTSDIR}/www/neon29

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	dav

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.mk>
