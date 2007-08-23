# New ports collection makefile for:	pecl-bbcode
# Date created:			6 Aug 2007
# Whom:				Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	bbcode
PORTVERSION=	0.9.1
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ditesh@gathani.org
COMMENT=	A PECL extension which allows quick and efficient BBCode Parsing

USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--enable-bbcode

post-patch:
	@${REINPLACE_CMD} -e 's/#include <malloc.h>/\/\/#include <malloc.h>/g' ${WRKSRC}/lib/stacklib.c
	@${REINPLACE_CMD} -e 's/#include <malloc.h>/\/\/#include <malloc.h>/g' ${WRKSRC}/lib/bbcode.c

.include <bsd.port.mk>
