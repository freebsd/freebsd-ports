# New ports collection makefile for:	greed
# Date created:			Apr 2, 2001
# Whom:				Mark Pulford «mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	greed
PORTVERSION=	3.5
CATEGORIES=	games
MASTER_SITES=	http://catb.org/~esr/greed/
PKGNAMESUFFIX=	-game

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A text puzzle game with the aim of clearing the game field

ALL_TARGET=	greed
MAN6=		greed.6
PLIST_FILES=	bin/greed

do-install:
	${INSTALL_PROGRAM} -m 2555 -o root -g games ${WRKSRC}/greed ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/greed.6 ${PREFIX}/man/man6
	${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
