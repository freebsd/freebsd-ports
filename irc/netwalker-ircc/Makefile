# New ports collection makefile for:   netwalker-ircc
# Date created:        4 December 2004
# Whom:                Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	netwalker-ircc
PORTVERSION=	0.5.0
CATEGORIES=	irc
MASTER_SITES=	http://critical.ch/netwalker-ircc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A lightweight curses-based IRC client

MAN1=		netwalker.1

LDFLAGS=	-lncurses ${PTHREAD_LIBS}
CFLAGS?=	-O2 -Wall

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

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

.include <bsd.port.post.mk>
