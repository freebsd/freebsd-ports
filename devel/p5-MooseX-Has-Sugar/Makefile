PORTNAME=	MooseX-Has-Sugar
PORTVERSION=	1.000006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sugar Syntax for moose has fields

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Sub-Exporter-Progressive>=0:devel/p5-Sub-Exporter-Progressive
TEST_DEPENDS=	p5-MooseX-Types>=0.44:devel/p5-MooseX-Types \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-namespace-clean>=0:devel/p5-namespace-clean

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
