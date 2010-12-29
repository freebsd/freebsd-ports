# New ports collection makefile for:	pecl-intl
# Date created:			June 28, 2008
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	intl
PORTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PECL extension to support Internationalization(ICU)

LIB_DEPENDS=	icui18n.46:${PORTSDIR}/devel/icu

LICENSE=	PHP301

USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=4

.include <bsd.port.mk>
