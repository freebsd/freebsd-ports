# Created by: tonym
# $FreeBSD$

PORTNAME=	ncbi-toolkit
PORTVERSION=	2012.06.20	# containing BLAST v2.2.27
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.ncbi.nlm.nih.gov/toolbox/ncbi_tools/old/${PORTVERSION:S/.//g}/
DISTNAME=	ncbi
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NCBI development toolkit, including BLAST 2 and GenBank/Entrez support

OPTIONS_DEFINE=	DOCS

USES=		motif
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

# These are the executables we install.
#
# We follow Debian in the separation of the port in three
# main categories and in the selection of programs that
# are installed in each case. This Makes Sense (TM).
# Thus, we drop a handful of programs that are useful only as tests
# or code examples
# (credit goes to Aaron Ucko, the Debian maintainer of the NCBI stuff)
# Right now the port installs all the executables below, this may
# change in the future with the addition of selectable knobs or
# new slave ports

TOOLKIT_EXE=	asn2ff asn2gb asn2idx asn2xml asndhuff asntool cdscan \
		checksub debruijn demo_regexp demo_regexp_grep dosimple \
		entrcmd errhdr fa2htgs findspl gene2xml getmesh getpub \
		gil2bin idfetch indexpub makeset ncbisort seqtest tbl2asn \
		vecscreen
BLAST_EXE=	bl2seq blastall blastcl3 blastclust blastpgp copymat \
		fastacmd formatdb formatrpsdb impala makemat megablast \
		rpsblast seedtop taxblast
X11_EXE=	Nentrez Psequin ddv entrez2 sbtedit udv

# and these are the man pages we have
MAN1=		Psequin.1 asn2ff.1 asn2idx.1 asn2xml.1 asndhuff.1 \
		asntool.1 blast.1 blastclust.1 cdscan.1 checksub.1 \
		copymat.1 ddv.1 debruijn.1 entrez2.1 errhdr.1 fa2htgs.1 \
		fastacmd.1 findspl.1 formatdb.1 formatrpsdb.1 getmesh.1 \
		getpub.1 gil2bin.1 idfetch.1 indexpub.1 makemat.1 \
		taxblast.1 tbl2asn.1 udv.1 vecscreen.1

MLINKS=		blast.1 bl2seq.1 blast.1 blastall.1 blast.1 blastcl3.1 \
		blast.1 blastpgp.1 blast.1 impala.1 blast.1 megablast.1 \
		blast.1 seedtop.1 blast.1 rpsblast.1 

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/make/makedis.csh
	@${REINPLACE_CMD} -e \
		'/^NCBI_CC/s|=.*|= ${CC}| ; \
		 /^NCBI_LDFLGS1/s|=.*|= ${LDFLAGS}| ; \
		 /^NCBI_OPTFLAG/s|= .*|= ${CFLAGS}| ; \
		 s|-I/usr/X11R6/include||g ; \
		 s|-L/usr/X11R6/lib||g ; \
		 s|/usr/local|${LOCALBASE}|g ; \
		 s|-Wl,-Bstatic|| ; \
		 s|-Wl,-Bdynamic||' ${WRKSRC}/platform/freebsd.ncbi.mk

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
	(cd ${WRKSRC}/lib && ${INSTALL_DATA} *.a ${PREFIX}/lib/${DISTNAME})
	@${MKDIR} ${PREFIX}/include/${DISTNAME}
	(cd ${WRKSRC}/include && ${INSTALL_DATA} *.h \
		${PREFIX}/include/${DISTNAME})
	@${MKDIR} ${PREFIX}/include/${DISTNAME}/connect
	(cd ${WRKSRC}/include/connect && ${INSTALL_DATA} *.h \
		${PREFIX}/include/${DISTNAME}/connect)
.for man in ${MAN1}
	(cd ${WRKSRC}/doc/man && ${INSTALL_MAN} ${man} ${MANPREFIX}/man/man1)
.endfor
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/data && ${INSTALL_DATA} * ${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${TAR} --exclude man -cf - .) | \
		(cd ${DOCSDIR} && ${TAR} --unlink -xf -)
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DOCSDIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
