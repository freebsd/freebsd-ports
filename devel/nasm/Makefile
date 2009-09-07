# New ports collection makefile for:	nasm
# Date created:        7 April 1998
# Whom:                Murray Stokely <murray@cdrom.com>
#
# $FreeBSD$
#

PORTNAME=	nasm
PORTVERSION=	2.07
PORTEPOCH=	1
CATEGORIES=	devel lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20sources/${PORTVERSION} \
		http://www.nasm.us/pub/nasm/releasebuilds/${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-xdoc${EXTRACT_SUFX}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	General-purpose multi-platform x86 and x86-64 assembler

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install install_rdf
MAKE_JOBS_UNSAFE=	yes

MAN1=		nasm.1 ndisasm.1 \
		ldrdf.1 rdf2bin.1 rdf2com.1 rdf2ihx.1 rdf2ith.1 rdf2srec.1 rdfdump.1 rdflib.1 rdx.1
PORTDOCS=	nasmdoc.txt

post-install:
.ifndef(NOPORTDOCS)
.	for d in ${PORTDOCS}
		${MKDIR} ${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/doc/$d ${DOCSDIR}
.	endfor
.endif

.include <bsd.port.mk>
