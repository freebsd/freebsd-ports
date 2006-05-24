# ex:ts=8
# Ports collection makefile for:  nibbles
# Date created:		Tue Jul 15, 2002
# Whom:			Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	nibbles
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Nibbles is a simple ncurses-based console game

LDFLAGS+=	-L${LOCALBASE}/lib -lncurses
CFLAGS+=	-Wall
USE_GCC=	2.7+

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -c -o main.o main.c)
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -c -o misc.o misc.c)
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -c -o screen.o screen.c)
	(cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} main.o misc.o screen.o)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
