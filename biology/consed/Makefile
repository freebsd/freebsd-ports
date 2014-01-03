# Created by: Motomichi Matsuzaki <mzaki@biol.s.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	consed
PORTVERSION=	16.0
CATEGORIES=	biology
MASTER_SITES=	http://www.phrap.org/consed/distributions/${PORTVERSION}/
DISTNAME=	${PORTNAME}_linux
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	mzaki@biol.s.u-tokyo.ac.jp
COMMENT=	A graphical tool for editing Phrap assemblies

RUN_DEPENDS=	phred:${PORTSDIR}/biology/phred \
		phrap:${PORTSDIR}/biology/phrap \
		phd2fasta:${PORTSDIR}/biology/phd2fasta

USES=		perl5
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
ONLY_FOR_ARCHS=	i386 amd64

RESTRICTED=	Redistribution is not permitted in any form. You must request access permission via e-mail to get the tarball. Free for academic use.
.if defined(PACKAGE_BUILDING)
IGNORE=		distribution files must be obtained via the authors
.endif

NO_WRKSUBDIR=	yes

BUILD_WRKSRC=	${WRKSRC}/misc/mktrace
ALL_TARGET=	mktrace

BINARIES=	consed mktrace sffinfo sff2scf
CONTRIBS=	ace2OligosWithComments.perl ace2fof \
		aceContigs2Phds.perl acestatus.pl export_cons \
		mergeAces.perl recover_consensus_tags revert_fof
SCRIPTS=	ace2Fasta.perl ace2Oligos.perl addReads2Consed.perl \
		amplifyTranscripts.perl catPhdFiles.perl \
		countEditedBases.perl determineReadTypes.perl fasta2Phd.perl \
		findSequenceMatchesForConsed.perl lib2Phd.perl \
		orderPrimerPairs.perl phd2Ace.perl phredPhrap removeReads \
		revertToUneditedRead tagRepeats.perl transferConsensusTags.perl
.for f in ${BINARIES} ${CONTRIBS} ${SCRIPTS}
PLIST_FILES+=	bin/${f}
.endfor

DATADIR=	${PREFIX}/lib/screenLibs
DATAFILES=	primerCloneScreen.seq primerSubcloneScreen.seq \
		repeats.fasta singleVectorForRestrictionDigest.fasta
NULLFILES=	vector.seq
.for f in ${DATAFILES} ${NULLFILES}
PORTDATA+=	${f}.dist
.endfor
PORTDOCS=	README.txt

NO_STAGE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
EXAMPLES=	standard autofinish assembly_view polyphred
PLIST=		${PKGDIR}/pkg-plist.examples
.endif

post-build:
	(cd ${WRKSRC}/misc/454; ${CC} ${CFLAGS} sffinfo.c -o sffinfo)
	(cd ${WRKSRC}/misc/454; ${CC} ${CFLAGS} sff2scf.c -o sff2scf)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/consed_linux2.4 ${PREFIX}/bin/consed
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/mktrace ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/misc/454/sffinfo ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/misc/454/sff2scf ${PREFIX}/bin/
.for f in ${BINARIES}
	@${CHMOD} a-r ${PREFIX}/bin/${f}
.endfor
.for f in ${CONTRIBS}
	@${INSTALL_SCRIPT} ${WRKSRC}/contributions/${f} ${PREFIX}/bin/
.endfor
.for f in ${SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/${f} ${PREFIX}/bin/
.endfor
	@${MKDIR} ${DATADIR}
.for f in ${DATAFILES}
	@${INSTALL_DATA} ${WRKSRC}/misc/${f} ${DATADIR}/${f}.dist
.endfor
.for f in ${NULLFILES}
	@${INSTALL_DATA} /dev/null ${DATADIR}/${f}.dist
.endfor
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for dir in ${EXAMPLES}
	@${CP} -R ${WRKSRC}/${dir} ${EXAMPLESDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.if ! ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_CMD} "Examples were not installed. You can define WITH_EXAMPLES=yes to install them."
.endif
	@${ECHO_CMD} "You must set the CONSED_HOME environment variable to '${PREFIX}'"

.include <bsd.port.mk>
