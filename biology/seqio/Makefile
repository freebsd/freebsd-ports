# Created by: Tony Maher
# $FreeBSD$

PORTNAME=	seqio
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.cs.ucdavis.edu/~gusfield/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of C functions which can read/write biological sequence files

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

EXAMPLES=	example1.c example2.c example3.c example4.c seqio.c \
		seqio.h Makefile
PROGRAMS=	fmtseq grepseq idxseq typeseq wcseq
PLIST_FILES+=	${PROGRAMS:S,^,bin/,}
PORTEXAMPLES=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${PROGRAMS:S,^,${WRKSRC}/,} ${PREFIX}/bin
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/bioseq.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.doc ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DOCSDIR}/html
.endif

.include <bsd.port.mk>
