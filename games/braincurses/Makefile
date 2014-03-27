# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	braincurses
PORTVERSION=	0.5a
CATEGORIES=	games
MASTER_SITES=	http://freebsdcluster.org/~mich/software/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A clone of the Mastermind game

LDFLAGS+=	-lncurses
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && \
	${CXX} -c -o curses/windows.o curses/windows.cpp && \
	${CXX} ${CFLAGS} -c ${PORTNAME}.cpp && \
	${CXX} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} curses/windows.o ${PORTNAME}.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
