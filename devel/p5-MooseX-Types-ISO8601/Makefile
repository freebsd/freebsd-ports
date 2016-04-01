# $FreeBSD$

PORTNAME=	MooseX-Types-ISO8601
PORTVERSION=	0.18
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	ISO8601 date and duration string type constraints and coercions

RUN_DEPENDS=	p5-aliased>=0:devel/p5-aliased \
		p5-DateTime>=0.03:devel/p5-DateTime \
		p5-DateTime-Format-Duration>=1.03:devel/p5-DateTime-Format-Duration \
		p5-DateTime-Format-ISO8601>=0:devel/p5-DateTime-Format-ISO8601 \
		p5-Moose>=0.79:devel/p5-Moose \
		p5-MooseX-Types-DateTime>=0.03:devel/p5-MooseX-Types-DateTime \
		p5-MooseX-Types-DateTime-MySQL>=0:devel/p5-MooseX-Types-DateTime-MySQL \
		p5-namespace-clean>=0.05:devel/p5-namespace-clean \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Simple>=0.88:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
