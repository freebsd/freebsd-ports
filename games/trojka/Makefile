# New ports collection makefile for:   trojka
# Date created:        22 march 2000
# Whom:                Edwin Mons
#
# $FreeBSD$
#

PORTNAME=	trojka
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.funet.fi/pub/unix/games/
DISTNAME=	${PORTNAME}

MAINTAINER=	e@ik.nu
COMMENT=	A game of skill

MAN6=		trojka.6
SUB_FILES=	pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
