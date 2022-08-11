PORTNAME=	Config-MVP
PORTVERSION=	2.200012
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Multivalue-property package-oriented configuration

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Load>=0.17:devel/p5-Class-Load \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-Moose>=0.91:devel/p5-Moose \
		p5-MooseX-OneArgNew>=0:devel/p5-MooseX-OneArgNew \
		p5-Params-Util>=0:devel/p5-Params-Util \
		p5-Role-HasMessage>=0:devel/p5-Role-HasMessage \
		p5-Role-Identifiable>=0:devel/p5-Role-Identifiable \
		p5-Throwable>=0:devel/p5-Throwable \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
