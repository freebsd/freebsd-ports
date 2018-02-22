# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	netwalker-ircc
PORTVERSION=	0.5.0
CATEGORIES=	irc
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Lightweight curses-based IRC client

LICENSE=	GPLv2

USES=		ncurses tar:tgz

LDFLAGS+=	-lncurses -lpthread

.include <bsd.port.pre.mk>

# does not compile with clang 6.0.0
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200056
USE_GCC=	yes
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
	${INSTALL_PROGRAM} ${WRKSRC}/netwalker ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/netwalker.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/help/* ${STAGEDIR}${PREFIX}/share/netwalker-ircc

.include <bsd.port.post.mk>
