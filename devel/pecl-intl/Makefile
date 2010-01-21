# New ports collection makefile for:	pecl-intl
# Date created:			June 28, 2008
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	intl
PORTVERSION=	1.1.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PECL extension to support Internationalization(ICU)

BUILD_DEPENDS=	${LOCALBASE}/bin/icu-config:${PORTSDIR}/devel/icu

USE_PHP=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>
