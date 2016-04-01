# Created by: Motomichi Matsuzaki <mzaki@biol.s.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	consed
PORTVERSION=	27.0
CATEGORIES=	biology
# MASTER_SITES=	http://www.phrap.org/consed/distributions/${PORTVERSION}/
# MASTER_SITES=	http://bozeman.mbt.washington.edu/consed/distributions/${PORTVERSION}/
DISTNAME=	${PORTNAME}_linux

MAINTAINER=	mzaki@m.u-tokyo.ac.jp
COMMENT=	Graphical tool for editing Phrap assemblies

RUN_DEPENDS=	phred:biology/phred \
		phrap:biology/phrap

CONFLICTS_INSTALL=	phd2fasta-[0-9]*

SUB_FILES=	pkg-message

USES=		perl5 shebangfix
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
ONLY_FOR_ARCHS=	i386 amd64
MYSHEBANG=	bin/ace2Fasta.perl \
		bin/tagRepeats.perl \
		bin/selectRegions.perl \
		bin/selectOneRegion.perl \
		bin/revertToUneditedRead \
		bin/removeReads \
		bin/phredPhrap.orig \
		bin/phredPhrap \
		bin/phd2Ace.perl \
		bin/orderPrimerPairs.perl \
		bin/makeRegionsFile.perl \
		bin/makePhdBall.perl \
		bin/lib2Phd.perl \
		bin/fixContigEnd.perl \
		bin/findSequenceMatchesForConsed.perl \
		bin/revert_fof \
		bin/filter454Reads.perl \
		bin/fastq2Phrap.perl \
		bin/fasta2PhdBall.perl \
		bin/fasta2Phd.perl \
		bin/fasta2Ace.perl \
		bin/determineReadTypes.perl \
		bin/countEditedBases.perl \
		bin/bam2Ace.perl \
		bin/amplifyTranscripts.perl \
		bin/alignSolexaReads2Refs.perl \
		bin/alignRNA2Genomic.perl \
		bin/addSolexaReads.perl \
		bin/addSangerReads.perl \
		bin/addReads2Consed.perl \
		bin/add454Reads.perl \
		bin/ace2Oligos.perl \
		bin/transferConsensusTags.perl \
		bin/ace2fof \
		bin/ace2OligosWithComments.perl \
		bin/sff2phd.perl \
		bin/recover_consensus_tags \
		bin/phredPhrapWithPhdBalls \
		bin/cons.perl \
		bin/acestatus.pl \
		bin/aceContigs2Phds.perl \
		bin/sff2phd_Samborskyy

RESTRICTED=	Redistribution is not permitted in any form. You must request access permission via e-mail to get the tarball. Free for academic use.
.if defined(PACKAGE_BUILDING)
IGNORE=		distribution files must be obtained via the authors
.endif

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${LN} -sf ../../bin ${STAGEDIR}${DATADIR}/bin
	(cd ${WRKSRC}; ${SETENV} CC=${CC} ./installConsed.perl consed_linux32bit ${STAGEDIR}${DATADIR})
	${LN} -sf ../../../etc/PhredPar/phredpar.dat ${STAGEDIR}${DATADIR}/lib/phredpar.dat
	cd ${STAGEDIR}${PREFIX} && ${ECHO_CMD} ${MYSHEBANG} | ${XARGS} ${SED} -i '' ${_SHEBANG_REINPLACE_ARGS}

.include <bsd.port.mk>
