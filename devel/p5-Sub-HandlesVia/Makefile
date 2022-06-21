# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	Sub-HandlesVia
PORTVERSION=	0.025
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
		p5-Class-Tiny>=0:devel/p5-Class-Tiny \
		p5-Exporter-Tiny>=0:devel/p5-Exporter-Tiny \
		p5-Role-Tiny>=0:devel/p5-Role-Tiny \
		p5-Scope-Guard>=0:devel/p5-Scope-Guard \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>

