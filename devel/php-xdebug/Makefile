# Created by: Jens Rehsack <rehsack@liwing.de>
# $FreeBSD$

PORTNAME=	xdebug
PORTVERSION=	2.2.3
CATEGORIES=	devel
MASTER_SITES=	http://www.xdebug.org/files/
PKGNAMEPREFIX=	php-
EXTRACT_SUFX=	.tgz

MAINTAINER=	freebsd-ports-maintainers@intermedix.com
COMMENT=	Xdebug extension for PHP

LICENSE=	BSD

CONFIGURE_ARGS=	--enable-xdebug
USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
SUB_FILES=	pkg-message

PKGMESSAGE=	${WRKDIR}/pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
