# New ports collection makefile for:	galaxis
# Date created:				30 June 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	galaxis
PORTVERSION=	1.7
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/galaxis/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clone of the nifty little Macintosh game

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DNDEBUG"
ALL_TARGET=	${PORTNAME}

MAN6=		galaxis.6
PLIST_FILES=	bin/galaxis

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/galaxis ${PREFIX}/bin/galaxis
	${INSTALL_MAN} ${WRKSRC}/galaxis.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
