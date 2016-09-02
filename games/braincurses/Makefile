# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	braincurses
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Clone of the Mastermind game

LICENSE=	GPLv2

USES=		gmake ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	bderrly

#LDFLAGS+=	-L${LOCALBASE}/lib -lncurses

OPTIONS_DEFINE=	DOCS

#do-build:
#	cd ${WRKSRC} && \
#	${CXX} -c -o main.o code.o braincurses.o && \
#	${CXX} ${CFLAGS} -c ${PORTNAME}.cpp && \
#	${CXX} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} windows/windows.o ${PORTNAME}.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README.md

.include <bsd.port.mk>
