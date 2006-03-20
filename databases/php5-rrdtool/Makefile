# New ports collection makefile for:	php5-rrdtool
# Date created:				19 Mar 2006
# Whom:					rick@wzoeterwoude.net
# Credits:				mat
#
# $FreeBSD$

PORTNAME=	rrdtool
PORTVERSION=	1.00
CATEGORIES=	net
MASTER_SITES=	http://people.ee.ethz.ch/~oetiker/webtools/rrdtool/pub/contrib/ \
		http://ftp.ntua.gr/pub/net/monitoring/rrdtool/contrib/ \
		http://www.mirrors.wiretapped.net/security/network-monitoring/rrdtool/contrib/
PKGNAMEPREFIX=	php5-
DISTNAME=	php_rrdtool
EXTRACT_SUFX=	.tgz

MAINTAINER=	rick@wzoeterwoude.net
COMMENT=	A php 5 rrdtool glue

LIB_DEPENDS=	rrd:${PORTSDIR}/net/rrdtool

WRKSRC=		${WRKDIR}/rrdtool

USE_PHP=	yes
DEFAULT_PHP_VER=5
USE_PHPEXT=	yes

.include <bsd.port.mk>
