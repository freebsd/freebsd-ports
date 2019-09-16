# Created by: Chris D. Faulhaber <jedgar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xinvaders3d
DISTVERSION=	1.3.6
DISTVERSIONSUFFIX=	.src
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/arcade/invaders/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D Vector-graphics Space Invaders clone for X

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${FONTDIR}/misc/10x20.pcf.gz:x11-fonts/font-misc-misc

USES=		xorg
USE_XORG=	x11

PLIST_FILES=	bin/xinv3d
WRKSRC=		${WRKDIR}/${PORTNAME}
FONTDIR=	${LOCALBASE}/share/fonts

DESKTOP_ENTRIES="XInvaders 3D" "Space Invaders clone for X" "xorg" \
		"xinv3d" "ArcadeGame;Game;" false

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xinv3d ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
