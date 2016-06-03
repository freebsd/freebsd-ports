# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xroads
PORTVERSION=	0.6
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://math.missouristate.edu/~erik/files/fbsd/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Commodore 64 "Crossroads"-like video game for X Window System

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
USE_XORG=	x11 xpm xext

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xroads ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xroads
.for file in 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18
	${INSTALL_DATA} ${WRKSRC}/map${file}.xrm ${STAGEDIR}${PREFIX}/share/xroads
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/xroads
.for file in BUGS CHANGELOG README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/share/doc/xroads
.endfor

.include <bsd.port.mk>
