PORTNAME=	AnyMQ
PORTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Non-blocking message queue system based on AnyEvent

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Any-Moose>=0:devel/p5-Any-Moose \
		p5-AnyEvent>=0,1:devel/p5-AnyEvent \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-MouseX-NativeTraits>=0:devel/p5-MouseX-NativeTraits \
		p5-MouseX-Traits>=0:devel/p5-MouseX-Traits
TEST_DEPENDS=	p5-Test-Memory-Cycle>=0:devel/p5-Test-Memory-Cycle \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
