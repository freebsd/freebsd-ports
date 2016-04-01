# $FreeBSD$

PORTNAME=	MooseX-Types-DateTime-MySQL
PORTVERSION=	0.003
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	MySQL datetime type constraints and coercions

RUN_DEPENDS=	p5-DateTime>=0.03:devel/p5-DateTime \
		p5-DateTime-Format-Duration>=1.03:devel/p5-DateTime-Format-Duration \
		p5-DateTime-Format-MySQL>=0:devel/p5-DateTime-Format-MySQL \
		p5-Moose>=0.79:devel/p5-Moose \
		p5-MooseX-Types-DateTime>=0.03:devel/p5-MooseX-Types-DateTime \
		p5-namespace-clean>=0.05:devel/p5-namespace-clean

BUILD_DEPENDS:=	${RUN_DEPENDS}
#TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
#		p5-Test-Simple>=0.88:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
