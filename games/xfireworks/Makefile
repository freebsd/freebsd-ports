# New ports collection makefile for:   XFireworks
# Date created:        29 July 2000
# Whom:                Sakai Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xfireworks
PORTVERSION=	1.3
CATEGORIES=	games
MASTER_SITES=	http://www.seki.ee.kagu.tus.ac.jp/~sakai/myfreesoft/ \
		http://hp.vector.co.jp/authors/VA014157/myfreesoft/ \
		http://www.people.or.jp/~hsakai/myfreesoft/

MAINTAINER=	sakai@seki.ee.kagu.tus.ac.jp
COMMENT=	Fireworks on X

USE_X_PREFIX=	yes

MAN1=		xfireworks.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xfireworks ${PREFIX}/bin/xfireworks
	${INSTALL_MAN} ${WRKSRC}/xfireworks.1 ${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/xfireworks.conf ${PREFIX}/etc/xfireworks.conf.sample
.if !exists(${PREFIX}/etc/xfireworks.conf)
	${CP} ${PREFIX}/etc/xfireworks.conf.sample ${PREFIX}/etc/xfireworks.conf
.endif

.include <bsd.port.mk>
