# New ports collection makefile for:	pecl-phar
# Date created:			6 Aug 2007
# Whom:				Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	phar
DISTVERSION=	2.0.0RC2
CATEGORIES=	archivers pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PECL extension which allows running applications out of .phar files

USE_PHP=	hash spl pcre
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
CFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"

OPTIONS=	BZ2		"Enable bz2 compression support" off \
		ZLIB		"Enable gzip compression support" off

.include <bsd.port.pre.mk>

.if defined(WITH_BZ2) && !defined(WITHOUT_BZ2)
USE_PHP+=	bz2
.endif

.if defined(WITH_ZLIB) && !defined(WITHOUT_ZLIB)
USE_PHP+=	zlib
.endif

CONFIGURE_ARGS=	--enable-phar

.include <bsd.port.post.mk>
