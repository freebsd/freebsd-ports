# New ports collection makefile for:	blue
# Date created:				6 June 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	blue
PORTVERSION=	2.6
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/blue/

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	# empty
MAN6=		blue.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/blue ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/blue.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
