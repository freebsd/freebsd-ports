# New ports collection makefile for:	tRNAscan-SE
# Date created:				15 Jan 2002
# Whom:					chuynh@biolateral.com.au
#
# $FreeBSD$
#

PORTNAME=	tRNAscan-SE
PORTVERSION=	1.21
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.genetics.wustl.edu/pub/eddy/software/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	chuynh@biolateral.com.au
COMMENT=	An improved tool for transfer RNA detection

MAN1=		tRNAscan-SE.1

USE_PERL5=	yes

#
# have to install before testing as path to data files is hardcoded
#
post-install:
		@ cd ${WRKSRC} && $(MAKE) testrun
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Manual.ps ${DOCSDIR}
.endif

.include <bsd.port.mk>
