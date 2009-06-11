# New ports collection makefile for:	pecl-spread
# Date created:			10 June 2008
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	spread
PORTVERSION=	2.1.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Php Interface to the Spread Toolkit API

BUILD_DEPENDS=	${LOCALBASE}/include/sp.h:${PORTSDIR}/net/spread4

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS+=--with-spread=${LOCALBASE}

.include <bsd.port.mk>
