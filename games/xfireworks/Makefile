# New ports collection makefile for:   XFireworks
# Date created:        29 July 2000
# Whom:                Sakai Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xfireworks
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://kozos.jp/myfreesoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fireworks on X

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_XORG=	x11

MAN1=		xfireworks.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xfireworks ${PREFIX}/bin/xfireworks
	${INSTALL_MAN} ${WRKSRC}/xfireworks.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/xfireworks.conf ${PREFIX}/etc/xfireworks.conf.sample
.if !exists(${PREFIX}/etc/xfireworks.conf)
	${CP} ${PREFIX}/etc/xfireworks.conf.sample ${PREFIX}/etc/xfireworks.conf
.endif

.include <bsd.port.mk>
