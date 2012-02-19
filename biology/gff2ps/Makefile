# New ports collection makefile for:	gff2ps
# Date created:				17 December 2001
# Whom:					Camson Huynh <chuynh@biolateral.com.au>
#
# $FreeBSD$
#

PORTNAME=	gff2ps
PORTVERSION=	0.98d
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	ftp://genome.crg.es/pub/gff_tools/gff2ps/ \
		http://genome.crg.es/software/gfftools/gff2ps_docs/manual/:doc
DISTFILES=	${PORTNAME}_v${PORTVERSION}.gz
.if !defined(NOPORTDOCS)
DISTFILES+=	${GFF2PS_MAN}.gz:doc
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts gff-formated genomic data-sets to PostScript

LICENSE=	GPLv2 # (or later)

RUN_DEPENDS=	gawk:${PORTSDIR}/lang/gawk \
		bash:${PORTSDIR}/shells/bash

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PORTDOCS=	${GFF2PS_MAN}
PLIST_FILES=	bin/${PORTNAME}

GFF2PS_MAN=	MANUAL_GFF2PS_v0.96.ps

do-extract:
	@${MKDIR} ${WRKDIR}
	@${GZCAT} ${DISTDIR}/${PORTNAME}_v${PORTVERSION}.gz \
		> ${WRKDIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${GZCAT} ${DISTDIR}/${GFF2PS_MAN}.gz > ${WRKDIR}/${GFF2PS_MAN}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#!/bin/bash|#!${LOCALBASE}/bin/bash| ; \
		 s|/usr/local/bin/gawk|${LOCALBASE}/bin/gawk|' ${WRKSRC}/gff2ps

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gff2ps ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${GFF2PS_MAN} ${DOCSDIR}
.endif

.include <bsd.port.mk>
