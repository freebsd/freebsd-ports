# Created by: Sakai Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
# $FreeBSD$

PORTNAME=	nadar
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://ftp.vector.co.jp/pack/unix/game/action/

MAINTAINER=	hsakai@m8.ffn.ne.jp
COMMENT=	Network tank battle game

BROKEN=		unfetchable

MAKE_ENV=	X11BASE=${LOCALBASE}
USES=		xorg
USE_XORG=	xpm
MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nadar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nadars ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nadar.1.gz ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nadars.1.gz ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
