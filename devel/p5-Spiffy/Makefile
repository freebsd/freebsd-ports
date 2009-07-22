# New ports collection makefile for:	Spiffy
# Date created:		15 Jul 2004
# Whom:			Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Spiffy
PORTVERSION=	0.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IN/INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Spiffy Perl Interface Framework For You

PERL_CONFIGURE=	yes

MAN3=		Spiffy.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
