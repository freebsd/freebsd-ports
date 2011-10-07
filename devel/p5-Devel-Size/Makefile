# New ports collection makefile for:	Devel-Size
# Date created:	   16 Octobre 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Devel-Size
PORTVERSION=	0.77
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for finding the memory usage of Perl variables

LICENSE_COMB=	dual
LICENSES=	ART10 GPLv1

PERL_CONFIGURE=	yes

MAN3=		Devel::Size.3

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
