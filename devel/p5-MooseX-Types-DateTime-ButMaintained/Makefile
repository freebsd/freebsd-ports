PORTNAME=	MooseX-Types-DateTime-ButMaintained
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	DateTime related constraints and coercions for Moose

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime>=0.43:devel/p5-DateTime \
		p5-DateTime-Locale>=0.40:devel/p5-DateTime-Locale \
		p5-DateTime-TimeZone>=0.96:devel/p5-DateTime-TimeZone \
		p5-Moose>=0.41:devel/p5-Moose \
		p5-MooseX-Types>=0.04:devel/p5-MooseX-Types \
		p5-Olson-Abbreviations>=0.03:devel/p5-Olson-Abbreviations \
		p5-namespace-clean>=0.08:devel/p5-namespace-clean
TEST_DEPENDS=	p5-Test-Exception>=0.27:devel/p5-Test-Exception

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
