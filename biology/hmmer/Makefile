# New ports collection Makefile for: hmmer
# Date created:		June 29 1998
# Whom:			barnhart@genetics.wustl.edu
#
# $FreeBSD$
#

PORTNAME=	hmmer
PORTVERSION=	2.2.g
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.genetics.wustl.edu/pub/eddy/hmmer/${VERSIONSTRING}/
DISTNAME=	${PORTNAME}-${VERSIONSTRING}

MAINTAINER=	wjv@FreeBSD.org

GNU_CONFIGURE=	yes
USE_PERL5=	yes
VERSIONSTRING=	${PORTVERSION:C|\.([^.]*)$|\1|}

DOCFILES=	00README COPYRIGHT NOTES Userguide.pdf
MAN1=		afetch.1 alistat.1 hmmalign.1 hmmbuild.1 hmmcalibrate.1 \
		hmmconvert.1 hmmemit.1 hmmer.1 hmmfetch.1 hmmindex.1 \
		hmmpfam.1 hmmsearch.1 seqstat.1 sfetch.1 shuffle.1 \
		sreformat.1

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ${DOCFILES}
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
