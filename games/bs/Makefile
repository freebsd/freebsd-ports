# New ports collection makefile for:	bs
# Date created:				11 May 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	bs
PORTVERSION=	2.4
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/bs/

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	# empty
MAN6=		bs.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bs.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
