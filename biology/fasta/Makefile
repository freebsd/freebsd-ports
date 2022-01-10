# Created by: Johann Visagie <johann@egenetics.com>

PORTNAME=	fasta
PORTVERSION=	21.1.1
CATEGORIES=	biology
MASTER_SITES=	http://faculty.virginia.edu/wrpearson/fasta/fasta2/ \
		ftp://ftp.ebi.ac.uk/pub/software/unix/fasta/fasta2/
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of programs for searching DNA and protein databases

# Converted from NO_CDROM
LICENSE=	FASTA
LICENSE_NAME=	fasta
LICENSE_TEXT=	May not be sold or incorporated into a commercial product
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

CONFLICTS_INSTALL=	align

WRKSRC=		${WRKDIR}/fasta
SUB_FILES=	pkg-message

MAN_FILES=	align.1 fasta.1 lalign.1 prdf.1 prss.1 randseq.1 ssearch.1
PORTDOCS=	COPYRIGHT README.versions fasta20.doc fasta20.me format.doc \
		readme.*

OPTIONS_DEFINE=	DOCS

do-extract:
	@ ${RM} -r ${WRKDIR}
	@ ${MKDIR} ${WRKSRC}
	@ for f in ${EXTRACT_ONLY}; do \
	  cd ${WRKSRC} && (${GZCAT} ${DISTDIR}/$${f} | ${SH} >/dev/null); \
	done

post-patch:
	@${REINPLACE_CMD} 's|BIN)|DESTDIR)$$(&|' ${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${MAN_FILES:S,^,${WRKSRC}/,} \
		${STAGEDIR}${MAN1PREFIX}/man/man1
.for mlink in tfasta lfasta plfasta fastx tfastx
	${LN} -s fasta.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1/${mlink}.1.gz
.endfor
	${LN} -s align.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1/align0.1.gz
	${LN} -s align.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1/plalign.1.gz
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
