# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	netwalker-ircc
PORTVERSION=	0.5.0
CATEGORIES=	irc
MASTER_SITES=	CRITICAL
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Lightweight curses-based IRC client

LICENSE=	GPLv2

MAN1=		netwalker.1

LDFLAGS+=	-lncurses ${PTHREAD_LIBS}
CFLAGS?=	-O2 -Wall

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
	${WRKSRC}/config.h > ${WRKSRC}/config.h.freebsd
	${MV} ${WRKSRC}/config.h.freebsd ${WRKSRC}/config.h

do-build:
.for file in main functions screen server user messages signals parameter userdb
	${CXX} ${CFLAGS} -c ${WRKSRC}/${file}.cc -o ${WRKSRC}/${file}.o
.endfor
	${CXX} ${LDFLAGS} -L${WRKSRC}/ ${WRKSRC}/*.o -o ${WRKSRC}/netwalker

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netwalker ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/netwalker.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/help/* ${PREFIX}/share/netwalker-ircc

.include <bsd.port.mk>
