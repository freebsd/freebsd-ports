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

USE_XORG=	x11 xpm xext

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xroads ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/xroads
.for file in 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18
	${INSTALL_DATA} ${WRKSRC}/map${file}.xrm ${PREFIX}/share/xroads
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xroads
.for file in BUGS CHANGELOG README
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xroads
.endfor
.endif

.include <bsd.port.post.mk>
