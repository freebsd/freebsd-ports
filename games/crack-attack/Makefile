# New ports collection makefile for:	crack-attack
# Date created:				21 December 2003
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	crack-attack
PORTVERSION=	1.1.10
CATEGORIES=	games
MASTER_SITES=	http://blackseav.bsdns5.net/~aluminum/attack/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	OpenGL game based on Super Nintendo classic Tetris Attack

LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" CXXFLAGS="${CFLAGS}"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-O6 -s|${CFLAGS}|' ${WRKSRC}/src/Makefile.in
.if ${OSVERSION} >= 502126
	@${REINPLACE_CMD} -e 's|#ifndef max|#if 0|' ${WRKSRC}/src/Game.h
.endif

.include <bsd.port.post.mk>
