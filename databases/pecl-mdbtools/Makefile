# New ports collection makefile for:	pecl-mdbtools
# Date created:			22 December 2007
# Whom:				Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	mdbtools
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	databases pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PECL extension for the mdbtools library

USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHP_BUILD=	yes
BUILD_DEPENDS=	${LOCALBASE}/lib/libmdb.a:${PORTSDIR}/databases/mdbtools
RUN_DEPENDS=	${LOCALBASE}/lib/libmdb.a:${PORTSDIR}/databases/mdbtools

CONFIGURE_ARGS=	--with-mdbtools=${LOCALBASE}

.include <bsd.port.mk>
