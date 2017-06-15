# Created by: Kris Kennaway <kkennawa@physics.adelaide.edu.au>
# $FreeBSD$

PORTNAME=	wmMoonClock
PORTVERSION=	1.27
PORTREVISION=	3
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://www.cs.mun.ca/~gstarkes/wmaker/dockapps/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays the phase of the moon, plus orbital data

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${DISTNAME}/Src

USE_XORG=	xpm
USES=		gmake

PLIST_FILES=	bin/wmmoonclock man/man1/wmmoonclock.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmMoonClock ${STAGEDIR}${PREFIX}/bin/wmmoonclock
	${INSTALL_MAN} ${WRKSRC}/wmMoonClock.1 ${STAGEDIR}${PREFIX}/man/man1/wmmoonclock.1

.include <bsd.port.mk>
