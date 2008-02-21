# New ports collection makefile for:	deal
# Date created:				Apr 2, 2001
# Whom:					Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	deal
PORTVERSION=	2.4
CATEGORIES=	games
MASTER_SITES=	http://catb.org/~esr/deal/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A calculator for card-draw probabilities

MAN1=		deal.1
PLIST_FILES=	bin/deal

CFLAGS+=	-lm

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o deal deal.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deal ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/deal.1 ${PREFIX}/man/man1

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not compile on ia64
.endif

.include <bsd.port.post.mk>
