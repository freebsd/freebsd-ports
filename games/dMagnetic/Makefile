# $FreeBSD$

PORTNAME=	dMagnetic
PORTVERSION=	0.23
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
		sha256 ` == 70af45367a6ad1b612ceabd36fef309d4258abac275281a5541342ccf0a765cd -a \
		`${ECHO_CMD} Hello | ../dMagnetic -ini ../dMagnetic.ini \
		-mag minitest.mag -gfx minitest.gfx \
		-vmode monochrome -vecho -vcols 300 -vrows 300 | \
		sha256 ` == b1e0f1b9fb7ade27960b23a0bbf195d6b57713bc91397792fab0bd700e882fb6 -a \
		`${ECHO_CMD} Hello | ../dMagnetic -ini ../dMagnetic.ini \
		-mag minitest.mag -gfx minitest.gfx \
		-vmode monochrome_inv -vecho -vcols 300 -vrows 300 | \
		sha256 ` == 31fa692260d66e4c884cd378f4d556948fa2cac993a222735b50fe77d5e42f74 -a \
		`${ECHO_CMD} Hello | ../dMagnetic -ini ../dMagnetic.ini \
		-mag minitest.mag -gfx minitest.gfx \
		-vmode low_ansi -vecho -vcols 300 -vrows 300 | \
		sha256 ` == 0305fe17144310c4759a2fc23f78e7f3975603d525b64a1ecc79fb86628523c9 -a \
		`${ECHO_CMD} Hello | ../dMagnetic -ini ../dMagnetic.ini \
		-mag minitest.mag -gfx minitest.gfx \
		-vmode low_ansi2 -vecho -vcols 300 -vrows 300 | \
		sha256 ` == ef4a1edd1313246dff47a9d44e2827b475c483efce456d1c3475b9b19f8fd8b7 -a \
		`${ECHO_CMD} Hello | ../dMagnetic -ini ../dMagnetic.ini \
		-mag minitest.mag -gfx minitest.gfx \
		-vmode high_ansi -vecho -vcols 300 -vrows 300 | \
		sha256 ` == 91a443b46e40caa3a8f229144adafe8220f445f452cae6632e0f7dcd95e03b9f -a \
		`${ECHO_CMD} Hello | ../dMagnetic -ini ../dMagnetic.ini \
		-mag minitest.mag -gfx minitest.gfx \
		-vmode sixel -vecho -vcols 300 -vrows 300 | \
		sha256 ` == 69deb35a1323d3b018d249fb0eb91b33872e454d986c7538912aba3c91d55a32 \
		]; \
		then echo ok; else echo expected output not seen; exit 1; fi

.include <bsd.port.mk>
