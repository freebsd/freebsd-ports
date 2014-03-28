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

USES=		iconv motif
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
MAN_FILES=	Psequin.1 asn2ff.1 asn2idx.1 asn2xml.1 asndhuff.1 \
		asntool.1 blast.1 blastclust.1 cdscan.1 checksub.1 \
		copymat.1 ddv.1 debruijn.1 entrez2.1 errhdr.1 fa2htgs.1 \
		fastacmd.1 findspl.1 formatdb.1 formatrpsdb.1 getmesh.1 \
		getpub.1 gil2bin.1 idfetch.1 indexpub.1 makemat.1 \
		taxblast.1 tbl2asn.1 udv.1 vecscreen.1

MAN_LINKS=	bl2seq blastall blastcl3 blastpgp impala megablast \
		seedtop rpsblast

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
	@${REINPLACE_CMD} -e 's/%%ICONV_LIB%%/${ICONV_LIB}/' \
		${WRKSRC}/make/makeall.unx ${WRKSRC}/make/makenet.unx

# the ncbi-toolkit provides a shell script to drive the build
# and we use it

do-build:
	cd ${WRKDIR}; ./${DISTNAME}/make/makedis.csh

# the ncbi-toolkit does not provide an install target
# we thus roll our own

do-install:
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} ${BLAST_EXE} \
		${TOOLKIT_EXE} ${X11_EXE} ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${DISTNAME}
	(cd ${WRKSRC}/lib && ${INSTALL_DATA} *.a \
		${STAGEDIR}${PREFIX}/lib/${DISTNAME})
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${DISTNAME}/connect
	(cd ${WRKSRC}/include && ${INSTALL_DATA} *.h \
		${STAGEDIR}${PREFIX}/include/${DISTNAME})
	(cd ${WRKSRC}/include/connect && ${INSTALL_DATA} *.h \
		${STAGEDIR}${PREFIX}/include/${DISTNAME}/connect)
	(cd ${WRKSRC}/doc/man && ${INSTALL_MAN} ${MAN_FILES} \
		${STAGEDIR}${MANPREFIX}/man/man1)
.for man in ${MAN_LINKS}
	${LN} -s ${MANPREFIX}/man/man1/blast.1.gz \
		${STAGEDIR}${PREFIX}/man/man1/${man}.1.gz
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/data && ${INSTALL_DATA} * ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${TAR} --exclude man -cf - .) | \
		(cd ${STAGEDIR}${DOCSDIR} && ${TAR} --unlink -xf -)
	@${FIND} ${STAGEDIR}${DOCSDIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${STAGEDIR}${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}

.include <bsd.port.mk>
