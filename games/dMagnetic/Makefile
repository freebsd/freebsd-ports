# $FreeBSD$

PORTNAME=	dMagnetic
PORTVERSION=	0.21
CATEGORIES=	games
MASTER_SITES=	https://www.dettus.net/dMagnetic/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	dettus@dettus.net
COMMENT=	Magnetic Scrolls Interpreter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		tar:bz2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dMagnetic.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/dMagneticini.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${MKDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dMagnetic.ini ${STAGEDIR}/${DATADIR}
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}/${DOCSDIR}

do-test:
	cd ${WRKSRC}/testcode; if [ `${ECHO_MSG} Hello | ../dMagnetic \
	-mag minitest.mag -gfx minitest.gfx \
	-vmode high_ansi -vecho -vcols 300 -vrows 300 | \
	sha256 ` == e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855 ]; \
	then echo ok; else echo expected output not seen; exit 1; fi

.include <bsd.port.mk>
