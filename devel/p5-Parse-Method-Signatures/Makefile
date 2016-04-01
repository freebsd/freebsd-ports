# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Parse-Method-Signatures
PORTVERSION=	1.003016
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl6 like method signature parser

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Load>=0.19:devel/p5-Class-Load \
		p5-List-MoreUtils>=0.20:lang/p5-List-MoreUtils \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Traits>=0.06:devel/p5-MooseX-Traits \
		p5-MooseX-Types>=0.17:devel/p5-MooseX-Types \
		p5-MooseX-Types-Structured>=0:devel/p5-MooseX-Types-Structured \
		p5-PPI>=1.203:textproc/p5-PPI \
		p5-namespace-clean>=0.10:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-aliased>=0:devel/p5-aliased

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
