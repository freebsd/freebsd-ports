# New ports collection makefile for:	seqio
# Date created:				17 August 2001
# Whom:					Tony Maher
#
# $FreeBSD$
#

PORTNAME=	seqio
PORTVERSION=	1.2.2
CATEGORIES=	biology
MASTER_SITES=	http://www.cs.ucdavis.edu/~gusfield/
DISTNAME=	${PORTNAME}

MAINTAINER=	tonym@biolateral.com.au
COMMENT=	A set of C functions which can read/write biological sequence files

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}
EXAMPLES=	example1.c example2.c example3.c example4.c seqio.c \
		seqio.h Makefile
PROGRAMS=	fmtseq grepseq idxseq typeseq wcseq

do-install:
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/html
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}; \
	for file in ${PROGRAMS}; do \
		${INSTALL_PROGRAM} $$file ${PREFIX}/bin; \
	done
post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; \
	for file in ${EXAMPLES}; do \
		${INSTALL_DATA} $$file ${EXAMPLESDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/bioseq.txt ${DOCSDIR}
	cd ${WRKSRC}/doc; \
	for file in *.doc; do \
		${INSTALL_DATA} $$file ${DOCSDIR}; \
	done
	cd ${WRKSRC}/html; \
	for file in *.html; do \
		${INSTALL_DATA} $$file ${DOCSDIR}/html; \
	done
.endif

.include <bsd.port.mk>
