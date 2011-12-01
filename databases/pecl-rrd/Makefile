# New ports collection makefile for:	pecl-rrd
# Date created:		2011-03-28
# Whom:			Florian Smeets <flo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rrd
DISTVERSION=	1.0.5
CATEGORIES=	databases pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	flo@FreeBSD.org
COMMENT=	PHP bindings to rrd tool system

LIB_DEPENDS=	rrd:${PORTSDIR}/databases/rrdtool

LDFLAGS+=	-L${LOCALBASE}/lib

LICENSE=	PHP301

USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=4

.include <bsd.port.mk>
