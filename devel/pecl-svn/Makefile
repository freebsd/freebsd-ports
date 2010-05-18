# New ports collection makefile for:	pecl-svn
# Date created:			20051220
# Whom:				Alex Kiesel <kiesel@schlund.de>
#
# $FreeBSD$
#

PORTNAME=	svn
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	svn-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PECL extension to the libsvn library

LIB_DEPENDS=	svn_client-1:${PORTSDIR}/devel/subversion

USE_PHP=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>
