# New ports collection makefile for:	pecl-imlib2
# Date created:				18 September 2006
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	imlib2
PORTVERSION=	0.1.00
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A PECL extension if imlib2

USE_PHP=	yes
USE_PHPEXT=	yes
USE_EFL=	imlib2

# libImlib2 may or may not depend on X, however,
# imlib2 extension doesn't need X related functions in libImlib2
CFLAGS+=	-DX_DISPLAY_MISSING

post-patch:
	@${REINPLACE_CMD} -e 's/-ldl//' ${WRKSRC}/config.m4
	@${REINPLACE_CMD} -e '/Xlib.h/d' ${WRKSRC}/php_imlib2.h

.include <bsd.port.mk>
