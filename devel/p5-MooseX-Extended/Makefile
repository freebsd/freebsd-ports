PORTNAME=	MooseX-Extended
PORTVERSION=	0.35
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extend Moose with safe defaults and useful features
WWW=		https://metacpan.org/dist/MooseX-Extended

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-B-Hooks-AtRuntime>=0:devel/p5-B-Hooks-AtRuntime \
		p5-Data-Printer>=0:devel/p5-Data-Printer \
		p5-Import-Into>=0:devel/p5-Import-Into \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Role-WarnOnConflict>=0:devel/p5-MooseX-Role-WarnOnConflict \
		p5-MooseX-StrictConstructor>=0:devel/p5-MooseX-StrictConstructor \
		p5-Ref-Util>=0:devel/p5-Ref-Util \
		p5-Type-Tiny>=1.012004:devel/p5-Type-Tiny \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean \
		p5-true>=1.0.2:devel/p5-true
TEST_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-Test-Most>=0:devel/p5-Test-Most

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
