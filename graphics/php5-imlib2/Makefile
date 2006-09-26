# New ports collection makefile for:	php5-imlib2
# Date created:				18 September 2006
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	imlib2
PORTVERSION=	0.1.00
CATEGORIES=	graphics
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	php5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	The imlib2 shared extension for php

LIB_DEPENDS=	Imlib2:${PORTSDIR}/graphics/imlib2

USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=4
DEFAULT_PHP_VER=5

# libImlib2 may or may not depend on X, however,
# imlib2 extension doesn't need X related functions in libImlib2
CFLAGS+=	-DX_DISPLAY_MISSING

post-patch:
	@${REINPLACE_CMD} -e 's/-ldl//' ${WRKSRC}/config.m4
	@${REINPLACE_CMD} -e '/Xlib.h/d' ${WRKSRC}/php_imlib2.h

.include <bsd.port.mk>
