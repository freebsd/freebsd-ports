# Ports collection makefile for:  pear-File_DNS
# Date created:		03 July 2007
# Whom:			Chris St Denis (<chris@ctgameinfo.com>)
#
# $FreeBSD$
#

PORTNAME=	File_DNS
PORTVERSION=	0.0.8
CATEGORIES=	dns devel pear

MAINTAINER=	chris@ctgameinfo.com
COMMENT=	PEAR class to read and write RFC1033-style DNS Zonefiles

BUILD_DEPENDS=	${PEARDIR}/File.php:${PORTSDIR}/sysutils/pear-File
RUN_DEPENDS=	${PEARDIR}/File.php:${PORTSDIR}/sysutils/pear-File

CATEGORY=	File
FILES=		DNS.php
EXAMPLES=	example.php example.net

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
