# ex:ts=8
# Ports collection makefile for:  braincurses
# Date created:		Wed Jan 15, 2003
# Whom:			Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	braincurses
PORTVERSION=	0.2
CATEGORIES=	games
MASTER_SITES=	http://uhaweb.hartford.edu/hyland/derr/

MAINTAINER=	mich@freebsdcluster.org

LDFLAGS+=	-lncurses
WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	cd ${WRKSRC} && \
	${CXX} -c -o curses/windows.o curses/windows.cpp && \
	${CXX} ${CFLAGS} -c ${PORTNAME}.cpp && \
	${CXX} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} curses/windows.o ${PORTNAME}.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
