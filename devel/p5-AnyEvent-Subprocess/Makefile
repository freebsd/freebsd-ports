PORTNAME=	AnyEvent-Subprocess
PORTVERSION=	1.102912
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Flexible, OO, asynchronous process spawning and management

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-AnyEvent>=5.2:devel/p5-AnyEvent \
		p5-EV>=4.0:devel/p5-EV \
		p5-Event-Join>=0.05:devel/p5-Event-Join \
		p5-IO-Tty>=0:devel/p5-IO-Tty \
		p5-JSON>=2:converters/p5-JSON \
		p5-Moose>=1.15:devel/p5-Moose \
		p5-MooseX-Clone>=0:devel/p5-MooseX-Clone \
		p5-MooseX-Role-Parameterized>=0:devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-StrictConstructor>=0:devel/p5-MooseX-StrictConstructor \
		p5-MooseX-Types>=0.19:devel/p5-MooseX-Types \
		p5-MooseX-Types-Signal>=0:devel/p5-MooseX-Types-Signal \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean \
		p5-namespace-clean>0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-Test-Exception>0:devel/p5-Test-Exception

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
