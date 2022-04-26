PORTNAME=	MooX-late
PORTVERSION=	0.100
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to easily translate Moose code to Moo

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moo>=2:devel/p5-Moo \
		p5-Sub-HandlesVia>=0.013:devel/p5-Sub-HandlesVia \
		p5-Type-Tiny>=1.000001:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Test-Fatal>=0.010:devel/p5-Test-Fatal \
		p5-Test-Requires>=0.06:devel/p5-Test-Requires \

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
