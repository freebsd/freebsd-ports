PORTNAME=	MooseX-ClassAttribute
PORTVERSION=	0.29
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/MooseX CPAN
MASTER_SITE_SUBDIR=	CPAN:DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Declare class attributes Moose-style

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moose>=2:devel/p5-Moose \
		p5-namespace-autoclean>=0.11:devel/p5-namespace-autoclean \
		p5-namespace-clean>=0.20:devel/p5-namespace-clean
TEST_DEPENDS=	p5-MooseX-Role-Parameterized>=0:devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-Role-Strict>=0:devel/p5-MooseX-Role-Strict \
		p5-Test-Requires>=0.05:devel/p5-Test-Requires \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
