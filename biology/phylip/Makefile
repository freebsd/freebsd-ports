# New ports collection makefile for:	phylip
# Date created:				4 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	phylip
PORTVERSION=	3.6
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/phylip/phylip36/
DISTNAME=	${PORTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/src
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dbader@eece.unm.edu

USE_XLIB=	yes
NO_WRKSUBDIR=	yes

BINARIES=	clique consense contml contrast dnacomp dnadist dnainvar \
		dnaml dnamlk dnamove dnapars dnapenny dolmove dollop \
		dolpenny drawgram drawtree factor fitch gendist kitsch \
		mix move neighbor pars penny proml protdist protpars \
		restdist restml retree seqboot treedist
DOCFILES=	clique.html consense.html contchar.html contml.html \
		contrast.html discrete.html distance.html dnacomp.html \
		dnadist.html dnainvar.html dnaml.html dnamlk.html \
		dnamove.html dnapars.html dnapenny.html dollop.html \
		dolmove.html dolpenny.html draw.html drawgram.html \
		drawtree.html factor.html fitch.html gendist.html \
		kitsch.html main.html mix.html move.html neighbor.html \
		pars.html penny.html phylip.gif proml.html protdist.html \
		protpars.html restdist.html restml.html retree.html \
		seqboot.html sequence.html treedist.html

do-install:
.for f in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${f} \
	${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif

.include <bsd.port.mk>
