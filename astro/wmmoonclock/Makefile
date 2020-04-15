# Created by: Kris Kennaway <kkennawa@physics.adelaide.edu.au>
# $FreeBSD$

PORTNAME=	wmmoonclock
PORTVERSION=	1.29
CATEGORIES=	astro windowmaker
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	mbeis@xs4all.nl
COMMENT=	Displays the phase of the moon, plus orbital data

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		autoreconf:build pkgconfig xorg
USE_XORG+=	x11 xext xpm

PLIST_FILES=	bin/wmmoonclock man/man1/wmmoonclock.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmmoonclock ${STAGEDIR}${PREFIX}/bin/wmmoonclock
	${INSTALL_MAN} ${WRKSRC}/src/wmMoonClock.1 ${STAGEDIR}${PREFIX}/man/man1/wmmoonclock.1

.include <bsd.port.mk>
