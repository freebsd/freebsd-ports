# New ports collection makefile for:	bs
# Date created:				11 May 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	bs
PORTVERSION=	2.7
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/bs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Battleships solitaire game with a color interface

MAKE_ARGS=	CC="${CC}"
ALL_TARGET=	# empty

MAN6=		bs.6
PLIST_FILES=	bin/bs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bs.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
