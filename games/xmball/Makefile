# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xmball
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Masterball puzzle for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		imake
USE_XORG=	x11 xext xt sm ice

PLIST_FILES=	bin/xmball \
		man/man1/xmball.1.gz \
		lib/X11/app-defaults/Mball

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmball ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Mball.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Mball
	${INSTALL_MAN} ${WRKSRC}/xmball.man ${STAGEDIR}${MANPREFIX}/man/man1/xmball.1

.include <bsd.port.mk>
