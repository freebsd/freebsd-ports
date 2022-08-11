PORTNAME=	Bread-Board
PORTVERSION=	0.37
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:YANICK
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Solderless way to wire up your application components

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moose>=2.1200:devel/p5-Moose \
		p5-MooseX-Clone>=0.05:devel/p5-MooseX-Clone \
		p5-MooseX-Params-Validate>=0.14:devel/p5-MooseX-Params-Validate \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-Form-Sensible>=0:devel/p5-Form-Sensible \
		p5-Log-Dispatch>=0:devel/p5-Log-Dispatch \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
