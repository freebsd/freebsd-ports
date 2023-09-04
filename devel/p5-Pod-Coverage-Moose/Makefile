PORTNAME=	Pod-Coverage-Moose
PORTVERSION=	0.08
CATEGORIES=	devel textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pod::Coverage extension for Moose
WWW=		https://metacpan.org/release/Pod-Coverage-Moose

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moose>=2.1300:devel/p5-Moose \
		p5-Pod-Coverage>=0:devel/p5-Pod-Coverage \
		p5-namespace-autoclean>=0.08:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-Test-Needs>=0:devel/p5-Test-Needs

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
