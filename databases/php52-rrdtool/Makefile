# New ports collection makefile for:	php5-rrdtool
# Date created:				27 Nov 2011
# Whom:					scheidell@freebsd.org
# Credits:				rick@wzoeterwoude.net
#
# $FreeBSD$

PORTNAME=	rrdtool
PORTVERSION=	1.00
CATEGORIES=	databases
MASTER_SITES=	http://oss.oetiker.ch/rrdtool/pub/contrib/ \
		http://ftp.ntua.gr/pub/net/monitoring/rrdtool/contrib/ \
		http://www.mirrors.wiretapped.net/security/network-monitoring/rrdtool/contrib/
PKGNAMEPREFIX=	php52-
DISTNAME=	php_rrdtool

MAINTAINER=	scheidell@secnap.net
COMMENT=	A php 52 rrdtool glue

LIB_DEPENDS=	rrd:${PORTSDIR}/databases/rrdtool

WRKSRC=		${WRKDIR}/rrdtool

USE_PHP=	yes
DEFAULT_PHP_VER=52
USE_PHPEXT=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not configure on 6.X
.endif

.include <bsd.port.post.mk>
