# New ports collection makefile for:	fasta
# Date created:		29 January 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	fasta
PORTVERSION=	20.u66
CATEGORIES=	biology
MASTER_SITES=	http://ftp.virginia.edu/pub/fasta/
DISTNAME=	fasta${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	johann@egenetics.com

NO_CDROM=	May not be sold or incorporated into a commercial product
WRKSRC=		${WRKDIR}/fasta
PKGMESSAGE=	${WRKDIR}/pkg-message
FASTA_DOCDIR=	${PREFIX}/share/doc/fasta
FASTA_DOCS=	COPYRIGHT README.versions fasta20.doc fasta20.me format.doc \
		readme.*

MAN1=		align.1 fasta.1 lalign.1 prdf.1 prss.1 randseq.1 ssearch.1
MLINKS=		fasta.1 tfasta.1 fasta.1 lfasta.1 fasta.1 plfasta.1 \
		fasta.1 fastx.1  fasta.1 tfastx.1 \
		align.1 align0.1 lalign.1 plalign.1

do-extract:
	@ ${RM} -rf ${WRKDIR}
	@ ${MKDIR} ${WRKSRC}
	@ for file in ${EXTRACT_ONLY}; do \
	  cd ${WRKSRC} && (${GZCAT} ${DISTDIR}/$${file} | ${SH} >/dev/null); \
	done

post-install:
.for manpage in ${MAN1}
	@ ${INSTALL_MAN} ${WRKSRC}/${manpage} ${MAN1PREFIX}/man/man1/
.endfor
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${FASTA_DOCDIR}
.for docfile in ${FASTA_DOCS}
	@ ${INSTALL_MAN} ${WRKSRC}/${docfile} ${FASTA_DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
