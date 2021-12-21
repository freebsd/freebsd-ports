# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>

PORTNAME=	MooseX-Types
PORTVERSION=	0.50
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Organise your Moose types in libraries

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Carp-Clan>=6.00:devel/p5-Carp-Clan \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moose>=1.06:devel/p5-Moose \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Sub-Exporter-ForMethods>=0.100052:devel/p5-Sub-Exporter-ForMethods \
		p5-Sub-Install>=0:devel/p5-Sub-Install \
		p5-Sub-Name>=0,1:devel/p5-Sub-Name \
		p5-namespace-autoclean>=0.08:devel/p5-namespace-autoclean \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
