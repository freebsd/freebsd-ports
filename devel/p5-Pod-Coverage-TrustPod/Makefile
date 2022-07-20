PORTNAME=	Pod-Coverage-TrustPod
PORTVERSION=	0.100005
CATEGORIES=	devel textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Declare trusted symbol names in POD

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Pod-Coverage>=0:devel/p5-Pod-Coverage \
		p5-Pod-Eventual>=0:textproc/p5-Pod-Eventual
TEST_DEPENDS=	p5-Test-Pod>=1.41:devel/p5-Test-Pod

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
