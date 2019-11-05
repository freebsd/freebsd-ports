# Created by: Sakai Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
# $FreeBSD$

PORTNAME=	xfireworks
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://kozos.jp/myfreesoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fireworks on X

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		xorg
USE_XORG=	x11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xfireworks ${STAGEDIR}${PREFIX}/bin/xfireworks
	${INSTALL_MAN} ${WRKSRC}/xfireworks.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/xfireworks.conf ${STAGEDIR}${PREFIX}/etc/xfireworks.conf.sample

.include <bsd.port.mk>
