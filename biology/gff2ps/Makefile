# New ports collection makefile for:	gff2ps
# Date created:				17 December 2001
# Whom:					Camson Huynh <chuynh@biolateral.com.au>
#
# $FreeBSD$
#

PORTNAME=	gff2ps
PORTVERSION=	0.97b
CATEGORIES=	biology
MASTER_SITES=	ftp://www1.imim.es/pub/gff_tools/gff2ps/:prog \
		http://www1.imim.es/software/gfftools/gff2ps_docs/manual/:doc
DISTFILES=	${PORTNAME}_v${PORTVERSION}.gz:prog ${GFF2PS_MAN}.gz:doc

MAINTAINER=	chuynh@biolateral.com.au
COMMENT=	Converts gff-formated genomic data-sets to PostScript

RUN_DEPENDS=	gawk:${PORTSDIR}/lang/gawk \
		bash:${PORTSDIR}/shells/bash2

GFF2PS_MAN=	MANUAL_GFF2PS_v0.96.ps
PATCH_WRKSRC=	${WRKDIR}
USE_REINPLACE=	yes

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,^#!/bin/bash,#!${LOCALBASE}/bin/bash,; \
		s,/usr/local/bin/gawk,${LOCALBASE}/bin/gawk,' ${WRKDIR}/gff2ps

do-extract:
	@${MKDIR} ${WRKDIR}
	@${GZCAT} ${DISTDIR}/${PORTNAME}_v${PORTVERSION}.gz \
		> ${WRKDIR}/${PORTNAME}
	@${GZCAT} ${DISTDIR}/${GFF2PS_MAN}.gz > ${WRKDIR}/${GFF2PS_MAN}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/gff2ps ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/${GFF2PS_MAN} ${DOCSDIR}
.endif

.include <bsd.port.mk>
