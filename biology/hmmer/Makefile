# New ports collection Makefile for: hmmer
# Date created:		June 29 1998
# Whom:			barnhart@genetics.wustl.edu
#
# $FreeBSD$
#

PORTNAME=	hmmer
PORTVERSION=	2.1.1
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.genetics.wustl.edu/pub/eddy/hmmer/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	barnhart@genetics.wustl.edu

GNU_CONFIGURE=	yes

USE_PERL5=	yes
MAN1=		hmmalign.1 hmmbuild.1 hmmcalibrate.1 hmmconvert.1 hmmemit.1 \
		hmmer.1 hmmpfam.1 hmmsearch.1 hmmfetch.1 hmmindex.1 alistat.1 \
		getseq.1 seqstat.1 sreformat.1

post-build:
	@ strip ${WRKSRC}/binaries/*
	@ make test

test:
	@(cd ${WRKSRC}; make check)

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/hmmer
	${INSTALL_MAN} ${WRKSRC}/Userguide/Userguide.ps ${PREFIX}/share/doc/hmmer
.endif
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
