# New ports collection makefile for:	ptoc
# Date created:				10 December 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	ptoc
PORTVERSION=	3.54
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.garret.ru/~knizhnik/

MAINTAINER=	osa@FreeBSD.org
COMMENT=	ANSI/Turbo Pascal to C/C++ converter

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XLIB=	yes
USE_BISON=	yes

EXAMPLES=	arr.pas bgidemo.pas ccall.pas coord.txt dos.h dos.pas \
		func.pas hello.pas impact.pas lister.pas makefile.bsd \
		nested.pas objpas.pas polut2.pas printer.pas q2.txt \
		random.txt rename.cxx rename.pas set.pas str.pas test.c \
		test.cxx test.pas test.txt tpascal.pas trinor.pas \
		vibrkinp.pas vibrkinp.txt vibrtabl.pas war2.pas war2.txt \
		xy2.txt xy2orig.txt

pre-build:
	@${LN} -sf makefile.bsd ${WRKSRC}/Makefile
	@${LN} -sf makefile.bsd ${WRKSRC}/Xbgi/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cganal ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ptoc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ptoc.cfg ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/libptoc.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libXbgi.a ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/ptoc
.for f in array.h graph.h io.h paslib.h ptoc.h set.h
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/include/ptoc
.endfor
	@${MKDIR} ${DATADIR}
.for f in graph.pas ptoc.pas tptoc.pas
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
