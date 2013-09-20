# Created by: UMENO Takashi <umeno@rr.iij4u.or.jp>
# $FreeBSD$

PORTNAME=	quit
PORTVERSION=	1.2a
PORTREVISION=	1
CATEGORIES?=	games
MASTER_SITES=	http://megaui.net/fukuchi/archive/shortshort/

MAINTAINER?=	umeno@rr.iij4u.or.jp
COMMENT=	A bicycle with trailers like "sl"

MAN1=		quit.1
MANLANG=	ja

PLIST_FILES=	bin/quit
PORTDOCS=	README quit.txt

NO_STAGE=	yes
do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} -o ${WRKSRC}/quit ${WRKSRC}/quit.c -lncurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/quit.1 ${MAN1PREFIX}/man/ja/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/quit.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
