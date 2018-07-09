# $FreeBSD$

PORTNAME=	POEx-Types
PORTVERSION=	1.100910
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NPEREZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to provide MooseX::Types types for modern POE

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-MooseX-Types>0:devel/p5-MooseX-Types \
	p5-MooseX-Types-Structured>0:devel/p5-MooseX-Types-Structured \
	p5-POE>0:devel/p5-POE
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
