# New ports collection makefile for:    quit
# Date created:                25 Aug 2003
# Whom:                        UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	quit
PORTVERSION=	1.2a
CATEGORIES?=	games
MASTER_SITES=	http://megaui.net/fukuchi/archive/shortshort/

MAINTAINER?=	umeno@rr.iij4u.or.jp
COMMENT=	A bicycle with trailers like "sl"

MAN1=		quit.1
MANLANG=	ja

PLIST_FILES=	bin/quit
PORTDOCS=	README quit.txt

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} -o ${WRKSRC}/quit ${WRKSRC}/quit.c -lncurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/quit.1 ${MAN1PREFIX}/man/ja/man1
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/quit.txt ${DOCSDIR}

.include <bsd.port.mk>
