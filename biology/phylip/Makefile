# New ports collection makefile for:	phylip
# Date created:				4 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	phylip
PORTVERSION=	3.5
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/phylip/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dbader@eece.unm.edu

NO_WRKSUBDIR=	yes

BINARIES=	clique consense contml contrast dnacomp dnadist dnainvar \
		dnaml dnamlk dnamove dnapars dnapenny dolmove dollop \
		dolpenny drawgram drawtree factor fitch gendist kitsch \
		mix move neighbor penny protdist protpars restml retree \
		seqboot
DOCFILES=	README clique.doc consense.doc contchar.doc contml.doc \
		contrast.doc discrete.doc distance.doc dnacomp.doc dnadist.doc \
		dnainvar.doc dnaml.doc dnamlk.doc dnamove.doc dnapars.doc \
		dnapenny.doc dollop.doc dolmove.doc dolpenny.doc draw.doc \
		drawgram.doc drawtree.doc factor.doc fitch.doc gendist.doc \
		kitsch.doc main.doc makeinf.doc mix.doc move.doc neighbor.doc \
		penny.doc protdist.doc protml.doc protpars.doc restml.doc \
		retree.doc seqboot.doc sequence.doc

do-install:
.for f in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif

.include <bsd.port.mk>
