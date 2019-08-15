# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Specio
PORTVERSION=	0.44
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Type constraints and coercions for Perl

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Devel-StackTrace>=0:devel/p5-Devel-StackTrace \
		p5-Eval-Closure>=0:devel/p5-Eval-Closure \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Role-Tiny>=1.003003:devel/p5-Role-Tiny \
		p5-Sub-Quote>=0:devel/p5-Sub-Quote \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Needs>=0:devel/p5-Test-Needs \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
