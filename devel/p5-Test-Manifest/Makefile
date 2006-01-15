# New ports collection makefile for:	p5-Test-Manifest
# Date created:				01 Nov 2003
# Whom:	      				Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Manifest
PORTVERSION=	1.14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to interact with a t/test_manifest file

BUILD_DEPENDS=	${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	YES

MAN3=		Test::Manifest.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e '$$_="" if m{5.006}' ${WRKSRC}/Makefile.PL ${WRKSRC}/lib/Manifest.pm
	${PERL} -pi -e 's/(my\( )?\$$fh( \))?/FH/' ${WRKSRC}/lib/Manifest.pm
.endif

.include <bsd.port.post.mk>
