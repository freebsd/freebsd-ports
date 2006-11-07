# New ports collection makefile for:	atlast
# Date created:				26 Aug 97
# Whom:					Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	atlast
PORTVERSION=	1.1
CATEGORIES=	lang
MASTER_SITES=	http://www.fourmilab.ch/atlast/ \
		http://www.fourmilab.to/atlast/

MAINTAINER=	laszlof@FreeBSD.org
COMMENT=	Autodesk Threaded Language Application System Toolkit

SRC=		atlast.c atlmain.c
DEFINES=	-DMEMSTAT -DALIGNMENT -DEXPORT
LDFLAGS+=	-lm

PLIST_FILES=	bin/atlast
PORTDOCS=	atlast.ps atlast.rtf

do-build:
.for f in ${SRC}
	${CC} ${CFLAGS} ${DEFINES} -c ${WRKSRC}/${f} -o ${WRKSRC}/${f:C/\.c$/.o/}
.endfor
	${CC} ${LDFLAGS} ${SRC:C/(.*)\.c$/${WRKSRC}\/\1.o/} \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
