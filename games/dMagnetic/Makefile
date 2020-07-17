# $FreeBSD$

PORTNAME=	dMagnetic
PORTVERSION=	0.24
CATEGORIES=	games
MASTER_SITES=	https://www.dettus.net/dMagnetic/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	dettus@dettus.net
COMMENT=	Magnetic Scrolls Interpreter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		tar:bz2

TEST_TARGET=	do-test

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dMagnetic.1 ${STAGEDIR}${MANPREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/dMagneticini.5 ${STAGEDIR}${MANPREFIX}/share/man/man5
	${MKDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dMagnetic.ini ${STAGEDIR}/${DATADIR}
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
