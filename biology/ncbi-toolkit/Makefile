# ex:ts=8
# New ports collection makefile for:	NCBI
# Date created:         03 April 2000
# Whom:                 tonym
#
# $FreeBSD$
#

PORTNAME=	ncbi-toolkit
PORTVERSION=	2004.10.20
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.ncbi.nih.gov/toolbox/ncbi_tools/old/${PORTVERSION:S/.//g}/
DISTNAME=	ncbi
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	NCBI development toolkit, including BLAST 2 and GenBank/Entrez support

USE_MOTIF=	yes
CPIO_ARGS=	--quiet -pdum -R
PKGMESSAGE=	${WRKDIR}/pkg-message

# These are the executables we install.
#
# We follow Debian in the separation of the port in three
# main categories and in the selection of programs that
# are installed in each case. This Makes Sense (TM).
# Thus, we drop a handful of programs that are useful only as tests
# or code examples
# (credit goes to Aaron Ucko, the Debian maintainer of the NCBI stuff!)
# Right now the port installs all the executables below, this may
# change in the future with the addition of selectable knobs or
# new slave ports

TOOLKIT_EXE=	asn2ff asn2gb asn2xml asndhuff checksub debruijn \
		entrcmd fa2htgs findspl getseq getfeat getmesh \
		getpub gil2bin idfetch indexpub makeset tbl2asn vecscreen
BLAST_EXE=	bl2seq blast blastall blastcl3 blastclust blastpgp copymat \
		fastacmd formatdb impala makemat megablast rpsblast seedtop
X11_EXE=	Nentrez Psequin ddv entrez2 netentcf udv

# and these are the man pages we have
MAN1=		Nentrez.1 Psequin.1 asn2asn.1 asn2ff.1 asn2gb.1 asn2xml.1 asndhuff.1 \
		asntool.1 blast.1 blastclust.1 cdscan.1 checksub.1 copymat.1 ddv.1 \
		debruijn.1 entrcmd.1 entrez2.1 errhdr.1 fa2htgs.1 fastacmd.1 findspl.1 \
		fmerge.1 formatdb.1 gbseqget.1 getfeat.1 getmesh.1 getpub.1 gil2bin.1 \
		idfetch.1 indexpub.1 makemat.1 makeset.1 netentcf.1 rpsblast.1 \
		tbl2asn.1 udv.1 vecscreen.1

MLINKS=		blast.1 bl2seq.1 blast.1 blastall.1 blast.1 blastcl3.1 \
		blast.1 blastpgp.1 blast.1 impala.1 blast.1 megablast.1 \
		blast.1 seedtop.1

# the ncbi-toolkit provides a shell script to drive the build
# and we use it

do-build:
	cd ${WRKDIR}; ./${DISTNAME}/make/makedis.csh

# the ncbi-toolkit does not provide an install target
# we thus roll our own

do-install:
.for blastexe in ${BLAST_EXE}
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} ${blastexe} ${PREFIX}/bin)
.endfor

.for toolkitexe in ${TOOLKIT_EXE}
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} ${toolkitexe} ${PREFIX}/bin)
.endfor

.for x11exe in ${X11_EXE}
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} ${x11exe} ${PREFIX}/bin)
.endfor

	@${MKDIR} ${PREFIX}/lib/${DISTNAME}
	(cd ${WRKSRC}/lib && ${INSTALL_PROGRAM} *.a ${PREFIX}/lib/${DISTNAME})
	@${MKDIR} ${PREFIX}/include/${DISTNAME}/connect
	(cd ${WRKSRC}/include && ${INSTALL_DATA} *.h ${PREFIX}/include/${DISTNAME})
	(cd ${WRKSRC}/include/connect && ${INSTALL_DATA} *.h ${PREFIX}/include/${DISTNAME}/connect)

.for man in ${MAN1}
	(cd ${WRKSRC}/doc/man && ${INSTALL_MAN} ${man} ${PREFIX}/man/man1)
.endfor

post-install:
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/data/ && ${INSTALL_DATA} * ${DATADIR})

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${FIND} * | ${CPIO} ${CPIO_ARGS} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR})
.endif

.if !defined(BATCH)
	@ ${SED} -e "s#%%PREFIX%%#${PREFIX}#" ${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
