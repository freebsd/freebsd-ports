# New ports collection makefile for:	wise
# Date created:				26 February 2002
# Whom:					Tony Maher <tonym@biolateral.com.au>
#
# $FreeBSD$
#

PORTNAME=	wise
PORTVERSION=	2.2.0
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.ebi.ac.uk/pub/software/unix/wise2/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tonymaher@optusnet.com.au
COMMENT=	Intelligent algorithms for DNA searches

WRKTOP=		${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKTOP}/src
MAKEFILE=	makefile

#
# Actually want an 'ALL_TARGET = all perl' which then requires
# 'USE_PERL5= yes' but the perl sub-build is currently broken.
# The perl stuff is only so you can use the base libraries/functions
# from perl scripts.  This is extra, independent functionality for the
# port and not required for the base system which are C applications.
# When the perl part is fixed, it will require an install line
# something like '@cd ${WRKSRC}/perl/Wise2; ${MAKE} install'
#

BINFILES=	dba dnal estwise estwisedb genewise genewisedb \
		genomewise psw pswdb
DATAFILES=	BLOSUM30.bla BLOSUM45.bla BLOSUM62.bla BLOSUM80.bla \
		aa.rnd blosum30.bla blosum62.bla cb.tmf codon.table \
		gene.stat gon120.bla gon160.bla gon200.bla gon250.bla \
		gon350.bla human.gf human.gp human.stats idenity.bla \
		methods pb.gf pombe.gf tm.pri wise.2 wise.per worm.gf
DOCFILES=	README apiend.tex appendix.tex dynamite.tex \
		genewise21.eps genewise6.eps gettex.pl makefile \
		wise2.tex wise2api.tex wise3arch.tex
EXFILES=	README db.hmm hn_est.fa human.genomic \
		keratin_intron.human keratin_intron.mouse pep.fa \
		road.pep rrm.HMM vav.dna xeno.cdna xeno.pep

#
# Top level makefile does not respect CFLAGS.  Fixing it means
# having to fix some of the sub-directory makefiles.
# Note: some makefiles are ok and know that '-c' does not belong
# in CFLAGS and are part of the rule.
#

post-configure:
	@${REINPLACE_CMD} \
		-e s'#^CFLAGS = -c -O#CFLAGS ?= -c -O#;' \
		-e s'#\tcsh welcome.csh##;' \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} \
		-e s'#CFLAGS) $?#CFLAGS) -c $?#;' \
		${WRKSRC}/base/${MAKEFILE}
	@${REINPLACE_CMD} \
		-e s'#INCFLAGS) $?#INCFLAGS) -c $?#;' \
		${WRKSRC}/dynlibsrc/${MAKEFILE}
	@${REINPLACE_CMD} \
		-e s'#INCFLAGS) $?#INCFLAGS) -c $?#;' \
		-e s'#CFLAGS) estwise.c#CFLAGS) -c estwise.c#;' \
		-e s'#CFLAGS) estwiseb.c#CFLAGS) -c estwiseb.c#;' \
		-e s'#CFLAGS) estwisedb.c#CFLAGS) -c estwisedb.c#;' \
		-e s'#CFLAGS) genewise.c#CFLAGS) -c genewise.c#;' \
		-e s'#CFLAGS) genewisedb.c#CFLAGS) -c genewisedb.c#;' \
		${WRKSRC}/models/${MAKEFILE}

do-install:
.for file in ${BINFILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}
.for file in ${DATAFILES}
	@${INSTALL_DATA} ${WRKTOP}/wisecfg/${file} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	@${INSTALL_DATA} ${WRKTOP}/docs/${file} ${DOCSDIR}
.endfor
	 @${MKDIR} ${EXAMPLESDIR}
.for file in ${EXFILES}
	@${INSTALL_DATA} ${WRKTOP}/test_data/${file} ${EXAMPLESDIR}
.endfor

.endif

post-install:
	@${SED} -E -e 's#PREFIX#${PREFIX}#' -e '/(^\[|]$$)/d' ${PKGMESSAGE}

.include <bsd.port.mk>
