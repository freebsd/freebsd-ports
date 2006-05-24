# New ports collection makefile for:	pecl-zip
# Date created:			9 Jul 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zip
PORTVERSION=	1.3.1
CATEGORIES=	archivers pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PECL extension to create and read zip files

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--enable-zip --with-zlib-dir=/usr

.include <bsd.port.mk>
