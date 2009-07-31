# New ports collection makefile for:	crack-attack
# Date created:				21 December 2003
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	crack-attack
PORTVERSION=	1.1.14
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	OpenGL game based on Super Nintendo classic Tetris Attack

USE_GL=		glut
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" CXXFLAGS="${CFLAGS}"

MAN6=		crack-attack.6

post-patch:
	@${REINPLACE_CMD} -e 's|#ifndef max|#if 0|' ${WRKSRC}/src/Game.h

.include <bsd.port.mk>
