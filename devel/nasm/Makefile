# New ports collection makefile for:	The Netwide Assembler
# Date created:				7 April 1998
# Whom:					Murray Stokely <murray@cdrom.com>
#
# $FreeBSD$
#

PORTNAME=	nasm
PORTVERSION=	2.09.06
PORTEPOCH=	1
CATEGORIES=	devel lang
MASTER_SITES=	http://www.nasm.us/pub/nasm/releasebuilds/${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-xdoc${EXTRACT_SUFX}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	General-purpose multi-platform x86 and amd64 assembler

LICENSE=	BSD

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes	# parallel builds (-jX) are broken with BSD make(1)
INSTALL_TARGET=	install install_rdf

MAN1=		ldrdf.1 nasm.1 ndisasm.1 rdf2bin.1 rdf2com.1 rdf2ihx.1 \
		rdf2ith.1 rdf2srec.1 rdfdump.1 rdflib.1 rdx.1
PORTDOCS=	*

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/nasmdoc.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
