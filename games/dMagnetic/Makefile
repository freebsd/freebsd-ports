# $FreeBSD$

PORTNAME=	dMagnetic
PORTVERSION=	0.22
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
	cd ${WRKSRC}/testcode; if [ `${ECHO_CMD} Hello | ../dMagnetic -ini ../dMagnetic.ini \
		-mag minitest.mag -gfx minitest.gfx \
		-vmode none -vecho -vcols 300 -vrows 300 | \
		sha256 ` == 0cec7b8c0972a3e135fccb01c460f3b0477ac468f9a7ac99599dd3b84b29b6e2 -a \
		`echo Hello | ../dMagnetic -ini ../dMagnetic.ini \
		-mag minitest.mag -gfx minitest.gfx \
		-vmode monochrome -vecho -vcols 300 -vrows 300 | \
		sha256 ` == 247f6fd1487a8ccbd6b765c44bce6f72aa99894c2692da622c435466f33ff006 -a \
		`echo Hello | ../dMagnetic -ini ../dMagnetic.ini \
		-mag minitest.mag -gfx minitest.gfx \
		-vmode low_ansi -vecho -vcols 300 -vrows 300 | \
		sha256 ` == e8385b520d6c85906e497226dcf34ad7f7cc7d14394481c2b8b3e293e2247903 -a \
		`echo Hello | ../dMagnetic -ini ../dMagnetic.ini \
		-mag minitest.mag -gfx minitest.gfx \
		-vmode high_ansi -vecho -vcols 300 -vrows 300 | \
		sha256 ` == 4a18aaa50f04cbc09257683780c082cd24bcf4093a65a3544236b0d754dc8fc9 -a \
		`echo Hello | ../dMagnetic -ini ../dMagnetic.ini \
		-mag minitest.mag -gfx minitest.gfx \
		-vmode sixel -vecho -vcols 300 -vrows 300 | \
		sha256 ` == 44bb9e0e6ac0461a649fc03d60e273d4e5b660b4430652828e5c58dc47f9eaba \
		]; \
		then echo ok; else echo expected output not seen; exit 1; fi

.include <bsd.port.mk>
