# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	nibbles
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Nibbles is a simple ncurses-based console game

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
LDFLAGS+=	-L${LOCALBASE}/lib -lncurses
CFLAGS+=	-Wall

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -c -o main.o main.c)
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -c -o misc.o misc.c)
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -c -o screen.o screen.c)
	(cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} main.o misc.o screen.o)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
