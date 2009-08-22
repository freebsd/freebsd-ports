# New ports collection makefile for:	php-dbg2
# Date created:		19 July 2007
# Whom:			Josh Paetzel <josh@tcbug.org>
#
# $FreeBSD$
#

PORTNAME=	dbg2
PORTVERSION=	2.15.5
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/dbg/${PORTVERSION}
PKGNAMEPREFIX=	php-
DISTNAME=	dbg-${PORTVERSION}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Debugger for PHP

USE_PHP=	yes
USE_PHPIZE=	yes
DEFAULT_PHP_VER=5
CONFIGURE_ARGS=	--enable-dbg=shared --with-dbg-profiler \
		--with-php-config=${PREFIX}/bin/php-config \
		--prefix=${PREFIX}/lib/php/${PHP_EXT_DIR}
PKGMESSAGE=	pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
