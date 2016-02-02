# Created by: UMENO Takashi <umeno@rr.iij4u.or.jp>
# $FreeBSD$

PORTNAME=	quit
PORTVERSION=	1.2a
PORTREVISION=	1
CATEGORIES?=	games
MASTER_SITES=	http://megaui.net/fukuchi/archive/shortshort/

MAINTAINER?=	meta+ports@vmeta.jp
COMMENT=	Bicycle with trailers like "sl"

MANLANG=	ja

USES=		ncurses

OPTIONS_DEFINE=	DOCS

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} -o ${WRKSRC}/quit \
		${WRKSRC}/quit.c ${LDFLAGS} -lncurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/quit.1 ${STAGEDIR}${MAN1PREFIX}/man/ja/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/quit.txt \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
