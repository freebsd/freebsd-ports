# New ports collection Makefile for: hmmer
# Version required:	2.0
# Date created:		June 29 1998
# Whom:			barnhart@genetics.wustl.edu
#
# $Id$
#

DISTNAME=	hmmer-2.0
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.genetics.wustl.edu/pub/eddy/hmmer/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	barnhart@genetics.wustl.edu

BUILD_DEPENDS=	perl:${PORTSDIR}/lang/perl5

MAN1=		hmmalign.1 hmmbuild.1 hmmcalibrate.1 hmmconvert.1 hmmemit.1 hmmer.1 hmmpfam.1 hmmsearch.1

WRKSRC=		${WRKDIR}/build/${DISTNAME}

post-build:
	@ strip ${WRKSRC}/binaries/*
	@ make test

test:
	@(cd ${WRKSRC}; make test)

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/hmmer
	${INSTALL_MAN} ${WRKSRC}/Userguide/Userguide.ps ${PREFIX}/share/doc/hmmer
.endif
	@ ${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
