# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	braincurses
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Clone of the Mastermind game

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake ncurses
USE_CSTD=	c++11

USE_GITHUB=	yes
GH_ACCOUNT=	bderrly

LDFLAGS+=	-L${LOCALBASE}/lib -lncurses

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && \
	${CXX} ${CFLAGS} -c -o main.o main.cpp && \
	${CXX} ${CFLAGS} -c -o code.o code.cpp && \
	${CXX} ${CFLAGS} -c -o braincurses.o braincurses.cpp && \
	${CXX} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} code.o ${PORTNAME}.o main.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README.md

.include <bsd.port.mk>
