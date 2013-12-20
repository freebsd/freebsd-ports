# Created by: Jens Rehsack <rehsack@liwing.de>
# $FreeBSD$

PORTNAME=	xdebug
PORTVERSION=	2.2.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.xdebug.org/files/
PKGNAMEPREFIX=	php-
EXTRACT_SUFX=	.tgz

MAINTAINER=	freebsd-ports-maintainers@intermedix.com
COMMENT=	Xdebug extension for PHP

LICENSE=	BSD

CONFIGURE_ARGS=	--enable-xdebug
USE_PHP=	yes
USE_PHPIZE=	yes
USE_ZENDEXT=	yes
SUB_FILES=	pkg-message

PKGMESSAGE=	${WRKDIR}/pkg-message

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
