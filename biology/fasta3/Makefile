# New ports collection makefile for:	fasta3
# Date created:		29 January 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	fasta3
PORTVERSION=	33.t08.d4
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.virginia.edu/pub/fasta/
DISTNAME=	fasta${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A collection of programs for searching DNA and protein databases, v3

NO_CDROM=	May not be sold or incorporated into a commercial product
WRKSRC=		${WRKDIR}/fasta3
PKGMESSAGE=	${WRKDIR}/pkg-message
FASTA3_DOCDIR=	${PREFIX}/share/doc/fasta3
FASTA3_DOCS=	00README.1st README COPYRIGHT fasta3x.me fasta3x.doc \
		readme.*

MAN1=		fasta3.1 fastf3.1 fasts3.1 map_db.1 prss3.1
MLINKS=		fasta3.1 tfasta3.1 fasta3.1 fastx3.1  fasta3.1 tfastx3.1  \
		fasta3.1 fasty3.1  fasta3.1 tfasty3.1 fasta3.1 ssearch3.1 \
		fastf3.1 tfastf3.1 fasts3.1 tfasts3.1

do-extract:
	@ ${RM} -rf ${WRKDIR}
	@ ${MKDIR} ${WRKSRC}
	@ for file in ${EXTRACT_ONLY}; do \
	  cd ${WRKSRC} && (${GZCAT} ${DISTDIR}/$${file} | ${SH} >/dev/null); \
	done

post-install:
	@ ${INSTALL_DATA} ${WRKSRC}/fastlibs ${PREFIX}/etc/fastlibs.sample
.for manpage in ${MAN1}
	@ ${INSTALL_MAN} ${WRKSRC}/${manpage} ${MAN1PREFIX}/man/man1/
.endfor
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${FASTA3_DOCDIR}
.for docfile in ${FASTA3_DOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${FASTA3_DOCDIR}
.endfor
.endif
.if !defined(BATCH)
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#' ${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
