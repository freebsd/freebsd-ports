PORTNAME=	MooseX-Params-Validate
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extension of Params::Validate for using Moose types

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Devel-Caller>=0:devel/p5-Devel-Caller \
		p5-Moose>=0.58:devel/p5-Moose \
		p5-Params-Validate>=0.88:devel/p5-Params-Validate \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
