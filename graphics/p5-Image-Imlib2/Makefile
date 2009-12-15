# New ports collection makefile for:	p5-Image-Imlib2
# Date created:				September 11th, 2003
# Whom:	      				Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Imlib2
PORTVERSION=	2.03
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the Imlib2 image library

BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_MODBUILD=	yes
USE_EFL=	imlib2

MAN3=		Image::Imlib2.3

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES
EXAMPLES=	examples/benchmark.pl examples/benchmark.txt examples/maeda.pl

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
