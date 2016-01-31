# Created by: Kyle Martin <mkm@ieee.org>
# $FreeBSD$

PORTNAME=	duhdraw
PORTVERSION=	2.8.13
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.helsinki.fi/u/penberg/duhdraw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ANSI graphic drawing program

USES=		ncurses

MAKE_ARGS=	CC="${CC} ${CFLAGS}"

PLIST_FILES=	bin/ansi bin/ansitoc bin/duhdraw

post-patch:
	@${REINPLACE_CMD} -e '/<malloc.h>/d' ${WRKSRC}/duhdraw.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ansi ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ansitoc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/duhdraw ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
