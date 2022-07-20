PORTNAME=	Sub-HandlesVia
PORTVERSION=	0.032
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Alternative handles_via implementation

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Method-Modifiers>=0:devel/p5-Class-Method-Modifiers \
		p5-Exporter-Tiny>=0:devel/p5-Exporter-Tiny \
		p5-Role-Hooks>=0.008:devel/p5-Role-Hooks \
		p5-Role-Tiny>=0:devel/p5-Role-Tiny \
		p5-Type-Tiny>=1.004000:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
