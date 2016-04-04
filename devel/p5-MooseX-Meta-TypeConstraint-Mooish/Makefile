# $FreeBSD$

PORTNAME=	MooseX-Meta-TypeConstraint-Mooish
PORTVERSION=	0.001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Translate Moo-style constraints to Moose-style

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-namespace-autoclean>=0.24:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-CheckDeps>=0.010:devel/p5-Test-CheckDeps \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Moose-More>=0.028:devel/p5-Test-Moose-More \
		p5-aliased>=0:devel/p5-aliased

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
