# Created by: James Bailie <jimmy@mammothcheese.ca>
# $FreeBSD$

PORTNAME=	tetrons
PORTVERSION=	1.10
CATEGORIES=	games
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	jimmy@mammothcheese.ca
COMMENT=	Tetris(TM) clone for X11

BROKEN=		unfetchable

MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		X11BASE=${LOCALBASE}
USES=		xorg
USE_XORG=	x11 xext xi
PLIST_FILES=	bin/tetrons

.include <bsd.port.mk>
