# New ports collection makefile for:	blue
# Date created:				6 June 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	blue
PORTVERSION=	2.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/bluemoon/
DISTNAME=	bluemoon-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Blue Moon card solitaire

USE_GMAKE=	yes
ALL_TARGET=	bluemoon

MAN6=		bluemoon.6
MLINKS=		bluemoon.6 blue.6

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS?=|g ; \
		 s|cc |$$(CC) |g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bluemoon ${PREFIX}/bin
	@${LN} -sf bluemoon ${PREFIX}/bin/blue
	${INSTALL_MAN} ${WRKSRC}/bluemoon.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
