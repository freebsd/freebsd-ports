# New ports collection makefile for:	deal
# Date created:				Apr 2, 2001
# Whom:					Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	deal
PORTVERSION=	2.1
CATEGORIES=	games
MASTER_SITES=	http://www.tuxedo.org/~esr/deal/

MAINTAINER=	mark@kyne.com.au

ALL_TARGET=	deal
MAN1=		deal.1

pre-build:
	${PERL} -pi -e "s@-g@${CFLAGS}@g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deal ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/deal.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
