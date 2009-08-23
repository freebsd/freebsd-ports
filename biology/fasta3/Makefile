# ex:ts=8
# New ports collection makefile for:	fasta3
# Date created:		29 January 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	fasta3
PORTVERSION=	35.4.9
CATEGORIES=	biology
MASTER_SITES=	http://faculty.virginia.edu/wrpearson/fasta/fasta3/
DISTNAME=	fasta-${PORTVERSION}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A collection of programs for searching DNA and protein databases

NO_CDROM=	May not be sold or incorporated into a commercial product
WRKSRC=		${WRKDIR}/${DISTNAME}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
SUB_FILES=	pkg-message
MAKEFILE=	Makefile.freebsd

XDIR=		${PREFIX}/bin
FASTA_HOST!=	/usr/bin/uname -n

MAKE_ENV+=	THR_LIBS=${PTHREAD_LIBS} XDIR=${XDIR} \
		FASTA_HOST='"${FASTA_HOST}"'

FASTA3_DOCS=	README.versions fasta3x.me fasta3x.doc \
		fasta20.doc fasta_func.doc readme.* fasta.defaults \
		fasta.options fasta_versions.html changes*.html
DATA=		data/*.mat
EXAMPLES=	seq/*.aa seq/*.lc seq/*.seq seq/*.lib

MAN1=		fasta35.1 map_db.1 ps_lav.1 pvcomp.1
MLINKS=		fasta35.1 tfasta35.1 fasta35.1 fastx35.1 fasta35.1 tfastx35.1  \
		fasta35.1 fasty35.1  fasta35.1 tfasty35.1 fasta35.1 ssearch35.1 \
		fasta35.1 fastf35.1 fasta35.1 fasts35.1 fasta35.1 tfasts35.1 \
		fasta35.1 fastm35.1 fasta35.1 tfastf35.1 fasta35.1 ggsearch35.1 \
		fasta35.1 lalign35.1 fasta35.1 prss35.1 fasta35.1 prfx35.1
PLIST_SUB=	VER=${PORTVERSION:R:R}

post-patch:
	@ ${CP} ${WRKSRC}/make/${MAKEFILE} ${BUILD_WRKSRC}/
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/conf/fastlibs ${PREFIX}/etc/fastlibs.sample
	@ ${MKDIR} ${DATADIR}
.for data in ${DATA}
	${INSTALL_DATA} ${WRKSRC}/${data} ${DATADIR}
.endfor
	@ ${MKDIR} ${EXAMPLESDIR}
.for ex in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${ex} ${EXAMPLESDIR}
.endfor
.for manpage in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${manpage} ${MAN1PREFIX}/man/man1/
.endfor
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FASTA_LIST ${DOCSDIR}
.for docfile in ${FASTA3_DOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${DOCSDIR}
.endfor
.endif
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
