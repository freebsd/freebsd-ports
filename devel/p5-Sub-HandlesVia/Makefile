PORTNAME=	Sub-HandlesVia
PORTVERSION=	0.053005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Alternative handles_via implementation
WWW=		https://metacpan.org/dist/Sub-HandlesVia

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Method-Modifiers>=0:devel/p5-Class-Method-Modifiers \
		p5-Exporter-Tiny>=0:devel/p5-Exporter-Tiny \
		p5-Role-Hooks>=0.008:devel/p5-Role-Hooks \
		p5-Role-Tiny>=0:devel/p5-Role-Tiny \
		p5-Type-Tiny>=1.004000:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Object-Pad>=0.70:devel/p5-Object-Pad \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	RECOMMENDED
OPTIONS_DEFAULT=RECOMMENDED
RECOMMENDED_DESC=	Recommended dependencies by upstream

RECOMMENDED_BUILD_DEPENDS=	p5-Sub-HandlesVia-XS>=0.002000:devel/p5-Sub-HandlesVia-XS
RECOMMENDED_RUN_DEPENDS=p5-Sub-HandlesVia-XS>=0.002000:devel/p5-Sub-HandlesVia-XS

.include <bsd.port.mk>
