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
MASTER_SITES=	http://hp.vector.co.jp/authors/VA014157/myfreesoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fireworks on X

USE_XORG=	x11
MAN1=		xfireworks.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xfireworks ${PREFIX}/bin/xfireworks
	${INSTALL_MAN} ${WRKSRC}/xfireworks.1 ${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/xfireworks.conf ${PREFIX}/etc/xfireworks.conf.sample
.if !exists(${PREFIX}/etc/xfireworks.conf)
	${CP} ${PREFIX}/etc/xfireworks.conf.sample ${PREFIX}/etc/xfireworks.conf
.endif

.include <bsd.port.mk>
