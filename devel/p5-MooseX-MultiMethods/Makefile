# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-MultiMethods
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Multi Method Dispatch based on Moose type constraints

RUN_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-aliased>0:devel/p5-aliased \
		p5-namespace-autoclean>0:devel/p5-namespace-autoclean \
		p5-Devel-Declare>=0.004000:devel/p5-Devel-Declare \
		p5-MooseX-Types-VariantTable>=0.03:devel/p5-MooseX-Types-VariantTable \
		p5-MooseX-Method-Signatures>=0.29:devel/p5-MooseX-Method-Signatures \
		p5-MooseX-Types>0:devel/p5-MooseX-Types
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
