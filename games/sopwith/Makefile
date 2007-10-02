# New ports collection makefile for:	sopwith
# Date created:			1 July 2002
# Whom:				Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	sopwith
PORTVERSION=	1.7.1
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sdl-sopwith
DISTNAME=	sdl_${PORTNAME}-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	A classic WW1 biplane game

USE_SDL=	sdl
USE_GMAKE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

MAN6=		sopwith.6

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
