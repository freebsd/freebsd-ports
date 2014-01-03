# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	wu-blast
PORTVERSION=	2.0
PORTREVISION=	20060322	# YYYYMMDD
CATEGORIES=	biology
MASTER_SITES=	#
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	wen@FreeBSD.org
COMMENT=	WU BLAST, a software package for sequence similarity searches

# Distfiles change rapidly, but since they can only be downloaded from
# the author, this is not a problem.
IGNOREFILES=	${DISTFILES}

RESTRICTED=	License does not allow redistribution of binaries. You should first register for the software, which is free for academic use.
ONLY_FOR_ARCHS=	i386 amd64

NO_BUILD=	yes
DOWNLOAD_URL=	http://blast.wustl.edu/licensing

NO_WRKSUBDIR=	yes

PORTDOCS=	COPYRIGHT FAQ-Indexing.html HISTORY LICENSE Memory.html \
		README.html parameters.html tabular.html
BINS=		blasta gb2fasta gt2fasta memfile nrdb pam patdb \
		pir2fasta sp2fasta xdformat xdget
SCRIPTS=	wu-blastall wu-formatdb
BLASTA_LINKS=	blastn blastp blastx tblastn tblastx
XDFORMAT_LINKS=	setdb pressdb
SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
DISTNAME=	blast${PORTVERSION:S/.0//}.freebsd-6.x-x64
.else
DISTNAME=	blast${PORTVERSION:S/.0//}.freebsd-6.x-i686
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		You must manually fetch ${PORTNAME}${PORTVERSION:S/.0//} for the FreeBSD platform (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-install:
.for bin in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${bin} ${PREFIX}/bin
.endfor
.for script in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${script} ${PREFIX}/bin
.endfor
	${CHMOD} a-rw,a+x ${PREFIX}/bin/blasta
.for blink in ${BLASTA_LINKS}
	@(cd ${PREFIX}/bin && ${LN} -s blasta ${blink})
.endfor
.for xlink in ${XDFORMAT_LINKS}
	@(cd ${PREFIX}/bin && ${LN} -s xdformat ${xlink})
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/matrix ${DATADIR}
	${CP} -R ${WRKSRC}/filter ${DATADIR}
	${CP} ${WRKSRC}/sysblast.sample ${DATADIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
