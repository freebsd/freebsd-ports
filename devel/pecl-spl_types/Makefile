# New ports collection makefile for:	pecl-spl_types
# Date created:			15 Jan 2007
# Whom:				Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	spl_types
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	SPL_Types-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A PECL extension of a collection of special typehandling classes

USE_PHP=	spl
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	spl_types

CONFIGURE_ARGS=	--enable-spl-types
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
