# New ports collection makefile for:	pecl-zip
# Date created:			9 Jul 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zip
PORTVERSION=	1.0
CATEGORIES=	archivers pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PECL extension to read zip files

LIB_DEPENDS=	zzip.10:${PORTSDIR}/devel/zziplib

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-zip=${LOCALBASE}

.include <bsd.port.mk>
