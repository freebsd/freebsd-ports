# New ports collection makefile for:	hunt
# Date created:				2001-02-20
# Whom:					bdluevel@heitec.net
#
# $FreeBSD$

PORTNAME=	hunt
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.heitec.net/pub/distfiles/

MAINTAINER=	bdluevel@heitec.net
COMMENT=	Rogue-like multiplayer game

MAN6=	hunt.6 huntd.6

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
