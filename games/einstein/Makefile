# New ports collection makefile for:	einstein
# Date created:				30 january 2005
# Whom:					edwin@mavetju.org
#
# $FreeBSD$
#

PORTNAME=	einstein
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.babichev.info/files/einstein/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	edwin@mavetju.org
COMMENT=	Remake of old DOS game Sherlock, which was inspired by Albert Einstein's puzzle.

USE_SDL=	sdl ttf
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
