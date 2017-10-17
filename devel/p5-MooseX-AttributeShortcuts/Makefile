# $FreeBSD$

PORTNAME=	MooseX-AttributeShortcuts
PORTVERSION=	0.035
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Shorthand for common attribute options

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Moose>=1.14:devel/p5-Moose \
		p5-MooseX-Meta-TypeConstraint-Mooish>=0:devel/p5-MooseX-Meta-TypeConstraint-Mooish \
		p5-MooseX-Role-Parameterized>=0:devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-MooseX-Types-Common>=0:devel/p5-MooseX-Types-Common \
		p5-MooseX-Util>=0:devel/p5-MooseX-Util \
		p5-aliased>=0:devel/p5-aliased \
		p5-namespace-autoclean>=0.24:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-MooseX-Types-Path-Class>=0:devel/p5-MooseX-Types-Path-Class \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Test-CheckDeps>=0.010:devel/p5-Test-CheckDeps \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Moose-More>=0.049:devel/p5-Test-Moose-More \
		p5-Test-Requires>=0:devel/p5-Test-Requires

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
