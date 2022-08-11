PORTNAME=	Data-Stream-Bulk
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	N at a time iteration API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moose>=0.90:devel/p5-Moose \
		p5-Path-Class>0:devel/p5-Path-Class \
		p5-Sub-Exporter>0:devel/p5-Sub-Exporter \
		p5-namespace-clean>0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-Test-Requires>0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
