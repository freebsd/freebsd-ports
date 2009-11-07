# New ports collection makefile for:	velvet
# Date created:		27 Oct 2009
# Whom:			Motomichi Matsuzaki <mzaki@m.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	velvet
PORTVERSION=	0.7.55
CATEGORIES=	biology
MASTER_SITES=	http://www.ebi.ac.uk/~zerbino/velvet/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mzaki@m.u-tokyo.ac.jp
COMMENT=	Sequence assembler for very short reads

USE_GMAKE=	yes
ALL_TARGET=	default

MAXKMERLENGTH?=	31
MAKE_ENV+=	MAXKMERLENGTH=${MAXKMERLENGTH}

USE_PERL5_RUN=	yes

BINARIES=	velvetg velveth
SCRIPTS=	contrib/VelvetOptimiser/VelvetOptimiser.pl \
		contrib/afg_handling/asmbly_splitter.pl \
		contrib/afg_handling/snp_view.pl \
		contrib/estimate-exp_cov/velvet-estimate-exp_cov.pl \
		contrib/fasta2agp/fasta2agp.pl \
		contrib/extractContigReads/extractContigReads.pl \
		contrib/observed-insert-length.pl/observed-insert-length.pl \
		contrib/shuffleSequences_fasta/shuffleSequences_fasta.pl
PERLMOD_DIRS=	contrib/VelvetOptimiser/VelvetOpt
PERLMOD_FILES=	contrib/VelvetOptimiser/VelvetOpt/Assembly.pm \
		contrib/VelvetOptimiser/VelvetOpt/Utils.pm \
		contrib/VelvetOptimiser/VelvetOpt/gwrap.pm \
		contrib/VelvetOptimiser/VelvetOpt/hwrap.pm

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
SCRIPTS+=	contrib/layout/graph2.py
.endif

.for f in ${BINARIES} ${SCRIPTS}
PLIST_FILES+=	bin/${f:T}
.endfor
.for d in ${PERLMOD_DIRS}
PLIST_DIRS+=	%%SITE_PERL%%/${d:T}
.endfor
.for f in ${PERLMOD_FILES}
PLIST_FILES+=	%%SITE_PERL%%/${f:H:T}/${f:T}
.endfor

PORTDOCS=	ChangeLog Manual.pdf

post-patch:
.for f in ${SCRIPTS}
	${REINPLACE_CMD} -e s,#!/usr/bin/perl,${PERL}, ${WRKSRC}/${f}
.endfor
.if !defined(WITHOUT_PYTHON)
	(IFS=''; ${REINPLACE_CMD} -e `${ECHO} '1i\'; ${ECHO} '#!${PYTHON_CMD}'` ${WRKSRC}/contrib/layout/graph2.py)
.endif

post-build:
	${REINPLACE_CMD} -e s,%%MAXKMERLENGTH%%,${MAXKMERLENGTH},g ${WRKSRC}/contrib/VelvetOptimiser/VelvetOptimiser.pl

do-install:
.for f in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin/${f:T}
.endfor
.for d in ${PERLMOD_DIRS}
	${MKDIR} ${PREFIX}/${SITE_PERL_REL}/${d:T}
.endfor
.for f in ${PERLMOD_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${SITE_PERL_REL}/${f:H:T}/${f:T}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
