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

MAINTAINER=	wjv@FreeBSD.org

GNU_CONFIGURE=	yes
USE_PERL5=	yes

MAN1=		hmmalign.1 hmmbuild.1 hmmcalibrate.1 hmmconvert.1 hmmemit.1 \
		hmmer.1 hmmpfam.1 hmmsearch.1 hmmfetch.1 hmmindex.1 alistat.1 \
		getseq.1 seqstat.1 sreformat.1

HMMER_DOCDIR=	${PREFIX}/share/doc/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${HMMER_DOCDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/Userguide/Userguide.pdf ${HMMER_DOCDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/Userguide/Userguide.ps ${HMMER_DOCDIR}
	@ ${TAR} xzfC ${WRKSRC}/Userguide/hmmer-html.tar.Z ${HMMER_DOCDIR}
.endif
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
