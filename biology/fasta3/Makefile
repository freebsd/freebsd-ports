# ex:ts=8
# New ports collection makefile for:	fasta3
# Date created:		29 January 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	fasta3
PORTVERSION=	34.t25.d6
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.virginia.edu/pub/fasta/
DISTNAME=	fasta${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A collection of programs for searching DNA and protein databases

BROKEN=		Unfetchable

NO_CDROM=	"May not be sold or incorporated into a commercial product"
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message
MAKEFILE=	Makefile.freebsd

XDIR=		${PREFIX}/bin
FASTA_HOST!=	/usr/bin/uname -n

MAKE_ENV+=	THR_LIBS=${PTHREAD_LIBS} XDIR=${XDIR} \
		FASTA_HOST='"${FASTA_HOST}"'

FASTA3_DOCS=	README COPYRIGHT FASTA_LIST fasta3x.me fasta3x.doc \
		fasta20.doc fasta_func.doc readme.* fasta.defaults
DATA=		*.mat
EXAMPLES=	*.aa *.lc *.seq

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

post-extract:
	@ cp ${FILESDIR}/Makefile.freebsd ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/fastlibs ${PREFIX}/etc/fastlibs.sample
	@ ${MKDIR} ${DATADIR}
.for data in ${DATA}
	${INSTALL_DATA} ${WRKSRC}/${data} ${DATADIR}
.endfor
	@ ${MKDIR} ${EXAMPLESDIR}
.for ex in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${ex} ${EXAMPLESDIR}
.endfor
.for manpage in ${MAN1}
	@ ${INSTALL_MAN} ${WRKSRC}/${manpage} ${MAN1PREFIX}/man/man1/
.endfor
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ${FASTA3_DOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
