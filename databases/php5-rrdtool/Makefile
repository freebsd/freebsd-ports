# New ports collection makefile for:	php5-rrdtool
# Date created:				19 Mar 2006
# Whom:					rick@wzoeterwoude.net
# Credits:				mat
#
# $FreeBSD$

PORTNAME=	rrdtool
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://oss.oetiker.ch/rrdtool/pub/contrib/ \
		http://ftp.ntua.gr/pub/net/monitoring/rrdtool/contrib/ \
		http://www.mirrors.wiretapped.net/security/network-monitoring/rrdtool/contrib/
PKGNAMEPREFIX=	php5-
DISTNAME=	php_rrdtool

MAINTAINER=	rick@wzoeterwoude.net
COMMENT=	A php 5 rrdtool glue

LIB_DEPENDS=	rrd:${PORTSDIR}/databases/rrdtool

WRKSRC=		${WRKDIR}/rrdtool

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5

DEPRECATED=		deprecated via upstream please use databases/pecl-rrd.
EXPIRATION_DATE=	2012-06-30

.include <bsd.port.mk>
