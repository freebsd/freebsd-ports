# Ports collection Makefile for:	glmaze
# Date created:				5 June 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	glmaze
PORTVERSION=	1.1a
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiplayer OpenGL Maze Game

USE_SDL=	mixer sdl
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

MAN1=		glmaze.1

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/shot.c

.include <bsd.port.mk>
