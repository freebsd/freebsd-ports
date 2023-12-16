PORTNAME=	seqio
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.cs.ucdavis.edu/~gusfield/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of C functions which can read/write biological sequence files
WWW=		https://www.cs.ucdavis.edu/~gusfield/seqio.html

DEPRECATED=	Upstream last release was in 2000
EXPIRATION_DATE=	2024-01-17

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	${PROGRAMS:S,^,bin/,}
PORTDOCS=	*
PORTEXAMPLES=	*

EXAMPLES=	example1.c example2.c example3.c example4.c seqio.c \
		seqio.h Makefile
PROGRAMS=	fmtseq grepseq idxseq typeseq wcseq

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${PROGRAMS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/bioseq.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.doc ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${STAGEDIR}${DOCSDIR}/html

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
