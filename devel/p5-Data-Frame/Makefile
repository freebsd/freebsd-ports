PORTNAME=	Data-Frame
PORTVERSION=	0.006004
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data frame implementation
WWW=		https://metacpan.org/dist/Data-Frame

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Method-Modifiers>=0:devel/p5-Class-Method-Modifiers \
		p5-Devel-OverloadInfo>=0.005:devel/p5-Devel-OverloadInfo \
		p5-Eval-Quosure>=0.001001:devel/p5-Eval-Quosure \
		p5-Exporter-Tiny>=0:devel/p5-Exporter-Tiny \
		p5-Feature-Compat-Try>=0:devel/p5-Feature-Compat-Try \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-Function-Parameters>=2.001003:devel/p5-Function-Parameters \
		p5-Hash-Ordered>=0:devel/p5-Hash-Ordered \
		p5-Import-Into>=0:devel/p5-Import-Into \
		p5-List-AllUtils>=0.19:devel/p5-List-AllUtils \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=2.003004:devel/p5-Moo \
		p5-MooX-Traits>=0:devel/p5-MooX-Traits \
		p5-PDL>=2.019:math/p5-PDL \
		p5-PDL-DateTime>=0:math/p5-PDL-DateTime \
		p5-Package-Stash>=0:devel/p5-Package-Stash \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Ref-Util>=0.204:devel/p5-Ref-Util \
		p5-Role-Tiny>=0:devel/p5-Role-Tiny \
		p5-Safe-Isa>=1.000009:devel/p5-Safe-Isa \
		p5-Sereal-Encoder>=4.005:converters/p5-Sereal-Encoder \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple \
		p5-Text-CSV>=0:textproc/p5-Text-CSV \
		p5-Text-Table-Tiny>=0:textproc/p5-Text-Table-Tiny \
		p5-Type-Tiny>=1.004004:devel/p5-Type-Tiny \
		p5-Types-PDL>=0:devel/p5-Types-PDL \
		p5-autobox>=0:devel/p5-autobox \
		p5-boolean>=0:devel/p5-boolean \
		p5-failures>=0:devel/p5-failures \
		p5-namespace-autoclean>=0.28:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-Test-File-ShareDir>=0:devel/p5-Test-File-ShareDir \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple \
		p5-Test2-Tools-PDL>=0:devel/p5-Test2-Tools-PDL

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
