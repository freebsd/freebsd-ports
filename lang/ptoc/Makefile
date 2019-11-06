# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	ptoc
PORTVERSION=	3.58
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.garret.ru/

MAINTAINER=	osa@FreeBSD.org
COMMENT=	ANSI/Turbo Pascal to C/C++ converter

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		bison xorg
USE_XORG=	x11

EXAMPLES=	arr.pas bgidemo.pas ccall.pas coord.txt dos.h dos.pas \
		func.pas hello.pas impact.pas lister.pas makefile.bsd \
		nested.pas objpas.pas polut2.pas printer.pas q2.txt \
		random.txt rename.cxx rename.pas set.pas str.pas test.c \
		test.cxx test.pas test.txt tpascal.pas trinor.pas \
		vibrkinp.pas vibrkinp.txt vibrtabl.pas war2.pas war2.txt \
		xy2.txt xy2orig.txt

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-build:
	@${LN} -sf makefile.bsd ${WRKSRC}/Makefile
	@${LN} -sf makefile.bsd ${WRKSRC}/Xbgi/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cganal ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ptoc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ptoc.cfg ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/libptoc.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libXbgi.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/ptoc
.for f in array.h graph.h io.h paslib.h ptoc.h set.h
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/include/ptoc
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in graph.pas ptoc.pas tptoc.pas
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
