# Created by: Camson Huynh <chuynh@biolateral.com.au>
# $FreeBSD$

PORTNAME=	gff2ps
PORTVERSION=	0.98d
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	ftp://genome.crg.es/pub/gff_tools/gff2ps/ \
		http://genome.crg.es/software/gfftools/gff2ps_docs/manual/:doc
DISTFILES=	${PORTNAME}_v${PORTVERSION}.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts gff-formated genomic data-sets to PostScript

LICENSE=	GPLv2+

RUN_DEPENDS=	gawk:lang/gawk \
		bash:shells/bash

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PORTDOCS=	${GFF2PS_MAN}
PLIST_FILES=	bin/${PORTNAME}

GFF2PS_MAN=	MANUAL_GFF2PS_v0.96.ps

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES=	${GFF2PS_MAN}.gz:doc

.include <bsd.port.options.mk>

do-extract:
	@${MKDIR} ${WRKSRC}
	@${GZCAT} ${DISTDIR}/${PORTNAME}_v${PORTVERSION}.gz \
		> ${WRKSRC}/${PORTNAME}
do-extract-DOCS-on:
	@${GZCAT} ${DISTDIR}/${GFF2PS_MAN}.gz > ${WRKSRC}/${GFF2PS_MAN}

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#!/bin/bash|#!${LOCALBASE}/bin/bash| ; \
		 s|/usr/local/bin/gawk|${LOCALBASE}/bin/gawk|' ${WRKSRC}/gff2ps

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gff2ps ${STAGEDIR}${PREFIX}/bin
do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${GFF2PS_MAN} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
