# New ports collection makefile for:    quit
# Date created:                25 Aug 2003
# Whom:                        UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	quit
PORTVERSION=	1.02
CATEGORIES?=	games
MASTER_SITES=	http://megaui.net/fukuchi/archive/shortshort/
DISTNAME=	${PORTNAME}

MAINTAINER?=	umeno@rr.iij4u.or.jp
COMMENT=	A bicycle with trailers like "sl"

MAN1=		quit.1
MANLANG=	ja

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} -o ${WRKSRC}/quit ${WRKSRC}/quit.c -lncurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/quit.1 ${PREFIX}/man/ja/man1
	${MKDIR} ${PREFIX}/share/doc/quit
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/quit
	${INSTALL_DATA} ${WRKSRC}/quit.txt ${PREFIX}/share/doc/quit

.include <bsd.port.mk>
