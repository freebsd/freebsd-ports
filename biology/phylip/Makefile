# New ports collection makefile for:	phylip
# Date created:				4 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	phylip
PORTVERSION=	3.6
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/phylip/ \
		http://bioinformatics.weizmann.ac.il/software/linkage_and_mapping/phylip/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	dbader@ece.unm.edu
COMMENT=	A Phylogeny Inference Package

USE_XLIB=	yes
BUILD_WRKSRC=	${WRKSRC}/src

MAKE_ARGS=	CC="${CC} ${CFLAGS}" \
		DC="${CC} -DX -I${X11BASE}/include ${CFLAGS}" \
		GLIBS="-L${X11BASE}/lib -lX11 -lm"

BINARIES=	clique consense contml contrast dnacomp dnadist dnainvar \
		dnaml dnamlk dnamove dnapars dnapenny dollop dolmove \
		dolpenny drawgram drawtree factor fitch gendist kitsch \
		mix move neighbor pars penny proml promlk protdist \
		protpars restdist restml retree seqboot treedist
DOCFILES=	clique.html consense.html contchar.html contml.html \
		contrast.html discrete.html distance.html dnacomp.html \
		dnadist.html dnainvar.html dnaml.html dnamlk.html \
		dnamove.html dnapars.html dnapenny.html dollop.html \
		dolmove.html dolpenny.html draw.html drawgram.html \
		drawtree.html factor.html fitch.html gendist.html \
		kitsch.html main.html mix.html move.html neighbor.html \
		pars.html penny.html phylip.gif proml.html promlk.html \
		protdist.html protpars.html restdist.html restml.html \
		retree.html seqboot.html sequence.html treedist.html
FONTFILES=	font1 font2 font3 font4 font5 font6

do-install:
.for f in ${BINARIES}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${MKDIR} ${DATADIR}
.for font in ${FONTFILES}
	${INSTALL_DATA} ${BUILD_WRKSRC}/${font} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
