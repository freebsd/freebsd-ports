# New ports collection makefile for:	p5-Devel-PPPort
# Date created:				8 Aug 2004
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	Devel-PPPort
DISTVERSION=	3.19_03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MHX
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl/Pollution/Portability

LICENSE_COMB=	dual
LICENSE=	ART20 GPLv1

PERL_CONFIGURE=	yes

MAN3=		Devel::PPPort.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README HACKERS TODO

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
